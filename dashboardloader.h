#ifndef DASHBOARDLOADER_H
#define DASHBOARDLOADER_H

#include <QWidget>

namespace Ui {
class DashboardLoader;
}

class DashboardLoader : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardLoader(QWidget *parent = nullptr);
    ~DashboardLoader();

private:
    Ui::DashboardLoader *ui;
};

#endif // DASHBOARDLOADER_H
