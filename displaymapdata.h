#ifndef DISPLAYMAPDATA_H
#define DISPLAYMAPDATA_H

#include <QWidget>

class dashboard;

namespace Ui {
class DisplayMapData;
}

class DisplayMapData : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayMapData(QWidget *parent = nullptr);
    ~DisplayMapData();

private slots:
    void on_returntodashboard_button_clicked();

private:
    Ui::DisplayMapData *ui;
};

#endif // DISPLAYMAPDATA_H
