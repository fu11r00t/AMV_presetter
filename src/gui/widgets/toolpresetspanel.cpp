#include <include/gui/widgets/toolpresetspanel.h>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QFileDialog>

ToolPresetsPanel::ToolPresetsPanel(QWidget* parent)
    :QGroupBox(parent) {
    QVBoxLayout *presetsLayout = new QVBoxLayout(this);

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

    // Подключение сигналов
    connect(browseDrawingButton, &QPushButton::clicked, [this]() {
        QString file = QFileDialog::getOpenFileName(this, "Выберите чертёж", "", "Файлы (*.dwg *.dxf *.pdf)");
        if (!file.isEmpty()) {
            drawingFileLineEdit->setText(file);
        }
    });

    // Заглушка для будущих кнопок и джойстика
    QPushButton *calibrateButton = new QPushButton("Калибровать");
    presetsLayout->addWidget(calibrateButton);
}
