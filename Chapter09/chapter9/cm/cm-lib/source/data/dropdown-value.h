#ifndef DROPDOWNVALUE_H
#define DROPDOWNVALUE_H

#include <QObject>
#include <cm-lib_global.h>

namespace cm {
namespace data {

class CMLIBSHARED_EXPORT DropDownValue : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int ui_key MEMBER key CONSTANT )
	Q_PROPERTY(QString ui_description MEMBER description CONSTANT)

public:
	DropDownValue(QObject* parent = nullptr, int key = 0, const QString& description = "");
	~DropDownValue();

public:
	int key{0};
	QString description{""};
};

}}

#endif
