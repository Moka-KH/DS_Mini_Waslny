#include "deleteroad.h"
#include "ui_deleteroad.h"

deleteRoad::deleteRoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteRoad)
{
    ui->setupUi(this);
}

deleteRoad::~deleteRoad()
{
    delete ui;
}
