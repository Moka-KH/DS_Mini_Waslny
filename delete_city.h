#ifndef DELETE_CITY_H
#define DELETE_CITY_H

#include <QWidget>

#include "deletecity_error.h"
#include "deletecity_successfully.h"

class DeleteCity_Error;
class DeleteCity_Successfully;

namespace Ui {
class delete_city;
}

class delete_city : public QWidget
{
    Q_OBJECT

public:
    explicit delete_city(QWidget *parent = nullptr);
    ~delete_city();

private slots:
    void on_deleteCITY_deleteButton_clicked();

    void on_Returntoupdate_deleteCITY_clicked();

private:
    Ui::delete_city *ui;

    DeleteCity_Successfully* citydeletedPointer;
    DeleteCity_Error* deletecityerrorPointer;
};

#endif // DELETE_CITY_H
