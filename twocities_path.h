#ifndef TWOCITIES_PATH_H
#define TWOCITIES_PATH_H

#include <QWidget>

namespace Ui {
class TwoCities_Path;
}

class TwoCities_Path : public QWidget
{
    Q_OBJECT

public:
    explicit TwoCities_Path(QWidget *parent = nullptr);
    ~TwoCities_Path();

private slots:
    void on_traverse_button_clicked();

private:
    Ui::TwoCities_Path *ui;
};

#endif // TWOCITIES_PATH_H
