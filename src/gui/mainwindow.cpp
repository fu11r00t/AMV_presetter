#include "include/gui/mainwindow.h"
#include "include/gui/widgets/videomeasurementwidget.h"
#include "include/gui/widgets/coordinatespanel.h"
#include "include/gui/widgets/toolpresetspanel.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // Настройка главного окна
    setWindowTitle("AMV Presetter");
    resize(1200, 800);

    // Создание виджетов
    videoWidget = new VideoMeasurementWidget;
    coordsPanel = new CoordinatesPanel;
    presetsPanel = new ToolPresetsPanel;
    resultsTabWidget = new ResultsTabWidget;

    // Основная компоновка
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Левая колонка
    QVBoxLayout* leftColumn = new QVBoxLayout;
    leftColumn->addWidget(videoWidget);
    leftColumn->addWidget(coordsPanel);

    mainLayout->addLayout(leftColumn);

    // --- Колонка 2: Предустановки ---
    QVBoxLayout* presetsColumn = new QVBoxLayout;
    presetsColumn->addWidget(presetsPanel);

    mainLayout->addLayout(presetsColumn);

    // --- Колонка 3: Вкладки ---
    QVBoxLayout* resultsColumn = new QVBoxLayout;
    resultsColumn->addWidget(resultsTabWidget);

    mainLayout->addLayout(resultsColumn);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
