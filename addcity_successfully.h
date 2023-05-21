#ifndef ADDCITY_SUCCESSFULLY_H
#define ADDCITY_SUCCESSFULLY_H

#include <QWidget>

class Update_menu;
class addcity;

namespace Ui {
class AddCity_Successfully;
}

class AddCity_Successfully : public QWidget
{
    Q_OBJECT

public:
    explicit AddCity_Successfully(QWidget *parent = nullptr);
    ~AddCity_Successfully();

private slots:
    void on_addcity_success_addanoter_clicked();

    void on_addcity_success_return_clicked();

private:
    Ui::AddCity_Successfully *ui;
};

#endif // ADDCITY_SUCCESSFULLY_H
