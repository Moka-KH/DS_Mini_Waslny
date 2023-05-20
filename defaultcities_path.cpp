#include "defaultcities_path.h"
#include "ui_defaultcities_path.h"
#include "dashboard.h"

dashboard* dashboard_defaultcitiesreturnObject;


DefaultCities_Path::DefaultCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefaultCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/default_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_defaultcitiesreturnObject= nullptr;
}

DefaultCities_Path::~DefaultCities_Path()
{
    delete ui;
}

void DefaultCities_Path::on_return_button_clicked()
{
    if (dashboard_defaultcitiesreturnObject == nullptr)
    {
        dashboard_defaultcitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_defaultcitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_defaultcitiesreturnObject->show();
    this->hide();
}

