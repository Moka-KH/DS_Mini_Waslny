#include "deletecity_error.h"
#include "ui_deletecity_error.h"

DeleteCity_Error::DeleteCity_Error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteCity_Error)
{
    ui->setupUi(this);
}

DeleteCity_Error::~DeleteCity_Error()
{
    delete ui;
}
