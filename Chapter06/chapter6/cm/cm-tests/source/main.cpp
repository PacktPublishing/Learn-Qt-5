#include <QtTest/QtTest>
#include <QDebug>

#include "test-suite.h"

using namespace cm;

int main(int argc, char *argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	qDebug() << "Starting test suite...";
	qDebug() << "Accessing tests from " << &TestSuite::testList();
	qDebug() << TestSuite::testList().size() << " tests detected";

	int failedTestsCount = 0;

	for(TestSuite* i : TestSuite::testList()) {
		qDebug() << "Executing test " << i->testName;
		QString filename(i->testName + ".xml");
		int result = QTest::qExec(i, QStringList() << " " << "-o" << filename << "-xunitxml");
		qDebug() << "Test result " << result;
		if(result != 0) {
			failedTestsCount++;
		}
	}

	qDebug() << "Test suite complete - " << QString::number(failedTestsCount) << " failures detected.";

	return failedTestsCount;
}
