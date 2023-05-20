#ifndef ADDCITY_H
#define ADDCITY_H

#include <QWidget>

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
};

#endif // ADDCITY_H
