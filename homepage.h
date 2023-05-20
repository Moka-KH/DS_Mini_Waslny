#pragma once
#ifndef HOMEPAGE_H
#define HOMEPAGE_H
#include <QWidget>
#include "exitloader.h"
#include "addmap.h"
#include "dummy.h"


class choosemap;
class addmap;

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT


public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_pushButton_addnewmap_clicked();

    void on_pushButton_mapdashboard_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::HomePage *ui;
    ExitLoader exitloader;

    //pointers intializations
    addmap* addmapObject;
    choosemap* choosemapObject;
};

#endif // HOMEPAGE_H
