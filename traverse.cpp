#include "traverse.h"
#include "gVariables.h"
#include "ui_traverse.h"
#include "dfs.h"
#include "bfs.h"

traverse::traverse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::traverse),
    dfstraverse(new DFS), // Initialize the pointer
    dfstraversal(new BFS) // Initialize the pointer

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
}

traverse::~traverse()
{
    delete ui;
}

void traverse::on_dfstraverse_button_clicked()
{
    traverseVertex=ui->addmap_lineedit->text();
    dfstraverse->show();
    this->hide();
}


void traverse::on_bfstraverse_button_clicked()
{
    traverseVertex=ui->addmap_lineedit->text();
    dfstraversal->show();
    this->hide();
}

