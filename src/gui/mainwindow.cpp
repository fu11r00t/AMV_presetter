#include "include/gui/mainwindow.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // Настройка главного окна
    setWindowTitle("AMV Presetter");
    resize(1200, 800);

    // Главный виджет и layout
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // --- Колонка 1: Измерение ---
    QFrame *measurementColumn = new QFrame;
    QVBoxLayout *measurementLayout = new QVBoxLayout(measurementColumn);

    // Горизонтальный контейнер для изображения и вертикального слайдера
    QHBoxLayout *imageAndFocusLayout = new QHBoxLayout;

    // Изображение с камеры (заглушка)
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
    imageAndFocusLayout->addWidget(imageLabel);

    // Вертикальный слайдер (Фокус) справа от изображения
    focusSlider = new QSlider(Qt::Vertical);
    focusSlider->setFixedHeight(400); // Высота как у изображения
    imageAndFocusLayout->addWidget(focusSlider);

    measurementLayout->addLayout(imageAndFocusLayout);

    // Горизонтальный слайдер (Контраст) под изображением
    contrastSlider = new QSlider(Qt::Horizontal);
    measurementLayout->addWidget(contrastSlider);

    // --- Координаты ---
    QGroupBox *coordsGroup = new QGroupBox("Координаты");
    QFormLayout *coordsForm = new QFormLayout(coordsGroup);

    // Настройка стилей и размеров
    QFont labelFont("Arial", 16, QFont::Bold);
    QFont lcdFont("Arial", 20);

    // Z координата
    QLabel *zLabel = new QLabel("Z:");
    zLabel->setFont(labelFont);
    zCoordLCD = new QLCDNumber(6);
    zCoordLCD->setSegmentStyle(QLCDNumber::Flat);
    zCoordLCD->setStyleSheet("QLCDNumber { background: black; color: lime; }");
    zCoordLCD->setFont(lcdFont);
    zCoordLCD->setSmallDecimalPoint(true);
    coordsForm->addRow(zLabel, zCoordLCD);  // Добавляем в форму

    // X координата
    QLabel *xLabel = new QLabel("X:");
    xLabel->setFont(labelFont);
    xCoordLCD = new QLCDNumber(6);
    xCoordLCD->setSegmentStyle(QLCDNumber::Flat);
    xCoordLCD->setStyleSheet("QLCDNumber { background: black; color: lime; }");
    xCoordLCD->setFont(lcdFont);
    xCoordLCD->setSmallDecimalPoint(true);
    coordsForm->addRow(xLabel, xCoordLCD);

    // C координата
    QLabel *cLabel = new QLabel("C:");
    cLabel->setFont(labelFont);
    cCoordLCD = new QLCDNumber(6);
    cCoordLCD->setSegmentStyle(QLCDNumber::Flat);
    cCoordLCD->setStyleSheet("QLCDNumber { background: black; color: lime; }");
    cCoordLCD->setFont(lcdFont);
    cCoordLCD->setSmallDecimalPoint(true);
    coordsForm->addRow(cLabel, cCoordLCD);

    // Добавляем GroupBox в основной layout
    measurementLayout->addWidget(coordsGroup);

    mainLayout->addWidget(measurementColumn);

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
