#include "include/gui/widgets/resultstabwidget.h"
#include <QTableWidget>
#include <QTabWidget>
#include <QVBoxLayout>

ResultsTabWidget::ResultsTabWidget(QWidget* parent)
    :QTabWidget(parent) {
    QVBoxLayout *resultsLayout = new QVBoxLayout(this);
    QTabWidget *tabWidget = new QTabWidget();
    toolParamsTable = new QTableWidget(10, 2);
    toolParamsTable->setHorizontalHeaderLabels({"Параметр", "Значение"});
    partListTable = new QTableWidget(10, 3);
    partListTable->setHorizontalHeaderLabels({"Деталь", "ID", "Статус"});
    commentsTable = new QTableWidget(10, 1);
    commentsTable->setHorizontalHeaderLabels({"Комментарий"});

    tabWidget->addTab(toolParamsTable, "Параметры инструмента");
    tabWidget->addTab(partListTable, "Список деталей");
    tabWidget->addTab(commentsTable, "Комментарии");
    resultsLayout->addWidget(tabWidget);
}
