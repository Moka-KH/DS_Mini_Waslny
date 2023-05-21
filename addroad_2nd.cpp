#include "addroad_2nd.h"
#include "ui_addroad_2nd.h"
#include "update_menu.h"

Update_menu* update_menu_2_returnPointer;

addroad_2nd::addroad_2nd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addroad_2nd)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/Half-Half.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    update_menu_2_returnPointer = nullptr;
}

addroad_2nd::~addroad_2nd()
{
    delete ui;
}

void addroad_2nd::on_addROAD_addButton_clicked()
{

}


void addroad_2nd::on_Returntoupdate_addROAD_clicked()
{
    if (update_menu_2_returnPointer == nullptr)
    {
        update_menu_2_returnPointer = new Update_menu; // Create a new instance if it doesn't exist
        update_menu_2_returnPointer->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_menu_2_returnPointer->show();
    this->hide();
}

