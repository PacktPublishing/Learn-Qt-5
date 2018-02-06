#ifndef MOCKING_H
#define MOCKING_H

#include <QDebug>

class Client;

class IDatabaseController
{
public:
	virtual ~IDatabaseController(){}
	virtual void save(Client* client) = 0;
};

class DatabaseController : public IDatabaseController
{
public:
	DatabaseController()
	{
		qDebug() << "Creating a new database connection";
	}

	void save(Client* client) override
	{
		qDebug() << "Saving a Client to the production database";
	}
};

class MockDatabaseController : public IDatabaseController
{
public:
	MockDatabaseController()
	{
		qDebug() << "Absolutely not creating any database connections at all";
	}

	void save(Client* client) override
	{
		qDebug() << "Just testing - not saving any Clients to any databases";
	}
};

class Client
{
	IDatabaseController& databaseController;

public:
	Client(IDatabaseController& _databaseController)
		: databaseController(_databaseController)
	{
	}

	void save()
	{
		qDebug() << "Saving Client";
		databaseController.save(this);
	}
};

class ClientTestSuite
{
public:
	void saveTests()
	{
		MockDatabaseController databaseController;
		Client client1(databaseController);
		client1.save();
		Client client2(databaseController);
		client2.save();

		qDebug() << "Test passed!";
	}
};

#endif
