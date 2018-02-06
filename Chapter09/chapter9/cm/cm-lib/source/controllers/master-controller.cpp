#include "master-controller.h"

#include <networking/network-access-manager.h>
#include <networking/web-request.h>

using namespace cm::framework;
using namespace cm::models;
using namespace cm::networking;
using namespace cm::rss;

namespace cm {
namespace controllers {

class MasterController::Implementation
{
public:
	Implementation(MasterController* _masterController, IObjectFactory* _objectFactory)
		: masterController(_masterController)
		, objectFactory(_objectFactory)
	{
		databaseController = objectFactory->createDatabaseController(masterController);
		clientSearch = objectFactory->createClientSearch(masterController, databaseController);
		navigationController = objectFactory->createNavigationController(masterController);
		networkAccessManager = objectFactory->createNetworkAccessManager(masterController);
		rssWebRequest = objectFactory->createWebRequest(masterController, networkAccessManager, QUrl("http://feeds.bbci.co.uk/news/rss.xml?edition=uk"));
		QObject::connect(rssWebRequest, &IWebRequest::requestComplete, masterController, &MasterController::onRssReplyReceived);
		newClient = objectFactory->createClient(masterController);
		commandController = objectFactory->createCommandController(masterController, databaseController, navigationController, newClient, clientSearch, rssWebRequest);
	}

	MasterController* masterController{nullptr};
	IObjectFactory* objectFactory{nullptr};
	ICommandController* commandController{nullptr};
	IDatabaseController* databaseController{nullptr};
	INavigationController* navigationController{nullptr};
	Client* newClient{nullptr};
	ClientSearch* clientSearch{nullptr};
	INetworkAccessManager* networkAccessManager{nullptr};
	IWebRequest* rssWebRequest{nullptr};
	RssChannel* rssChannel{nullptr};
	QString welcomeMessage = "Welcome to the Client Management system!";
};

MasterController::MasterController(QObject* parent, IObjectFactory* objectFactory)
	: QObject(parent)
{
	implementation.reset(new Implementation(this, objectFactory));
}

MasterController::~MasterController()
{
}

ICommandController* MasterController::commandController()
{
	return implementation->commandController;
}

IDatabaseController* MasterController::databaseController()
{
	return implementation->databaseController;
}

INavigationController* MasterController::navigationController()
{
	return implementation->navigationController;
}

Client* MasterController::newClient()
{
	return implementation->newClient;
}

ClientSearch* MasterController::clientSearch()
{
	return implementation->clientSearch;
}

RssChannel* MasterController::rssChannel()
{
	return implementation->rssChannel;
}

const QString& MasterController::welcomeMessage() const
{
	return implementation->welcomeMessage;
}

void MasterController::selectClient(Client* client)
{
	implementation->navigationController->goEditClientView(client);
}

void MasterController::onRssReplyReceived(int statusCode, QByteArray body)
{
	qDebug() << "Received RSS request response code " << statusCode << ":";
	qDebug() << body;

	if(implementation->rssChannel) {
		implementation->rssChannel->deleteLater();
		implementation->rssChannel = nullptr;
		emit rssChannelChanged();
	}

	implementation->rssChannel = RssChannel::fromXml(body, this);
	emit rssChannelChanged();
}

}}
