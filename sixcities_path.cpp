#include "sixcities_path.h"
#include "ui_sixcities_path.h"
#include "dashboard.h"

dashboard* dashboard_sixcitiesreturnObject;

SixCities_Path::SixCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SixCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/6_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_sixcitiesreturnObject = nullptr; // Initialize the pointer
}

SixCities_Path::~SixCities_Path()
{
    delete ui;
}

void SixCities_Path::on_return_button_clicked()
{
    if (dashboard_sixcitiesreturnObject == nullptr)
    {
        dashboard_sixcitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_sixcitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_sixcitiesreturnObject->show();
    this->hide();
}

