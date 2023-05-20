#include "threecities_path.h"
#include "ui_threecities_path.h"
#include "dashboard.h"

dashboard* dashboard_threecitiesreturnObject;

ThreeCities_Path::ThreeCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThreeCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/3_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_threecitiesreturnObject = nullptr; // Initialize the pointer
}

ThreeCities_Path::~ThreeCities_Path()
{
    delete ui;
}

void ThreeCities_Path::on_return_button_clicked()
{
    if (dashboard_threecitiesreturnObject == nullptr)
    {
        dashboard_threecitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_threecitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_threecitiesreturnObject->show();
    this->hide();
}

