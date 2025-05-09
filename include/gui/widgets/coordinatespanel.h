#ifndef COORDINATESPANEL_H
#define COORDINATESPANEL_H
#include <QLCDNumber>
#include <QGroupBox>


class CoordinatesPanel : public QGroupBox{
    Q_OBJECT
public:
    explicit CoordinatesPanel(QWidget* parent = nullptr);

    QLCDNumber* zCoordLCD;
    QLCDNumber* xCoordLCD;
    QLCDNumber* yCoordLCD;

    void updateCoordinates(double z, double x, double y);
};
#endif // COORDINATESPANEL_H
