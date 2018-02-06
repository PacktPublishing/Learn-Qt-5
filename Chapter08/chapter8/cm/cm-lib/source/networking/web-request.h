#ifndef WEBREQUEST_H
#define WEBREQUEST_H

#include <QList>
#include <QObject>
#include <QSslError>
#include <networking/i-network-access-manager.h>
#include <networking/i-web-request.h>

namespace cm {
namespace networking {

class WebRequest : public QObject, public IWebRequest
{
	Q_OBJECT

public:
	WebRequest(QObject* parent, INetworkAccessManager* networkAccessManager, const QUrl& url);
	WebRequest(QObject* parent = nullptr) = delete;
	~WebRequest();

public:
	void execute() override;
	bool isBusy() const override;
	void setUrl(const QUrl& url) override;
	QUrl url() const override;

signals:
	void error(QString message);
	void isBusyChanged();
	void requestComplete(int statusCode, QByteArray body);
	void urlChanged();

private slots:
	void replyDelegate();
	void sslErrorsDelegate( const QList<QSslError>& _errors );

private:
	class Implementation;
	QScopedPointer<Implementation> implementation;
};

}}

#endif
