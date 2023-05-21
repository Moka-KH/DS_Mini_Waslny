#include "deleteroad.h"
#include "ui_deleteroad.h"
#include "update_menu.h"

Update_menu* update_menureturnPointer;

deleteRoad::deleteRoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteRoad)
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

    update_menureturnPointer =nullptr;
}

deleteRoad::~deleteRoad()
{
    delete ui;
}

void deleteRoad::on_addROAD_addButton_clicked()
{

}


void deleteRoad::on_Returntoupdate_addROAD_clicked()
{
    if (update_menureturnPointer == nullptr)
    {
        update_menureturnPointer = new Update_menu; // Create a new instance if it doesn't exist
        update_menureturnPointer->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_menureturnPointer->show();
    this->hide();
}

