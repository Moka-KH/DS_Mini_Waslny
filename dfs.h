#ifndef DFS_H
#define DFS_H

#include <QWidget>

class dashboard;

namespace Ui {
class DFS;
}

class DFS : public QWidget
{
    Q_OBJECT

public:
    explicit DFS(QWidget *parent = nullptr);
    ~DFS();

private slots:
    void on_traverse_button_clicked();

private:
    Ui::DFS *ui;
};

#endif // DFS_H
