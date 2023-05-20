#ifndef DEFAULTCITIES_PATH_H
#define DEFAULTCITIES_PATH_H

#include <QWidget>

namespace Ui {
class DefaultCities_Path;
}

class DefaultCities_Path : public QWidget
{
    Q_OBJECT

public:
    explicit DefaultCities_Path(QWidget *parent = nullptr);
    ~DefaultCities_Path();

private slots:
    void on_return_button_clicked();

private:
    Ui::DefaultCities_Path *ui;
};

#endif // DEFAULTCITIES_PATH_H
