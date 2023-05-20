#ifndef ADDMAP_H
#define ADDMAP_H

#include <QWidget>
#include "addmap_successfully.h"
#include "addmap_error.h"

class addmap_successfully;
class HomePage;
class addmap_error;

namespace Ui {
class addmap;
}

class addmap : public QWidget
{
    Q_OBJECT


public:
    explicit addmap(QWidget *parent = nullptr);
    ~addmap();

private slots:
    void on_addmap_add_2_clicked();

    void on_addmap_add_clicked();

private:
    Ui::addmap *ui;
    addmap_successfully* mapaddedObject; //pointer
    addmap_error* addmaperrorObject;
};

#endif // ADDMAP_H
