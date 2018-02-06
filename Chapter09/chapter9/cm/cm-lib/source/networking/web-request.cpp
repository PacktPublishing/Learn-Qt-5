#include "web-request.h"

#include <QMap>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace cm {
namespace networking { // Private Implementation

static const QMap<QNetworkReply::NetworkError, QString> networkErrorMapper = {
	{QNetworkReply::ConnectionRefusedError, "The remote server refused the connection (the server is not accepting requests)."},
	{QNetworkReply::RemoteHostClosedError, "The remote server closed the connection prematurely, before the entire reply was received and processed."},
	{QNetworkReply::HostNotFoundError, "The remote host name was not found (invalid hostname)."},
	{QNetworkReply::TimeoutError, "The connection to the remote server timed out."},
	{QNetworkReply::OperationCanceledError, "The operation was canceled via calls to abort() or close() before it was finished."},
	{QNetworkReply::SslHandshakeFailedError, "The SSL/TLS handshake failed and the encrypted channel could not be established. The sslErrors() signal should have been emitted."},
	{QNetworkReply::TemporaryNetworkFailureError, "The connection was broken due to disconnection from the network, however the system has initiated roaming to another access point. The request should be resubmitted and will be processed as soon as the connection is re-established."},
	{QNetworkReply::NetworkSessionFailedError, "The connection was broken due to disconnection from the network or failure to start the network."},
	{QNetworkReply::BackgroundRequestNotAllowedError, "The background request is not currently allowed due to platform policy."},
	{QNetworkReply::ProxyConnectionRefusedError, "The connection to the proxy server was refused (the proxy server is not accepting requests)."},
	{QNetworkReply::ProxyConnectionClosedError, "The proxy server closed the connection prematurely, before the entire reply was received and processed."},
	{QNetworkReply::ProxyNotFoundError, "The proxy host name was not found (invalid proxy hostname)."},
	{QNetworkReply::ProxyTimeoutError, "The connection to the proxy timed out or the proxy did not reply in time to the request sent."},
	{QNetworkReply::ProxyAuthenticationRequiredError, "The proxy requires authentication in order to honour the request but did not accept any credentials offered (if any)."},
	{QNetworkReply::ContentAccessDenied, "The access to the remote content was denied (similar to HTTP error 401)."},
	{QNetworkReply::ContentOperationNotPermittedError, "The operation requested on the remote content is not permitted."},
	{QNetworkReply::ContentNotFoundError, "The remote content was not found at the server (similar to HTTP error 404)."},
	{QNetworkReply::AuthenticationRequiredError, "The remote server requires authentication to serve the content but the credentials provided were not accepted (if any)."},
	{QNetworkReply::ContentReSendError, "The request needed to be sent again, but this failed for example because the upload data could not be read a second time."},
	{QNetworkReply::ContentConflictError, "The request could not be completed due to a conflict with the current state of the resource."},
	{QNetworkReply::ContentGoneError, "The requested resource is no longer available at the server."},
	{QNetworkReply::InternalServerError, "The server encountered an unexpected condition which prevented it from fulfilling the request."},
	{QNetworkReply::OperationNotImplementedError, "The server does not support the functionality required to fulfill the request."},
	{QNetworkReply::ServiceUnavailableError, "The server is unable to handle the request at this time."},
	{QNetworkReply::ProtocolUnknownError, "The Network Access API cannot honor the request because the protocol is not known."},
	{QNetworkReply::ProtocolInvalidOperationError, "The requested operation is invalid for this protocol."},
	{QNetworkReply::UnknownNetworkError, "An unknown network-related error was detected."},
	{QNetworkReply::UnknownProxyError, "An unknown proxy-related error was detected."},
	{QNetworkReply::UnknownContentError, "An unknown error related to the remote content was detected."},
	{QNetworkReply::ProtocolFailure, "A breakdown in protocol was detected (parsing error, invalid or unexpected responses, etc.)."},
	{QNetworkReply::UnknownServerError, "An unknown error related to the server response was detected."}
};

class WebRequest::Implementation
{
public:
	Implementation(WebRequest* _webRequest, INetworkAccessManager* _networkAccessManager, const QUrl& _url)
		: webRequest(_webRequest)
		, networkAccessManager(_networkAccessManager)
		, url(_url)
	{
	}

	WebRequest* webRequest{nullptr};
	INetworkAccessManager* networkAccessManager{nullptr};
	QUrl url {};
	QNetworkReply* reply {nullptr};

public:
	bool isBusy() const
	{
		return isBusy_;
	}

	void setIsBusy(bool value)
	{
		if (value != isBusy_) {
			isBusy_ = value;
			emit webRequest->isBusyChanged();
		}
	}

private:
	bool isBusy_{false};
};
}

namespace networking {  // Structors
WebRequest::WebRequest(QObject* parent, INetworkAccessManager* networkAccessManager, const QUrl& url)
	: IWebRequest(parent)
{
	implementation.reset(new WebRequest::Implementation(this, networkAccessManager, url));
}

WebRequest::~WebRequest()
{
}
}

namespace networking { // Methods
void WebRequest::execute()
{
	if(implementation->isBusy()) {
		return;
	}

	if(!implementation->networkAccessManager->isNetworkAccessible()) {
		emit error("Network not accessible");
		return;
	}

	implementation->setIsBusy(true);
	QNetworkRequest request;
	request.setUrl(implementation->url);
	implementation->reply = implementation->networkAccessManager->get(request);

	if(implementation->reply != nullptr) {
		connect(implementation->reply, &QNetworkReply::finished, this, &WebRequest::replyDelegate);
		connect(implementation->reply, &QNetworkReply::sslErrors, this, &WebRequest::sslErrorsDelegate);
	}
}

bool WebRequest::isBusy() const
{
	return implementation->isBusy();
}

void WebRequest::setUrl(const QUrl& url)
{
	if(url != implementation->url) {
		implementation->url = url;
		emit urlChanged();
	}
}

QUrl WebRequest::url() const
{
	return implementation->url;
}
}

namespace networking { // Private Slots
void WebRequest::replyDelegate()
{
	implementation->setIsBusy(false);

	if (implementation->reply == nullptr) {
		emit error("Unexpected error - reply object is null");
		return;
	}

	disconnect(implementation->reply, &QNetworkReply::finished, this, &WebRequest::replyDelegate);
	disconnect(implementation->reply, &QNetworkReply::sslErrors, this, &WebRequest::sslErrorsDelegate);

	auto statusCode = implementation->reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	auto responseBody = implementation->reply->readAll();
	auto replyStatus = implementation->reply->error();
	implementation->reply->deleteLater();

	if (replyStatus != QNetworkReply::NoError) {
		emit error(networkErrorMapper[implementation->reply->error()]);
	}

	emit requestComplete(statusCode, responseBody);
}

void WebRequest::sslErrorsDelegate(const QList<QSslError>& errors)
{
	QString sslError;
	for (const auto& error : errors) {
		sslError += error.errorString() + "\n";
	}
	emit error(sslError);
}

}}
