#include "master-controller-tests.h"

namespace cm {
namespace controllers { // Instance

static MasterControllerTests instance;

MasterControllerTests::MasterControllerTests()
	: TestSuite( "MasterControllerTests" )
{
}

}

namespace controllers { // Scaffolding

void MasterControllerTests::initTestCase()
{
}

void MasterControllerTests::cleanupTestCase()
{
}

void MasterControllerTests::init()
{
	masterController = new MasterController(this, &mockObjectFactory);
}

void MasterControllerTests::cleanup()
{
	if(masterController != nullptr) {
		masterController->deleteLater();
		masterController = nullptr;
	}
}

}

namespace controllers { // Tests

void MasterControllerTests::welcomeMessage_returnsCorrectMessage()
{
	QCOMPARE( masterController->welcomeMessage(), QString("Welcome to the Client Management system!") );
}

}}
