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
    zCoordLCD->setStyleSheet("QLCDNumber { background: black; color: lime; }");
    zCoordLCD->setFont(lcdFont);
    zCoordLCD->setSmallDecimalPoint(true);
    form->addRow(zLabel,zCoordLCD);
}
