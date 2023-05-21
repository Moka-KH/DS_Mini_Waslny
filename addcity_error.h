#ifndef ADDCITY_ERROR_H
#define ADDCITY_ERROR_H

#include <QWidget>

class Update_menu;
class addcity;

namespace Ui {
class AddCity_Error;
}

class AddCity_Error : public QWidget
{
    Q_OBJECT

public:
    explicit AddCity_Error(QWidget *parent = nullptr);
    ~AddCity_Error();

private slots:
    void on_addcity_error_addanoter_clicked();

    void on_addcity_error_return_clicked();

private:
    Ui::AddCity_Error *ui;
};

#endif // ADDCITY_ERROR_H
