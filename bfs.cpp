#include "bfs.h"
#include "ui_bfs.h"
#include "dashboard.h"

dashboard* dashboard_bfsreturnObject;

BFS::BFS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BFS)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/centered.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_bfsreturnObject = nullptr; // Initialize the pointer
}

BFS::~BFS()
{
    delete ui;
}

void BFS::on_traverse_button_clicked()
{
    if (dashboard_bfsreturnObject == nullptr)
    {
        dashboard_bfsreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_bfsreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_bfsreturnObject->show();
    this->hide();
}

