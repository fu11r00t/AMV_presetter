#ifndef RESULTSTABWIDGET_H
#define RESULTSTABWIDGET_H
#include <QTabWidget>
#include <QTableWidget>

class ResultsTabWidget : public QTabWidget{
    Q_OBJECT
public:
    explicit ResultsTabWidget(QWidget* parent = nullptr);
    QTableWidget* toolsParamsTable;
    QTableWidget* partListTable;
    QTableWidget* commentsTable;
};

#endif // RESULTSTABWIDGET_H
