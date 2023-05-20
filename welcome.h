#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include "homepage.h"

namespace Ui {
class welcome;
}

class welcome : public QWidget
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();

private slots:
    void on_pushButton_clicked();

private:
    Ui::welcome *ui;
    HomePage homepage; // Declare the homepage window as a member variable
};

#endif // WELCOME_H
