#ifndef TOOLPRESETSPANEL_H
#define TOOLPRESETSPANEL_H
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QGroupBox>

class ToolPresetsPanel : public QGroupBox{
    Q_OBJECT
public:
    explicit ToolPresetsPanel(QWidget* parent = nullptr);

    QComboBox *toolComboBox;
    QLineEdit *idLineEdit;
    QLineEdit *invLineEdit;
    QLineEdit *descriptionLineEdit;
    QLineEdit *drawingFileLineEdit;
    QPushButton *browseDrawingButton;

    QLineEdit *pitchLineEdit;
    QLineEdit *focusLineEdit;
    QLineEdit *measureRangeLineEdit;
    QLineEdit *edgeShapeLineEdit;
    QLineEdit *zLineEdit;
    QLineEdit *xLineEdit;
    QLineEdit *nominalRadiusLineEdit;
    QLineEdit *angle1LineEdit;
    QLineEdit *angle2LineEdit;


};


#endif // TOOLPRESETSPANEL_H
