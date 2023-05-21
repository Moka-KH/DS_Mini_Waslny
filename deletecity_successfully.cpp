#include "deletecity_successfully.h"
#include "ui_deletecity_successfully.h"

DeleteCity_Successfully::DeleteCity_Successfully(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteCity_Successfully)
{
    ui->setupUi(this);
}

DeleteCity_Successfully::~DeleteCity_Successfully()
{
    delete ui;
}
