#include "dropdown-value.h"

namespace cm {
namespace data {

DropDownValue::DropDownValue(QObject* parent, int _key, const QString& _description)
		: QObject(parent)
{
	key = _key;
	description = _description;
}

DropDownValue::~DropDownValue()
{
}

}}
