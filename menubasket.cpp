#include "menubasket.h"
#include "ui_menubasket.h"

MenuBasket::MenuBasket(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::MenuBasket)
{
    ui->setupUi(this);
}

MenuBasket::MenuBasket(QVector<QString> ids, QWidget *parent) :
    BaseData(parent),
    ui(new Ui::MenuBasket)
{
    ui->setupUi(this);
    init_table(ids);
}

MenuBasket::~MenuBasket()
{
    delete ui;
}

void MenuBasket::init_table(QVector<QString> ids)
{

    QVector<QVector<QString>> res;
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(ids.size());
    for(int i = 0; i < ids.size(); i++)
    {
        QVector<QString> vec =  get_data_at_id(ids[i].toInt());
        QVector<QString> under;
        under.push_back(ids[i]);
        under.push_back(vec[0]);
        under.push_back(vec[1]);
        under.push_back(vec[2]);
        under.push_back(vec[3]);
        res.push_back(under);
    }
    for(int i = 0; i < ids.size(); i++)
    {
        for(int j = 0; j < 5; j++) {

            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(res[i][j]));
            ui->tableWidget->setItem(i,j, itm);
            if(j == 0)
            {
                addCheckBoxAt(i, 5);
            }
        }

    }
    ui->tableWidget->setColumnHidden(0, true);
}

void MenuBasket::addCheckBoxAt(int row_number, int column_number)
{
    QTableWidgetItem *checkBoxItem = new QTableWidgetItem();
    checkBoxItem->setText("Выбрать");
    checkBoxItem->data(Qt::CheckStateRole);
    checkBoxItem->setCheckState(Qt::Unchecked);
    ui->tableWidget->setItem(row_number,column_number,checkBoxItem);
}

void MenuBasket::on_return_to_menu_clicked()
{
    MainWindow *w = new MainWindow(this);
    this->close();
    w->show();
}

void MenuBasket::on_buy_goods_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){

            if (ui->tableWidget->item(i, 5)->checkState()==Qt::Checked) //принять
            {
                QString count_buy = ui->tableWidget->item(i, 2)->text(); // количество купленного
                QString id = ui->tableWidget->item(i, 0)->text(); //id товара
                req_change_goods(id, count_buy);

            }
    }

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Успешно");
    msgBox.setText("Изменения приняты");
    msgBox.exec();
}
