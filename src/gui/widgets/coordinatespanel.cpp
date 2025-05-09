#include "include/gui/widgets/coordinatespanel.h"
#include <QFormLayout>
#include <QLabel>

CoordinatesPanel::CoordinatesPanel(QWidget* parent)
    : QGroupBox("Координаты", parent) {
    QFormLayout* form = new QFormLayout(this);
    QFont labelFont("Arial", 18, QFont::Bold);
    QFont lcdFont("Arial", 20);

    // Z координата
    QLabel* zLabel = new QLabel("Z:");
    zLabel->setFont(labelFont);
    zCoordLCD = new QLCDNumber(6);
    zCoordLCD->setSegmentStyle(QLCDNumber::Flat);
    zCoordLCD->setFixedWidth(100);
    zCoordLCD->setStyleSheet("QLCDNumber { background: grey; color: lime; }");
    zCoordLCD->setFont(lcdFont);
    zCoordLCD->setSmallDecimalPoint(true);
    form->addRow(zLabel,zCoordLCD);
    // X координата
    QLabel* xLabel = new QLabel("X:");
    xLabel->setFont(labelFont);
    xCoordLCD = new QLCDNumber(6);
    xCoordLCD->setSegmentStyle(QLCDNumber::Flat);
    xCoordLCD->setFixedWidth(100);
    xCoordLCD->setStyleSheet("QLCDNumber { background: grey; color: lime; }");
    xCoordLCD->setFont(lcdFont);
    xCoordLCD->setSmallDecimalPoint(true);
    form->addRow(xLabel,xCoordLCD);
    // Y координата
    QLabel* yLabel = new QLabel("Y:");
    yLabel->setFont(labelFont);
    yCoordLCD = new QLCDNumber(6);
    yCoordLCD->setSegmentStyle(QLCDNumber::Flat);
    yCoordLCD->setFixedWidth(100);
    yCoordLCD->setStyleSheet("QLCDNumber { background: grey; color: lime; }");
    yCoordLCD->setFont(lcdFont);
    yCoordLCD->setSmallDecimalPoint(true);
    form->addRow(yLabel,yCoordLCD);
}
