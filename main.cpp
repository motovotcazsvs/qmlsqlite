#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "sqlitebase.h"
#include "listmodel.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    sqlitebase database;
    engine.rootContext()->setContextProperty("database", &database);

    // Объявляем и инициализируем модель данных
    ListModel *model = new ListModel();
    engine.rootContext()->setContextProperty("myModel", model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
