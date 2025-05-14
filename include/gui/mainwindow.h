#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QLCDNumber>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>
#include <QTableWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

#include <opencv2/opencv.hpp>
//#include "videoprocessor.h"

#include <include/gui/widgets/videomeasurementwidget.h>
#include <include/gui/widgets/coordinatespanel.h>
#include <include/gui/widgets/toolpresetspanel.h>
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    // Колонка 1: Измерение
    VideoMeasurementWidget* videoWidget;
    CoordinatesPanel* coordsPanel;

    // Колонка 2: Предустановки
    ToolPresetsPanel* presetsPanel;


    // Колонка 3: Вкладки
    QTabWidget *tabWidget;
    QTableWidget *toolParamsTable;
    QTableWidget *partsListTable;
    QTableWidget *commentsTable;
};

#endif // MAINWINDOW_H
