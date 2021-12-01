#ifndef PROCESSORDERSWINDOW_H
#define PROCESSORDERSWINDOW_H

#include <QMainWindow>

namespace Ui {
class ProcessOrdersWindow;
}

class ProcessOrdersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProcessOrdersWindow(QWidget *parent = nullptr);
    ~ProcessOrdersWindow();

private:
    Ui::ProcessOrdersWindow *ui;
};

#endif // PROCESSORDERSWINDOW_H
