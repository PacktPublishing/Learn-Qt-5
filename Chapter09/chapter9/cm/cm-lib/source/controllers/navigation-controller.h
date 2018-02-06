#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>

#include <cm-lib_global.h>
#include <models/client.h>
#include <controllers/i-navigation-controller.h>

namespace cm {
namespace controllers {

class CMLIBSHARED_EXPORT NavigationController : public INavigationController
{
	Q_OBJECT

public:
	explicit NavigationController(QObject* parent = nullptr) : INavigationController(parent){}

};

}}

#endif
