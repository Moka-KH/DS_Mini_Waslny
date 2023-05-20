#ifndef SELECTMAP_H
#define SELECTMAP_H

#include <QWidget>

namespace Ui {
class selectmap;
}

class selectmap : public QWidget
{
    Q_OBJECT

public:
    explicit selectmap(QWidget *parent = nullptr);
    ~selectmap();

private:
    Ui::selectmap *ui;
};

#endif // SELECTMAP_H
