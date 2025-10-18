#ifndef PRODUCTMANAGEMENTWIDGET_H
#define PRODUCTMANAGEMENTWIDGET_H

#include <QWidget>

namespace Ui {
class ProductManagementWidget;
}

class ProductManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagementWidget(QWidget *parent = nullptr);
    ~ProductManagementWidget();

private:
    Ui::ProductManagementWidget *ui;
};

#endif // PRODUCTMANAGEMENTWIDGET_H
