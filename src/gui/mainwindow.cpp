#include "include/gui/mainwindow.h"
#include "include/gui/widgets/videomeasurementwidget.h"
#include "include/gui/widgets/coordinatespanel.h"
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

    // Основная компоновка
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Левая колонка
    QVBoxLayout* leftColumn = new QVBoxLayout;
    leftColumn->addWidget(videoWidget);
    leftColumn->addWidget(coordsPanel);

    mainLayout->addLayout(leftColumn);

    // --- Колонка 2: Предустановки ---
    QFrame *presetsColumn = new QFrame;
    QVBoxLayout *presetsLayout = new QVBoxLayout(presetsColumn);

    // Блок 1: Инструмент
    QGroupBox *toolGroup = new QGroupBox("Инструмент");
    QFormLayout *toolForm = new QFormLayout(toolGroup);
    toolComboBox = new QComboBox;
    toolComboBox->addItems({"Инструмент 1", "Инструмент 2", "Инструмент 3"});
    toolForm->addRow("Инструмент:", toolComboBox);
    idLineEdit = new QLineEdit;
    invLineEdit = new QLineEdit;
    descriptionLineEdit = new QLineEdit;
    drawingFileLineEdit = new QLineEdit;
    browseDrawingButton = new QPushButton("Обзор...");
    toolForm->addRow("ID no.:", idLineEdit);
    toolForm->addRow("Inv. no.:", invLineEdit);
    toolForm->addRow("Описание:", descriptionLineEdit);
    toolForm->addRow("Чертёж:", drawingFileLineEdit);
    toolForm->addWidget(browseDrawingButton);
    presetsLayout->addWidget(toolGroup);

    // Блок 2: Параметры
    QGroupBox *paramsGroup = new QGroupBox("Параметры");
    QFormLayout *paramsForm = new QFormLayout(paramsGroup);
    pitchLineEdit = new QLineEdit;
    focusLineEdit = new QLineEdit;
    measureRangeLineEdit = new QLineEdit;
    edgeShapeLineEdit = new QLineEdit;
    paramsForm->addRow("Шаг:", pitchLineEdit);
    paramsForm->addRow("Фокус:", focusLineEdit);
    paramsForm->addRow("Диапазон измерения:", measureRangeLineEdit);
    paramsForm->addRow("Форма режущей кромки:", edgeShapeLineEdit);
    presetsLayout->addWidget(paramsGroup);

    // Блок 3: Геометрия
    QGroupBox *geometryGroup = new QGroupBox("Геометрия");
    QFormLayout *geometryForm = new QFormLayout(geometryGroup);
    zLineEdit = new QLineEdit;
    xLineEdit = new QLineEdit;
    nominalRadiusLineEdit = new QLineEdit;
    angle1LineEdit = new QLineEdit;
    angle2LineEdit = new QLineEdit;
    geometryForm->addRow("Z:", zLineEdit);
    geometryForm->addRow("X:", xLineEdit);
    geometryForm->addRow("Номинальный радиус:", nominalRadiusLineEdit);
    geometryForm->addRow("Угол 1:", angle1LineEdit);
    geometryForm->addRow("Угол 2:", angle2LineEdit);
    presetsLayout->addWidget(geometryGroup);

    // Заглушка для будущих кнопок и джойстика
    QPushButton *calibrateButton = new QPushButton("Калибровать");
    presetsLayout->addWidget(calibrateButton);

    mainLayout->addWidget(presetsColumn);

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

    // Подключение сигналов
    connect(browseDrawingButton, &QPushButton::clicked, [this]() {
        QString file = QFileDialog::getOpenFileName(this, "Выберите чертёж", "", "Файлы (*.dwg *.dxf *.pdf)");
        if (!file.isEmpty()) {
            drawingFileLineEdit->setText(file);
        }
    });
}
