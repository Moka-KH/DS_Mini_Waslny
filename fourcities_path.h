#ifndef FOURCITIES_PATH_H
#define FOURCITIES_PATH_H

#include <QWidget>

namespace Ui {
class FourCities_Path;
}

class FourCities_Path : public QWidget
{
    Q_OBJECT

public:
    explicit FourCities_Path(QWidget *parent = nullptr);
    ~FourCities_Path();

private slots:
    void on_return_button_clicked();

private:
    Ui::FourCities_Path *ui;
};

#endif // FOURCITIES_PATH_H
