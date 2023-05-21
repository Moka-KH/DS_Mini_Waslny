#include "addroad_2nd.h"
#include "ui_addroad_2nd.h"

addroad_2nd::addroad_2nd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addroad_2nd)
{
    ui->setupUi(this);
}

addroad_2nd::~addroad_2nd()
{
    delete ui;
}
