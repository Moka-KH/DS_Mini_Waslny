#include "addroad.h"
#include "ui_addroad.h"

AddRoad::AddRoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddRoad)
{
    ui->setupUi(this);
}

AddRoad::~AddRoad()
{
    delete ui;
}
