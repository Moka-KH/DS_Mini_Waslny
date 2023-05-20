#ifndef ADDMAP_ERROR_H
#define ADDMAP_ERROR_H

#include <QWidget>


class HomePage;
class addmap;

namespace Ui {
class addmap_error;
}

class addmap_error : public QWidget
{
    Q_OBJECT

public:
    explicit addmap_error(QWidget *parent = nullptr);
    ~addmap_error();

private slots:
    void on_addmaperror_return_clicked();

    void on_addmaperror_addanother_clicked();

private:
    Ui::addmap_error *ui;
};

#endif // ADDMAP_ERROR_H
