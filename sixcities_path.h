#ifndef SIXCITIES_PATH_H
#define SIXCITIES_PATH_H

#include <QWidget>

namespace Ui {
class SixCities_Path;
}

class SixCities_Path : public QWidget
{
    Q_OBJECT

public:
    explicit SixCities_Path(QWidget *parent = nullptr);
    ~SixCities_Path();

private slots:
    void on_return_button_clicked();

private:
    Ui::SixCities_Path *ui;
};

#endif // SIXCITIES_PATH_H
