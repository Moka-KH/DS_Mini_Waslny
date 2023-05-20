#include "addcity.h"
#include "ui_addcity.h"
#include"graph.h"
#include"enumerators.cpp"

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
    graph myGraph;
    QString cityName=ui->addCITY_lineedit->text();

    int message=myGraph.addCity(cityName);
    if(message==cityExists)
    {
        hide(); // Close
        //->show();
    }
    else if (message == success)
    {
        hide(); // Close
        //->show()
    }

}


void addcity::on_Returntoupdate_addcity_clicked()
{

}

