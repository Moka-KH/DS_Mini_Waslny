#include "dfs.h"
#include "ui_dfs.h"
#include "dashboard.h"
#include"gVariables.h"
#include"algorithms.h"
#include <QQueue>

dashboard* dashboard_dfsreturnObject;

DFS::DFS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DFS)
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

    //set data on labels
    /*QQueue<QString> DFSOut=DFSS(*currentGraph,startingVertex);
    QString dfsData;
    QString helperstring(" ->");
    if (DFSOut.isEmpty()) {
        ui->dfs_display_label->setText("The queue is empty");
    }
    else if (!DFSOut.isEmpty()) {
        while (!DFSOut.isEmpty()) {
            QString item = DFSOut.dequeue();
            dfsData += item+helperstring;
        }
        ui->dfs_display_label->setText(dfsData);
    }
    */
    dashboard_dfsreturnObject = nullptr; // Initialize the pointer
}

DFS::~DFS()
{
    delete ui;
}

void DFS::on_traverse_button_clicked()
{
    if (dashboard_dfsreturnObject == nullptr)
    {
        dashboard_dfsreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_dfsreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_dfsreturnObject->show();
    this->hide();
}

