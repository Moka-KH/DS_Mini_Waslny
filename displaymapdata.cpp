#include "displaymapdata.h"
#include "ui_displaymapdata.h"
#include "dashboard.h"
//Malk
#include "gVariables.h"

dashboard* dashboard_returnObject;

DisplayMapData::DisplayMapData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayMapData)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/Display.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_returnObject = nullptr; // Initialize the pointer

    if(currentGraph->empty())
    {
        ui->display_mapdata_label->setText("Your graph is empty");
    }
    else
    {
        ui->display_mapdata_label->setText(currentGraph->display());
    }
}

DisplayMapData::~DisplayMapData()
{
    delete ui;
}

void DisplayMapData::on_returntodashboard_button_clicked()
{
    if (dashboard_returnObject == nullptr)
    {
        dashboard_returnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_returnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_returnObject->show();
    this->hide();
}

