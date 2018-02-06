#include "datetime-decorator-tests.h"

#include <QSignalSpy>

#include <data/entity.h>

namespace cm {
namespace data { // Instance

static DateTimeDecoratorTests instance;

DateTimeDecoratorTests::DateTimeDecoratorTests()
	: TestSuite( "DateTimeDecoratorTests" )
{
}

}

namespace data { // Tests

void DateTimeDecoratorTests::constructor_givenNoParameters_setsDefaultProperties()
{
	DateTimeDecorator decorator;

	QCOMPARE(decorator.parentEntity(), nullptr);
	QCOMPARE(decorator.key(), QString("SomeItemKey"));
	QCOMPARE(decorator.label(), QString(""));
	QCOMPARE(decorator.value(), QDateTime());
}

void DateTimeDecoratorTests::constructor_givenParameters_setsProperties()
{
	Entity parentEntity;
	DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", testDate);

	QCOMPARE(decorator.parentEntity(), &parentEntity);
	QCOMPARE(decorator.key(), QString("Test Key"));
	QCOMPARE(decorator.label(), QString("Test Label"));
	QCOMPARE(decorator.value(), testDate);
}

void DateTimeDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal()
{
	DateTimeDecorator decorator;
	QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

	QCOMPARE(decorator.value(), QDateTime());

	decorator.setValue(testDate);

	QCOMPARE(decorator.value(), testDate);
	QCOMPARE(valueChangedSpy.count(), 1);
}

void DateTimeDecoratorTests::setValue_givenSameValue_takesNoAction()
{
	Entity parentEntity;
	DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", testDate);
	QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

	QCOMPARE(decorator.value(), testDate);

	decorator.setValue(testDate);

	QCOMPARE(decorator.value(), testDate);
	QCOMPARE(valueChangedSpy.count(), 0);
}

void DateTimeDecoratorTests::jsonValue_whenDefaultValue_returnsJson()
{
	DateTimeDecorator decorator;

	QCOMPARE(decorator.jsonValue(), QJsonValue(QDateTime().toString(Qt::ISODate)));
}

void DateTimeDecoratorTests::jsonValue_whenValueSet_returnsJson()
{
	DateTimeDecorator decorator;
	decorator.setValue(testDate);

	QCOMPARE(decorator.jsonValue(), QJsonValue(testDate.toString(Qt::ISODate)));
}

void DateTimeDecoratorTests::update_whenPresentInJson_updatesValue()
{
	Entity parentEntity;
	DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", testDate);
	QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

	QCOMPARE(decorator.value(), testDate);

	QJsonObject jsonObject;
	jsonObject.insert("Key 1", "Value 1");
	jsonObject.insert("Test Key", QDateTime(QDate(2016, 4, 18), QTime(10, 37, 14)).toString(Qt::ISODate));
	jsonObject.insert("Key 3", 3);

	decorator.update(jsonObject);

	QCOMPARE(decorator.value(), QDateTime(QDate(2016, 4, 18), QTime(10, 37, 14)));
	QCOMPARE(valueChangedSpy.count(), 1);
}

void DateTimeDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault()
{
	Entity parentEntity;
	DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", testDate);
	QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

	QCOMPARE(decorator.value(), testDate);

	QJsonObject jsonObject;
	jsonObject.insert("Key 1", "Value 1");
	jsonObject.insert("Key 2", QDateTime(QDate(2016, 4, 18), QTime(10, 37, 14)).toString(Qt::ISODate));
	jsonObject.insert("Key 3", 3);

	decorator.update(jsonObject);

	QCOMPARE(decorator.value(), QDateTime());
	QCOMPARE(valueChangedSpy.count(), 1);
}

void DateTimeDecoratorTests::toIso8601String_whenDefaultValue_returnsString()
{
	DateTimeDecorator decorator;

	QCOMPARE(decorator.toIso8601String(), QString(""));
}

void DateTimeDecoratorTests::toIso8601String_whenValueSet_returnsString()
{
	DateTimeDecorator decorator;
	decorator.setValue(testDate);

	QCOMPARE(decorator.toIso8601String(), QString("2017-08-19T16:40:32"));
}

void DateTimeDecoratorTests::toPrettyDateString_whenDefaultValue_returnsString()
{
	DateTimeDecorator decorator;

	QCOMPARE(decorator.toPrettyDateString(), QString("Not set"));
}

void DateTimeDecoratorTests::toPrettyDateString_whenValueSet_returnsString()
{
	DateTimeDecorator decorator;
	decorator.setValue(testDate);

	QCOMPARE(decorator.toPrettyDateString(), QString("19 Aug 2017"));
}

void DateTimeDecoratorTests::toPrettyTimeString_whenDefaultValue_returnsString()
{
	DateTimeDecorator decorator;

	QCOMPARE(decorator.toPrettyTimeString(), QString("Not set"));
}

void DateTimeDecoratorTests::toPrettyTimeString_whenValueSet_returnsString()
{
	DateTimeDecorator decorator;
	decorator.setValue(testDate);

	QCOMPARE(decorator.toPrettyTimeString(), QString("04:40 pm"));
}

void DateTimeDecoratorTests::toPrettyString_whenDefaultValue_returnsString()
{
	DateTimeDecorator decorator;

	QCOMPARE(decorator.toPrettyString(), QString("Not set"));
}

void DateTimeDecoratorTests::toPrettyString_whenValueSet_returnsString()
{
	DateTimeDecorator decorator;
	decorator.setValue(testDate);

	QCOMPARE(decorator.toPrettyString(), QString("Sat 19 Aug 2017 @ 16:40:32"));
}

}}
