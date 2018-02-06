#ifndef ENUMERATORDECORATORTESTS_H
#define ENUMERATORDECORATORTESTS_H

#include <QtTest>

#include <data/enumerator-decorator.h>

#include <test-suite.h>

namespace cm {
namespace data {

class EnumeratorDecoratorTests : public TestSuite
{
	Q_OBJECT

public:
	EnumeratorDecoratorTests();

private slots:
	void constructor_givenNoParameters_setsDefaultProperties();
	void constructor_givenParameters_setsProperties();

	void setValue_givenNewValue_updatesValueAndEmitsSignal();
	void setValue_givenSameValue_takesNoAction();

	void jsonValue_whenDefaultValue_returnsJson();
	void jsonValue_whenValueSet_returnsJson();

	void update_whenPresentInJson_updatesValue();
	void update_whenNotPresentInJson_updatesValueToDefault();

private:
	enum eTestEnum {
		Unknown = 0,
		Value1,
		Value2,
		Value3
	};

	const std::map<int, QString> descriptionMapper{
		{static_cast<int>(eTestEnum::Unknown), ""},
		{static_cast<int>(eTestEnum::Value1), "Value 1"},
		{static_cast<int>(eTestEnum::Value2), "Value 2"},
		{static_cast<int>(eTestEnum::Value3), "Value 3"}
	};
};

}}

#endif
