#include "rss-channel.h"
#include <QtXml/QDomDocument>

namespace cm {
namespace rss {

class RssChannel::Implementation
{
public:
	QString description;            // Mandatory.  Phrase or sentence describing the channel.
	RssImage* image{nullptr};       // Optional.  Image representing the channel.
	QList<RssItem*> items;          // Optional.  Collection representing stories.
	QString link;                   // Mandatory.  URL to the corresponding HTML website.
	QString title;                  // Mandatory.  THe name of the Channel.

	void update(const QDomNode& domNode)
	{
		QDomElement channelDescription = domNode.firstChildElement("description");
		if(!channelDescription.isNull()) {
			description = channelDescription.text();
		}

		QDomElement channelLink = domNode.firstChildElement("link");
		if(!channelLink.isNull()) {
			link = channelLink.text();
		}

		QDomElement channelTitle = domNode.firstChildElement("title");
		if(!channelTitle.isNull()) {
			title = channelTitle.text();
		}
	}
};

RssChannel::RssChannel(QObject* parent, const QDomNode& domNode)
	: QObject(parent)
{
	implementation.reset(new Implementation());
	implementation->update(domNode);
}

RssChannel::~RssChannel()
{
}

void RssChannel::addItem(RssItem* item)
{
	if(!implementation->items.contains(item)) {
		item->setParent(this);
		implementation->items.push_back(item);
	}
}

const QString&  RssChannel::description() const
{
	return implementation->description;
}

RssImage* RssChannel::image() const
{
	return implementation->image;
}

const QList<RssItem*>&  RssChannel::items() const
{
	return implementation->items;
}

const QString&  RssChannel::link() const
{
	return implementation->link;
}

void RssChannel::setImage(RssImage* image)
{
	if(implementation->image) {
		implementation->image->deleteLater();
		implementation->image = nullptr;
	}

	image->setParent(this);
	implementation->image = image;
}

const QString& RssChannel::title() const
{
	return implementation->title;
}
QQmlListProperty<RssItem> RssChannel::ui_items()
{
	return QQmlListProperty<RssItem>(this, implementation->items);
}

RssChannel* RssChannel::fromXml(const QByteArray& xmlData, QObject* parent)
{
	QDomDocument doc;
	doc.setContent(xmlData);

	auto channelNodes = doc.elementsByTagName("channel");

	// Rss must have 1 channel
	if(channelNodes.size() != 1) return nullptr;

	RssChannel* channel = new RssChannel(parent, channelNodes.at(0));
	auto imageNodes = doc.elementsByTagName("image");
	if(imageNodes.size() > 0) {
		channel->setImage(new RssImage(channel, imageNodes.at(0)));
	}

	auto itemNodes = doc.elementsByTagName("item");
	for (auto i = 0; i < itemNodes.size(); ++i) {
		channel->addItem(new RssItem(channel, itemNodes.item(i)));
	}

	return channel;
}

}}
