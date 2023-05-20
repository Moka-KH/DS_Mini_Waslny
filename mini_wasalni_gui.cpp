#include "mini_wasalni_gui.h"
#include "ui_mini_wasalni_gui.h"
#include "welcome.h" // Include the "welcome.h" header file
#include <QPixmap>
#include <QTimer>

Mini_Wasalni_GUI::Mini_Wasalni_GUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mini_Wasalni_GUI)
{
    ui->setupUi(this);



    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/Pic_Intro.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    // Timer
    introTimer = new QTimer(this);
    connect(introTimer, SIGNAL(timeout()), this, SLOT(introScreenTimer()));
    introTimer->start(3000);
}

Mini_Wasalni_GUI::~Mini_Wasalni_GUI()
{
    delete ui;
}

void Mini_Wasalni_GUI::introScreenTimer()
{
    introTimer->stop(); // Stop the timer

    welcome.show(); // Show the welcome window

    close(); // Close the Mini_Wasalni_GUI window
}
