#ifndef FIVECITIES_PATH_H
#define FIVECITIES_PATH_H

#include <QWidget>

namespace Ui {
class FiveCities_Path;
}

class FiveCities_Path : public QWidget
{
    Q_OBJECT

public:
    explicit FiveCities_Path(QWidget *parent = nullptr);
    ~FiveCities_Path();

private slots:
    void on_return_button_clicked();

private:
    Ui::FiveCities_Path *ui;
};

#endif // FIVECITIES_PATH_H
