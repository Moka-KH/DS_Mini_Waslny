#ifndef THREECITIES_PATH_H
#define THREECITIES_PATH_H

#include <QWidget>

namespace Ui {
class ThreeCities_Path;
}

class ThreeCities_Path : public QWidget
{
    Q_OBJECT

public:
    explicit ThreeCities_Path(QWidget *parent = nullptr);
    ~ThreeCities_Path();

private slots:
    void on_return_button_clicked();

private:
    Ui::ThreeCities_Path *ui;
};

#endif // THREECITIES_PATH_H
