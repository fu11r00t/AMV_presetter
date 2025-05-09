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
    QLCDNumber* cCoordLCD;

    void updateCoordinates(double z, double x, double c);
};
#endif // COORDINATESPANEL_H
