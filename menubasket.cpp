#include "menubasket.h"
#include "ui_menubasket.h"

MenuBasket::MenuBasket(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::MenuBasket)
{
    ui->setupUi(this);
    set_cucki();
}

MenuBasket::MenuBasket(QVector<QString> ids, QWidget *parent) :
    BaseData(parent),
    ui(new Ui::MenuBasket)
{
    ui->setupUi(this);
    init_table(ids);
    set_cucki();
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

                QVector<QString> data;
                data.push_back(id);  //id продукта
                data.push_back(count_buy);                   //количество купленного товара
                QVector<QString> vec = get_data_at_id(id.toInt());
                data.push_back(vec[3]); //цена продукта
                data.push_back(QString::number(vec[3].toFloat() * count_buy.toFloat())); // Цена продукта * количество купленного товара
                data.push_back(QString::number(get_id()));    // id user'a
                add_order(data);

            }
    }

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Успешно");
    msgBox.setText("Ваш заказ направлен на обработку!");
    msgBox.exec();
}
