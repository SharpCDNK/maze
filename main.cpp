#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "matrixitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Регистрация класса в модуле CustomComponents версии 1.0
    qmlRegisterType<MatrixItem>("CustomComponents", 1, 0, "MatrixItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
