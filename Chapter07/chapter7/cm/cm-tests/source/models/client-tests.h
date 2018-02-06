#ifndef CLIENTTESTS_H
#define CLIENTTESTS_H

#include <QtTest>
#include <QJsonObject>

#include <models/client.h>
#include <test-suite.h>

namespace cm {
namespace models {

class ClientTests : public TestSuite
{
	Q_OBJECT

public:
	ClientTests();

private slots:
	void constructor_givenParent_setsParentAndDefaultProperties();
	void constructor_givenParentAndJsonObject_setsParentAndProperties();
	void toJson_withDefaultProperties_constructsJson();
	void toJson_withSetProperties_constructsJson();
	void update_givenJsonObject_updatesProperties();
	void update_givenEmptyJsonObject_updatesPropertiesToDefaults();
	void id_givenPrimaryKeyWithNoValue_returnsUuid();
	void id_givenPrimaryKeyWithValue_returnsPrimaryKey();

private:
	void verifyBillingAddress(const QJsonObject& jsonObject);
	void verifyDefaultBillingAddress(const QJsonObject& jsonObject);
	void verifyBillingAddress(Address* address);
	void verifyDefaultBillingAddress(Address* address);
	void verifySupplyAddress(const QJsonObject& jsonObject);
	void verifyDefaultSupplyAddress(const QJsonObject& jsonObject);
	void verifySupplyAddress(Address* address);
	void verifyDefaultSupplyAddress(Address* address);
	void verifyAppointments(const QJsonObject& jsonObject);
	void verifyDefaultAppointments(const QJsonObject& jsonObject);
	void verifyAppointments(const QList<Appointment*>& appointments);
	void verifyDefaultAppointments(const QList<Appointment*>& appointments);
	void verifyContacts(const QJsonObject& jsonObject);
	void verifyDefaultContacts(const QJsonObject& jsonObject);
	void verifyContacts(const QList<Contact*>& contacts);
	void verifyDefaultContacts(const QList<Contact*>& contacts);

	QByteArray jsonByteArray = R"(
	{
		"reference": "CM0001",
		"name": "Mr Test Testerson",
		"billingAddress": {
			"building": "Billing Building",
			"city": "Billing City",
			"postcode": "Billing Postcode",
			"street": "Billing Street"
		},
		"appointments": [
		 {"startAt": "2017-08-20T12:45:00", "endAt": "2017-08-20T13:00:00", "notes": "Test appointment 1"},
		 {"startAt": "2017-08-21T10:30:00", "endAt": "2017-08-21T11:30:00", "notes": "Test appointment 2"}
		],
		"contacts": [
			{"contactType": 2, "address":"email@test.com"},
			{"contactType": 1, "address":"012345678"}
		],
		"supplyAddress": {
			"building": "Supply Building",
			"city": "Supply City",
			"postcode": "Supply Postcode",
			"street": "Supply Street"
		}
	})";
};

}}

#endif
