#include "addcity.h"
#include "ui_addcity.h"

addcity::addcity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addcity)
{
    ui->setupUi(this);
}

addcity::~addcity()
{
    delete ui;
}

void addcity::on_addCITY_add_clicked()
{

}


void addcity::on_Returntoupdate_addcity_clicked()
{

}

