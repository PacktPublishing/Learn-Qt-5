#ifndef ICOMMANDCONTROLLER_H
#define ICOMMANDCONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>

#include <cm-lib_global.h>
#include <framework/command.h>
#include <models/client.h>

namespace cm {
namespace controllers {

class CMLIBSHARED_EXPORT ICommandController : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands READ ui_createClientViewContextCommands CONSTANT)
	Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommands READ ui_editClientViewContextCommands CONSTANT)
	Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommands READ ui_findClientViewContextCommands CONSTANT)
	Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_rssViewContextCommands READ ui_rssViewContextCommands CONSTANT)

public:
	ICommandController(QObject* parent = nullptr) : QObject(parent){}
	virtual ~ICommandController(){}

	virtual QQmlListProperty<framework::Command> ui_createClientViewContextCommands() = 0;
	virtual QQmlListProperty<framework::Command> ui_editClientViewContextCommands() = 0;
	virtual QQmlListProperty<framework::Command> ui_findClientViewContextCommands() = 0;
	virtual QQmlListProperty<framework::Command> ui_rssViewContextCommands() = 0;

public slots:
	virtual void onCreateClientSaveExecuted() = 0;
	virtual void onEditClientDeleteExecuted() = 0;
	virtual void onEditClientSaveExecuted() = 0;
	virtual void onFindClientSearchExecuted() = 0;
	virtual void onRssRefreshExecuted() = 0;
	virtual void setSelectedClient(cm::models::Client* client) = 0;

};

}}

#endif
