#ifndef ADDROAD_2ND_H
#define ADDROAD_2ND_H

#include <QWidget>

namespace Ui {
class addroad_2nd;
}

class addroad_2nd : public QWidget
{
    Q_OBJECT

public:
    explicit addroad_2nd(QWidget *parent = nullptr);
    ~addroad_2nd();

private slots:
    void on_addROAD_addButton_clicked();

    void on_Returntoupdate_addROAD_clicked();

private:
    Ui::addroad_2nd *ui;
};

#endif // ADDROAD_2ND_H
