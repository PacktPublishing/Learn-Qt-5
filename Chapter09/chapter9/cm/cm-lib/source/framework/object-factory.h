#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <framework/i-object-factory.h>

namespace cm {
namespace framework {

class CMLIBSHARED_EXPORT ObjectFactory : public IObjectFactory
{
public:
	ObjectFactory();

	models::Client* createClient(QObject* parent) const override;
	models::ClientSearch* createClientSearch(QObject* parent, controllers::IDatabaseController* databaseController) const override;
	controllers::ICommandController* createCommandController(QObject* parent, controllers::IDatabaseController* databaseController, controllers::INavigationController* navigationController, models::Client* newClient, models::ClientSearch* clientSearch, networking::IWebRequest* rssWebRequest) const override;
	controllers::IDatabaseController* createDatabaseController(QObject* parent) const override;
	controllers::INavigationController* createNavigationController(QObject* parent) const override;
	networking::INetworkAccessManager* createNetworkAccessManager(QObject* parent) const override;
	networking::IWebRequest* createWebRequest(QObject* parent, networking::INetworkAccessManager* networkAccessManager, const QUrl& url) const override;
};

}}

#endif
