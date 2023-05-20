#ifndef MINI_WASALNI_GUI_H
#define MINI_WASALNI_GUI_H

#include <QMainWindow>
#include <QTimer>
#include "welcome.h" // Include the "welcome.h" header file

QT_BEGIN_NAMESPACE
namespace Ui { class Mini_Wasalni_GUI; }
QT_END_NAMESPACE

class Mini_Wasalni_GUI : public QMainWindow
{
    Q_OBJECT

public:
    Mini_Wasalni_GUI(QWidget *parent = nullptr);
    ~Mini_Wasalni_GUI();

public slots:
    void introScreenTimer();

private:
    Ui::Mini_Wasalni_GUI *ui;
    QTimer * introTimer;
    welcome welcome; // Declare the welcome window as a member variable

};
#endif // MINI_WASALNI_GUI_H

