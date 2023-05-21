#ifndef DELETECITY_ERROR_H
#define DELETECITY_ERROR_H

#include <QWidget>

namespace Ui {
class DeleteCity_Error;
}

class DeleteCity_Error : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteCity_Error(QWidget *parent = nullptr);
    ~DeleteCity_Error();

private:
    Ui::DeleteCity_Error *ui;
};

#endif // DELETECITY_ERROR_H
