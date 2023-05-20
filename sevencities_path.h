#ifndef SEVENCITIES_PATH_H
#define SEVENCITIES_PATH_H

#include <QWidget>

namespace Ui {
class SevenCities_Path;
}

class SevenCities_Path : public QWidget
{
    Q_OBJECT

public:
    explicit SevenCities_Path(QWidget *parent = nullptr);
    ~SevenCities_Path();

private slots:
    void on_return_button_clicked();

private:
    Ui::SevenCities_Path *ui;
};

#endif // SEVENCITIES_PATH_H
