#include "string-decorator-tests.h"

#include <QSignalSpy>

#include <data/entity.h>

namespace cm {
namespace data { // Instance

static StringDecoratorTests instance;

StringDecoratorTests::StringDecoratorTests()
	: TestSuite( "StringDecoratorTests" )
{
}

}

namespace data { // Tests

void StringDecoratorTests::constructor_givenNoParameters_setsDefaultProperties()
{
	StringDecorator decorator;

	QCOMPARE(decorator.parentEntity(), nullptr);
	QCOMPARE(decorator.key(), QString("SomeItemKey"));
	QCOMPARE(decorator.label(), QString(""));
	QCOMPARE(decorator.value(), QString(""));
}

void StringDecoratorTests::constructor_givenParameters_setsProperties()
{
	Entity parentEntity;
	StringDecorator decorator(&parentEntity, "Test Key", "Test Label", "Test Value");

	QCOMPARE(decorator.parentEntity(), &parentEntity);
	QCOMPARE(decorator.key(), QString("Test Key"));
	QCOMPARE(decorator.label(), QString("Test Label"));
	QCOMPARE(decorator.value(), QString("Test Value"));
}

void StringDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal()
{
	StringDecorator decorator;
	QSignalSpy valueChangedSpy(&decorator, &StringDecorator::valueChanged);

	QCOMPARE(decorator.value(), QString(""));

	decorator.setValue("New Value");

	QCOMPARE(decorator.value(), QString("New Value"));
	QCOMPARE(valueChangedSpy.count(), 1);
}

void StringDecoratorTests::setValue_givenSameValue_takesNoAction()
{
	Entity parentEntity;
	StringDecorator decorator(&parentEntity, "Test Key", "Test Label", "Test Value");
	QSignalSpy valueChangedSpy(&decorator, &StringDecorator::valueChanged);

	QCOMPARE(decorator.value(), QString("Test Value"));

	decorator.setValue("Test Value");

	QCOMPARE(decorator.value(), QString("Test Value"));
	QCOMPARE(valueChangedSpy.count(), 0);
}

void StringDecoratorTests::jsonValue_whenDefaultValue_returnsJson()
{
	StringDecorator decorator;

	QCOMPARE(decorator.jsonValue(), QJsonValue(""));
}

void StringDecoratorTests::jsonValue_whenValueSet_returnsJson()
{
	StringDecorator decorator;
	decorator.setValue("Test Value");

	QCOMPARE(decorator.jsonValue(), QJsonValue("Test Value"));
}

void StringDecoratorTests::update_whenPresentInJson_updatesValue()
{
	Entity parentEntity;
	StringDecorator decorator(&parentEntity, "Test Key", "Test Label", "Test Value");
	QSignalSpy valueChangedSpy(&decorator, &StringDecorator::valueChanged);

	QCOMPARE(decorator.value(), QString("Test Value"));

	QJsonObject jsonObject;
	jsonObject.insert("Key 1", "Value 1");
	jsonObject.insert("Test Key", "New Value");
	jsonObject.insert("Key 3", 3);

	decorator.update(jsonObject);

	QCOMPARE(decorator.value(), QString("New Value"));
	QCOMPARE(valueChangedSpy.count(), 1);
}

void StringDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault()
{
	Entity parentEntity;
	StringDecorator decorator(&parentEntity, "Test Key", "Test Label", "Test Value");
	QSignalSpy valueChangedSpy(&decorator, &StringDecorator::valueChanged);

	QCOMPARE(decorator.value(), QString("Test Value"));

	QJsonObject jsonObject;
	jsonObject.insert("Key 1", "Value 1");
	jsonObject.insert("Key 2", "New Value");
	jsonObject.insert("Key 3", 3);

	decorator.update(jsonObject);

	QCOMPARE(decorator.value(), QString(""));
	QCOMPARE(valueChangedSpy.count(), 1);
}

}}
