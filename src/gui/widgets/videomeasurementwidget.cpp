#include "include/gui/widgets/videomeasurementwidget.h"
#include <QVBoxLayout>

VideoMeasurementWidget::VideoMeasurementWidget(QWidget* parent)
    : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Виджет изображения
    imageLabel = new QLabel;
    imageLabel->setFixedSize(400, 400);
    imageLabel->setStyleSheet("background-color: black; border: 2px solid gray;");
    QImage image("scan.png");
    if(image.isNull())
    {
        qDebug()<<"Failed to load image!";
        return;
    }
    QPixmap pixmap = QPixmap::fromImage(image);
    imageLabel->setPixmap(pixmap);
    imageLabel->setScaledContents(true);
    layout->addWidget(imageLabel);

    // Слайдеры
    contrastSlider = new QSlider(Qt::Horizontal);
    focusSlider = new QSlider(Qt::Vertical);
    focusSlider->setFixedHeight(400);

    // Компоновка
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(imageLabel);
    hLayout->addWidget(focusSlider);

    layout->addLayout(hLayout);
    layout->addWidget(contrastSlider);
}
