#ifndef MOCKOBJECTFACTORY_H
#define MOCKOBJECTFACTORY_H

#include <framework/i-object-factory.h>

namespace cm {
namespace framework {

class MockObjectFactory : public IObjectFactory
{
public:
	MockObjectFactory(){}

	models::Client* createClient(QObject* parent) const override { return nullptr; }
	models::ClientSearch* createClientSearch(QObject* parent, controllers::IDatabaseController* databaseController) const override { return nullptr; }
	controllers::ICommandController* createCommandController(QObject* parent, controllers::IDatabaseController* databaseController, controllers::INavigationController* navigationController, models::Client* newClient, models::ClientSearch* clientSearch, networking::IWebRequest* rssWebRequest) const override { return nullptr; }
	controllers::IDatabaseController* createDatabaseController(QObject* parent) const override { return nullptr; }
	controllers::INavigationController* createNavigationController(QObject* parent) const override { return nullptr; }
	networking::INetworkAccessManager* createNetworkAccessManager(QObject* parent) const override { return nullptr; }
	networking::IWebRequest* createWebRequest(QObject* parent, networking::INetworkAccessManager* networkAccessManager, const QUrl& url) const override { return nullptr; }
};

}}

#endif
