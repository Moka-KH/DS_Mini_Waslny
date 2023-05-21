#include "fivecities_path.h"
#include "ui_fivecities_path.h"
#include "dashboard.h"
#include"gVariables.h"

dashboard* dashboard_fivecitiesreturnObject;

FiveCities_Path::FiveCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FiveCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/5_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    // Set the text of the label
    ui->city1_label->setText(startingVertex);

    ui->distanse_between_label_1->setText(QString::number(path.top().second));
    ui->city2_label->setText(path.top().first);

    path.pop();

    ui->distanse_between_label_2->setText(QString::number(path.top().second));
    ui->city3_label->setText(path.top().first);

    path.pop();

    ui->distanse_between_label_3->setText(QString::number(path.top().second));
    ui->city4_label->setText(path.top().first);

    path.pop();

    ui->distanse_between_label_4->setText(QString::number(path.top().second));
    ui->city5_label->setText(path.top().first);

    path.pop();

    ui->shortestdistance->setText("The shortest distance between " + startingVertex + " and " + targetVertex + " is: " + QString::number(totalDistance));

    dashboard_fivecitiesreturnObject = nullptr; // Initialize the pointer
}

FiveCities_Path::~FiveCities_Path()
{
    delete ui;
}

void FiveCities_Path::on_return_button_clicked()
{
    if (dashboard_fivecitiesreturnObject == nullptr)
    {
        dashboard_fivecitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_fivecitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_fivecitiesreturnObject->show();
    this->hide();
}

