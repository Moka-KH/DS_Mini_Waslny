#ifndef EXITLOADER_H
#define EXITLOADER_H

#include <QWidget>

namespace Ui {
class ExitLoader;
}

class ExitLoader : public QWidget
{
    Q_OBJECT

public:
    explicit ExitLoader(QWidget *parent = nullptr);
    ~ExitLoader();

private:
    Ui::ExitLoader *ui;
};

#endif // EXITLOADER_H
