#include "rss-item.h"
#include <QTextStream>
#include <utilities/xml-helper.h>

using namespace cm::utilities;

namespace cm {
namespace rss {
class RssItem::Implementation
{
public:
	Implementation(RssItem* _rssItem)
		: rssItem(_rssItem)
	{
	}

	RssItem* rssItem{nullptr};
	QString description;    // This or Title mandatory.  Either the synopsis or full story.  HTML is allowed.
	QString link;           // Optional. Link to full story.  Populated if Description is only the synopsis.
	QDateTime pubDate;      // Optional. When the item was published. RFC 822 format e.g. Sun, 19 May 2002 15:21:36 GMT.
	QString title;          // This or Description mandatory.

	void update(const QDomNode& domNode)
	{
		for(auto i = 0; i < domNode.childNodes().size(); ++i) {
			QDomNode childNode = domNode.childNodes().at(i);
			if(childNode.nodeName() == "description") {
				description = XmlHelper::toString(childNode);
			}
		}

		QDomElement itemLink = domNode.firstChildElement("link");
		if(!itemLink.isNull()) {
			link = itemLink.text();
		}

		QDomElement itemPubDate = domNode.firstChildElement("pubDate");
		if(!itemPubDate.isNull()) {
			pubDate = QDateTime::fromString(itemPubDate.text(), Qt::RFC2822Date);
		}

		QDomElement itemTitle = domNode.firstChildElement("title");
		if(!itemTitle.isNull()) {
			title = itemTitle.text();
		}
	}
};

RssItem::RssItem(QObject* parent, const QDomNode& domNode)
{
	implementation.reset(new Implementation(this));
	implementation->update(domNode);
}

RssItem::~RssItem()
{
}

const QString& RssItem::description() const
{
	return implementation->description;
}

const QString& RssItem::link() const
{
	return implementation->link;
}

const QDateTime& RssItem::pubDate() const
{
	return implementation->pubDate;
}

const QString& RssItem::title() const
{
	return implementation->title;
}

}}
