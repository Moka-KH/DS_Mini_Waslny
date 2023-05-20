#ifndef ADDMAP_SUCCESSFULLY_H
#define ADDMAP_SUCCESSFULLY_H

#include <QWidget>


class HomePage;
class addmap;

namespace Ui {
class addmap_successfully;
}

class addmap_successfully : public QWidget
{
    Q_OBJECT

public:
    explicit addmap_successfully(QWidget *parent = nullptr);
    ~addmap_successfully();

private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_addanother_clicked();

private:
    Ui::addmap_successfully *ui;
};

#endif // ADDMAP_SUCCESSFULLY_H
