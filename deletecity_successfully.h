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

private:
    Ui::DeleteCity_Successfully *ui;
};

#endif // DELETECITY_SUCCESSFULLY_H
