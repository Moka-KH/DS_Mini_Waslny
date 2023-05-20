#include "fourcities_path.h"
#include "ui_fourcities_path.h"
#include "dashboard.h"

dashboard* dashboard_fourcitiesreturnObject;

FourCities_Path::FourCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FourCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/4_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_fourcitiesreturnObject = nullptr; // Initialize the pointer
}

FourCities_Path::~FourCities_Path()
{
    delete ui;
}

void FourCities_Path::on_return_button_clicked()
{
    if (dashboard_fourcitiesreturnObject == nullptr)
    {
        dashboard_fourcitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_fourcitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_fourcitiesreturnObject->show();
    this->hide();
}

