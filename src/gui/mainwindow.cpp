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
    coordsPanel=new CoordinatesPanel;
    presetsPanel = new ToolPresetsPanel;

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
    tabWidget = new QTabWidget;
    toolParamsTable = new QTableWidget(10, 2);
    toolParamsTable->setHorizontalHeaderLabels({"Параметр", "Значение"});
    partsListTable = new QTableWidget(10, 3);
    partsListTable->setHorizontalHeaderLabels({"Деталь", "ID", "Статус"});
    commentsTable = new QTableWidget(10, 1);
    commentsTable->setHorizontalHeaderLabels({"Комментарий"});

    tabWidget->addTab(toolParamsTable, "Параметры инструмента");
    tabWidget->addTab(partsListTable, "Список деталей");
    tabWidget->addTab(commentsTable, "Комментарии");

    mainLayout->addWidget(tabWidget);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}
