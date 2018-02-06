#ifndef IWEBREQUEST_H
#define IWEBREQUEST_H

#include <QObject>
#include <QUrl>

namespace cm {
namespace networking {

class IWebRequest : public QObject
{
	Q_OBJECT

public:
	IWebRequest(QObject* parent) : QObject(parent){}
	virtual ~IWebRequest(){}

	virtual void execute() = 0;
	virtual bool isBusy() const = 0;
	virtual void setUrl(const QUrl& url) = 0;
	virtual QUrl url() const = 0;

signals:
	void error(QString message);
	void isBusyChanged();
	void requestComplete(int statusCode, QByteArray body);
	void urlChanged();
};

}}

#endif
