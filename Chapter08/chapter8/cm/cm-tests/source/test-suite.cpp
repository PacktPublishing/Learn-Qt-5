#include "test-suite.h"

#include <QDebug>

namespace cm {

TestSuite::TestSuite(const QString& _testName)
	: QObject()
	, testName(_testName)
{
	qDebug() << "Creating test" << testName;
	testList().push_back(this);
	qDebug() << testList().size() << " tests recorded";
}

TestSuite::~TestSuite()
{
	qDebug() << "Destroying test";
}

std::vector<TestSuite*>& TestSuite::testList()
{
	static std::vector<TestSuite*> instance = std::vector<TestSuite*>();
	return instance;
}

}
