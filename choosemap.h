#ifndef CHOOSEMAP_H
#define CHOOSEMAP_H

#include <QWidget>
#include "dashboard.h"

class dashboard;
class HomePage;

namespace Ui {
class choosemap;
}

class choosemap : public QWidget
{
    Q_OBJECT

public:
    explicit choosemap(QWidget *parent = nullptr);
    ~choosemap();

private slots:
    void on_choosemap_3_clicked();

    void on_addmaperror_return_2_clicked();

private:
    Ui::choosemap *ui;

    //dash board and homepage pointer
    dashboard* dashboardObject;
};

#endif // CHOOSEMAP_H
