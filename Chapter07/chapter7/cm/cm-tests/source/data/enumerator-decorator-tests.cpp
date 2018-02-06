#include "enumerator-decorator-tests.h"

#include <QSignalSpy>

#include <data/entity.h>

namespace cm {
namespace data { // Instance

static EnumeratorDecoratorTests instance;

EnumeratorDecoratorTests::EnumeratorDecoratorTests()
	: TestSuite( "EnumeratorDecoratorTests" )
{
}

}

namespace data { // Tests

void EnumeratorDecoratorTests::constructor_givenNoParameters_setsDefaultProperties()
{
	EnumeratorDecorator decorator;

	QCOMPARE(decorator.parentEntity(), nullptr);
	QCOMPARE(decorator.key(), QString("SomeItemKey"));
	QCOMPARE(decorator.label(), QString(""));
	QCOMPARE(decorator.value(), 0);
	QCOMPARE(decorator.valueDescription(), QString(""));
}

void EnumeratorDecoratorTests::constructor_givenParameters_setsProperties()
{
	Entity parentEntity;
	EnumeratorDecorator decorator(&parentEntity, "Test Key", "Test Label", static_cast<int>(eTestEnum::Value2), descriptionMapper);

	QCOMPARE(decorator.parentEntity(), &parentEntity);
	QCOMPARE(decorator.key(), QString("Test Key"));
	QCOMPARE(decorator.label(), QString("Test Label"));
	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Value2));
	QCOMPARE(decorator.valueDescription(), QString("Value 2"));
}

void EnumeratorDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal()
{
	Entity parentEntity;
	EnumeratorDecorator decorator(&parentEntity, "Test Key", "Test Label", static_cast<int>(eTestEnum::Unknown), descriptionMapper);
	QSignalSpy valueChangedSpy(&decorator, &EnumeratorDecorator::valueChanged);

	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Unknown));
	QCOMPARE(decorator.valueDescription(), QString(""));

	decorator.setValue(static_cast<int>(eTestEnum::Value2));

	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Value2));
	QCOMPARE(decorator.valueDescription(), QString("Value 2"));
	QCOMPARE(valueChangedSpy.count(), 1);
}

void EnumeratorDecoratorTests::setValue_givenSameValue_takesNoAction()
{
	Entity parentEntity;
	EnumeratorDecorator decorator(&parentEntity, "Test Key", "Test Label", static_cast<int>(eTestEnum::Value2), descriptionMapper);
	QSignalSpy valueChangedSpy(&decorator, &EnumeratorDecorator::valueChanged);

	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Value2));
	QCOMPARE(decorator.valueDescription(), QString("Value 2"));

	decorator.setValue(static_cast<int>(eTestEnum::Value2));

	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Value2));
	QCOMPARE(decorator.valueDescription(), QString("Value 2"));
	QCOMPARE(valueChangedSpy.count(), 0);
}

void EnumeratorDecoratorTests::jsonValue_whenDefaultValue_returnsJson()
{
	EnumeratorDecorator decorator;

	QCOMPARE(decorator.jsonValue(), QJsonValue(static_cast<int>(eTestEnum::Unknown)));
}

void EnumeratorDecoratorTests::jsonValue_whenValueSet_returnsJson()
{
	EnumeratorDecorator decorator;
	decorator.setValue(static_cast<int>(eTestEnum::Value2));

	QCOMPARE(decorator.jsonValue(), QJsonValue(static_cast<int>(eTestEnum::Value2)));
}

void EnumeratorDecoratorTests::update_whenPresentInJson_updatesValue()
{
	Entity parentEntity;
	EnumeratorDecorator decorator(&parentEntity, "Test Key", "Test Label", static_cast<int>(eTestEnum::Value2), descriptionMapper);
	QSignalSpy valueChangedSpy(&decorator, &EnumeratorDecorator::valueChanged);

	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Value2));
	QCOMPARE(decorator.valueDescription(), QString("Value 2"));

	QJsonObject jsonObject;
	jsonObject.insert("Key 1", "Value 1");
	jsonObject.insert("Test Key", static_cast<int>(eTestEnum::Value3));
	jsonObject.insert("Key 3", 3);

	decorator.update(jsonObject);

	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Value3));
	QCOMPARE(decorator.valueDescription(), QString("Value 3"));
	QCOMPARE(valueChangedSpy.count(), 1);
}

void EnumeratorDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault()
{
	Entity parentEntity;
	EnumeratorDecorator decorator(&parentEntity, "Test Key", "Test Label", static_cast<int>(eTestEnum::Value2), descriptionMapper);
	QSignalSpy valueChangedSpy(&decorator, &EnumeratorDecorator::valueChanged);

	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Value2));
	QCOMPARE(decorator.valueDescription(), QString("Value 2"));

	QJsonObject jsonObject;
	jsonObject.insert("Key 1", "Value 1");
	jsonObject.insert("Key 2", 123);
	jsonObject.insert("Key 3", 3);

	decorator.update(jsonObject);

	QCOMPARE(decorator.value(), static_cast<int>(eTestEnum::Unknown));
	QCOMPARE(decorator.valueDescription(), QString(""));
	QCOMPARE(valueChangedSpy.count(), 1);
}

}}
