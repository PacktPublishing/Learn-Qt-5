#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>

#include <cm-lib_global.h>
#include <framework/command.h>
#include <controllers/i-command-controller.h>
#include <controllers/i-database-controller.h>
#include <controllers/navigation-controller.h>
#include <models/client.h>
#include <models/client-search.h>
#include <networking/i-web-request.h>

namespace cm {
namespace controllers {

class CMLIBSHARED_EXPORT CommandController : public ICommandController
{
	Q_OBJECT
	Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands READ ui_createClientViewContextCommands CONSTANT)
	Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommands READ ui_findClientViewContextCommands CONSTANT)
	Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommands READ ui_editClientViewContextCommands CONSTANT)
	Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_rssViewContextCommands READ ui_rssViewContextCommands CONSTANT)

public:
	explicit CommandController(QObject* _parent = nullptr, IDatabaseController* databaseController = nullptr, controllers::INavigationController* navigationController = nullptr, models::Client* newClient = nullptr, models::ClientSearch* clientSearch = nullptr, networking::IWebRequest* rssWebRequest = nullptr);
	~CommandController();

	QQmlListProperty<framework::Command> ui_createClientViewContextCommands() override;
	QQmlListProperty<framework::Command> ui_findClientViewContextCommands() override;
	QQmlListProperty<framework::Command> ui_editClientViewContextCommands() override;
	QQmlListProperty<framework::Command> ui_rssViewContextCommands() override;

public slots:
	void setSelectedClient(cm::models::Client* client) override;
	void onCreateClientSaveExecuted() override;
	void onFindClientSearchExecuted() override;
	void onEditClientSaveExecuted() override;
	void onEditClientDeleteExecuted() override;
	void onRssRefreshExecuted() override;

private:
	class Implementation;
	QScopedPointer<Implementation> implementation;
};

}}

#endif
