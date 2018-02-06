#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <mocking.h>

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	qDebug() << "Running the production code...";

	DatabaseController databaseController;

	Client client1(databaseController);
	client1.save();
	Client client2(databaseController);
	client2.save();

	qDebug() << "Running the test code...";

	ClientTestSuite testSuite;
	testSuite.saveTests();

	return app.exec();
}
