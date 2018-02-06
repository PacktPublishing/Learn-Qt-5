#ifndef STRINGDECORATORTESTS_H
#define STRINGDECORATORTESTS_H

#include <QtTest>

#include <data/string-decorator.h>

#include <test-suite.h>

namespace cm {
namespace data {

class StringDecoratorTests : public TestSuite
{
	Q_OBJECT

public:
	StringDecoratorTests();

private slots:
	void constructor_givenNoParameters_setsDefaultProperties();
	void constructor_givenParameters_setsProperties();

	void setValue_givenNewValue_updatesValueAndEmitsSignal();
	void setValue_givenSameValue_takesNoAction();

	void jsonValue_whenDefaultValue_returnsJson();
	void jsonValue_whenValueSet_returnsJson();

	void update_whenPresentInJson_updatesValue();
	void update_whenNotPresentInJson_updatesValueToDefault();
};

}}

#endif
