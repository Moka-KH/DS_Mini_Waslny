#ifndef DELETECITY_SUCCESSFULLY_H
#define DELETECITY_SUCCESSFULLY_H

#include <QWidget>

namespace Ui {
class DeleteCity_Successfully;
}

class DeleteCity_Successfully : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteCity_Successfully(QWidget *parent = nullptr);
    ~DeleteCity_Successfully();

private slots:
    void on_deletecity_success_addanoter_clicked();

    void on_deletecity_success_return_clicked();

private:
    Ui::DeleteCity_Successfully *ui;
};

#endif // DELETECITY_SUCCESSFULLY_H
