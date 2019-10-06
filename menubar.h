#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMainWindow>

namespace Ui {
class Menubar;
}

class Menubar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menubar(QWidget *parent = nullptr);
    ~Menubar();

private slots:
    void on_actionExit_triggered();

    void on_actionNew_triggered();

private:
    Ui::Menubar *ui;
};

#endif // MENUBAR_H
