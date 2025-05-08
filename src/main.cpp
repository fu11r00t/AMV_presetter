#include "include/gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString fileName;
    QFile styleFile("darkstyle.qss");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        a.setStyleSheet(styleFile.readAll());
        styleFile.close();
    }
    else
        qDebug()<<"Stylesheet not found!";
    if(argc>=2)
        fileName=argv[1];
    else
        fileName=".";
    MainWindow w;
    w.show();
    return a.exec();
}
