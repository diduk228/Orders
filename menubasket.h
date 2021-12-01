#ifndef MENUBASKET_H
#define MENUBASKET_H

#include <QMainWindow>

namespace Ui {
class MenuBasket;
}

class MenuBasket : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuBasket(QWidget *parent = nullptr);
    ~MenuBasket();

private:
    Ui::MenuBasket *ui;
};

#endif // MENUBASKET_H
