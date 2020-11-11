#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "BarcodeFilter.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // If you use Qt version older than 5.15 you need to manually register BarcodeFilter
    //qmlRegisterType<BarcodeFilter>("com.scythestudio.sbarcodereader", 1, 0, "BarcodeFilter");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/ScannerPage.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
