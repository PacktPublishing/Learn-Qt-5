#include "rss-image.h"

namespace cm {
namespace rss {

class RssImage::Implementation
{
public:
	QString url;    // Mandatory. URL of GIF, JPEG or PNG that represents the channel.
	QString title;  // Mandatory.  Describes the image.
	QString link;   // Mandatory.  URL of the site.
	quint16 width;  // Optional.  Width in pixels.  Max 144, default 88.
	quint16 height; // Optional.  Height in pixels.  Max 400, default 31

	void update(const QDomNode& domNode)
	{
		QDomElement imageUrl = domNode.firstChildElement("url");
		if(!imageUrl.isNull()) {
			url = imageUrl.text();
		}

		QDomElement imageTitle = domNode.firstChildElement("title");
		if(!imageTitle.isNull()) {
			title = imageTitle.text();
		}

		QDomElement imageLink = domNode.firstChildElement("link");
		if(!imageLink.isNull()) {
			link = imageLink.text();
		}

		QDomElement imageWidth = domNode.firstChildElement("width");
		if(!imageWidth.isNull()) {
			width = static_cast<quint16>(imageWidth.text().toShort());
		} else {
			width = 88;
		}

		QDomElement imageHeight = domNode.firstChildElement("height");
		if(!imageHeight.isNull()) {
			height = static_cast<quint16>(imageHeight.text().toShort());
		} else {
			height = 31;
		}
	}
};

RssImage::RssImage(QObject* parent, const QDomNode& domNode)
	: QObject(parent)
{
	implementation.reset(new Implementation());
	implementation->update(domNode);
}

RssImage::~RssImage()
{
}

quint16 RssImage::height() const
{
	return implementation->height;
}

const QString& RssImage::link() const
{
	return implementation->link;
}

const QString& RssImage::title() const
{
	return implementation->title;
}

const QString& RssImage::url() const
{
	return implementation->url;
}

quint16 RssImage::width() const
{
	return implementation->width;
}

}}
