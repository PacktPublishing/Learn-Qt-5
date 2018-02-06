#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>
#include <QString>
#include <QtTest/QtTest>

#include <vector>

namespace cm {

class TestSuite : public QObject
{
	Q_OBJECT
public:
	explicit TestSuite(const QString& _testName = "");
	virtual ~TestSuite();

	QString testName;
	static std::vector<TestSuite*>& testList();
};

}

#endif
