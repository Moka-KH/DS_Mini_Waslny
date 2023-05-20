#ifndef NEWMAP_CREATED_H
#define NEWMAP_CREATED_H

#include <QWidget>
#include <QTimer>
#include "addnewmap.h"

namespace Ui {
class NewMapLoader;
}

class NewMapLoader : public QWidget
{
    Q_OBJECT

public:
    explicit NewMapLoader(QWidget *parent = nullptr);
    ~NewMapLoader();

public slots:
    void loaderScreenTimer();

private:
    Ui::NewMapLoader *ui;
    QTimer * LoaderTimer;
    AddNewMap addnewmap;
};

#endif // NEWMAP_CREATED_H
