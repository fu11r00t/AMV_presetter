#ifndef VIDEOMEASUREMENTWIDGET_H
#define VIDEOMEASUREMENTWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QSlider>

class VideoMeasurementWidget : public QWidget{
    Q_OBJECT
public:
    explicit VideoMeasurementWidget(QWidget* parent = nullptr);

    QLabel* imageLabel;
    QSlider* contrastSlider;
    QSlider* focusSlider;

    void loadImage(const QString& path);
};

#endif // VIDEOMEASUREMENTWIDGET_H
