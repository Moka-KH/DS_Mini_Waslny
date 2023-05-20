#include "sevencities_path.h"
#include "ui_sevencities_path.h"
#include "dashboard.h"

dashboard* dashboard_sevencitiesreturnObject;

SevenCities_Path::SevenCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SevenCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/7_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_sevencitiesreturnObject = nullptr; // Initialize the pointer
}

SevenCities_Path::~SevenCities_Path()
{
    delete ui;
}

void SevenCities_Path::on_return_button_clicked()
{
    if (dashboard_sevencitiesreturnObject == nullptr)
    {
        dashboard_sevencitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_sevencitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_sevencitiesreturnObject->show();
    this->hide();
}

