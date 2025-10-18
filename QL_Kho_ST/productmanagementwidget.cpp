#include "productmanagementwidget.h"
#include "ui_productmanagementwidget.h"

ProductManagementWidget::ProductManagementWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductManagementWidget)
{
    ui->setupUi(this);
}

ProductManagementWidget::~ProductManagementWidget()
{
    delete ui;
}
