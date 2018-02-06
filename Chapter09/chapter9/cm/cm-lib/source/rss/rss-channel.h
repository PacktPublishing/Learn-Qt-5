#ifndef RSSCHANNEL_H
#define RSSCHANNEL_H

#include <QDateTime>
#include <QtXml/QDomElement>
#include <QtXml/QDomNode>
#include <QList>
#include <QObject>
#include <QtQml/QQmlListProperty>
#include <QString>

#include <cm-lib_global.h>
#include <rss/rss-image.h>
#include <rss/rss-item.h>

namespace cm {
namespace rss {

class CMLIBSHARED_EXPORT RssChannel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString ui_description READ description CONSTANT)
	Q_PROPERTY(cm::rss::RssImage* ui_image READ image CONSTANT)
	Q_PROPERTY(QQmlListProperty<cm::rss::RssItem> ui_items READ ui_items CONSTANT)
	Q_PROPERTY(QString ui_link READ link CONSTANT)
	Q_PROPERTY(QString ui_title READ title CONSTANT)

public:
	RssChannel(QObject* parent = nullptr, const QDomNode& domNode = QDomNode());
	~RssChannel();

	void addItem(RssItem* item);
	const QString& description() const;
	RssImage* image() const;
	const QList<RssItem*>& items() const;
	const QString& link() const;
	void setImage(RssImage* image);
	const QString& title() const;
	QQmlListProperty<RssItem> ui_items();

	static RssChannel* fromXml(const QByteArray& xmlData, QObject* parent = nullptr);

private:
	class Implementation;
	QScopedPointer<Implementation> implementation;
};

}}

#endif
