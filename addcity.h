#ifndef ADDCITY_H
#define ADDCITY_H

#include <QWidget>
#include <addcity_error.h>
#include <addcity_successfully.h>

class AddCity_Error;
class AddCity_Successfully;

namespace Ui {
class addcity;
}

class addcity : public QWidget
{
    Q_OBJECT

public:
    explicit addcity(QWidget *parent = nullptr);
    ~addcity();

private slots:
    void on_addCITY_add_clicked();

    void on_Returntoupdate_addcity_clicked();

private:
    Ui::addcity *ui;

    AddCity_Successfully* cityaddedPointer;
    AddCity_Error*  addcityerrorPointer;
};

#endif // ADDCITY_H
