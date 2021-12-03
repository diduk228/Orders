#include "processorderswindow.h"
#include "ui_processorderswindow.h"

ProcessOrdersWindow::ProcessOrdersWindow(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::ProcessOrdersWindow)
{
    ui->setupUi(this);
    init_table();
}

ProcessOrdersWindow::~ProcessOrdersWindow()
{
    delete ui;
}

void ProcessOrdersWindow::init_table()
{
    QVector<QVector<QString>> res;
    QVector<QVector<QString>> vec = get_data_from_orders();
    int count =  get_count_orders();
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setRowCount(count);
    for(int i = 0; i < count; i++)
    {
        QVector<QString> under_vec;
        QVector<QString> goods = get_data_at_id(vec[i][1].toInt());
        under_vec.push_back(vec[i][0]);
        under_vec.push_back(vec[i][1]);
        under_vec.push_back(get_name_by_id(vec[i][5].toInt()));
        under_vec.push_back(goods[0]);
        under_vec.push_back(vec[i][2]);
        under_vec.push_back(QString("%1").arg(goods[3]));
        under_vec.push_back(vec[i][4]);
        under_vec.push_back(QString("%1").arg(goods[2]));
        res.push_back(under_vec);
    }
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(res[i][j]));
            ui->tableWidget->setItem(i,j, itm);
            if(j == 0)
            {
                addCheckBoxAt(i, 8,"Принять");
                addCheckBoxAt(i, 9,"Отказать");
            }
        }

    }
    ui->tableWidget->setColumnHidden(0, true);

}

void ProcessOrdersWindow::addCheckBoxAt(int row_number, int column_number, QString name)
{

    // Create a widget that will contain a checkbox
    // заполнение таблицы

         QTableWidgetItem *checkBoxItem = new QTableWidgetItem();
         checkBoxItem->setText(name);
         checkBoxItem->data(Qt::CheckStateRole);
         checkBoxItem->setCheckState(Qt::Unchecked);
         ui->tableWidget->setItem(row_number,column_number,checkBoxItem);
}

void ProcessOrdersWindow::on_pushButton_2_clicked()
{
    MainWindow *w = new MainWindow(this);
    this->close();
    w->show();
}

void ProcessOrdersWindow::on_pushButton_3_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){


            if (ui->tableWidget->item(i, 8)->checkState()==Qt::Checked) //принять
            {
                QString count_buy = ui->tableWidget->item(i, 4)->text(); // количество купленного
                QString id = ui->tableWidget->item(i, 1)->text(); //id товара
                QString id_order = ui->tableWidget->item(i, 0)->text(); //id заказа
                req_change_goods(id, count_buy);
                req_delete_orders(id_order);

            }
            if (ui->tableWidget->item(i, 9)->checkState()==Qt::Checked) //отказать
            {
                QString id = ui->tableWidget->item(i, 0)->text(); //id заказа
                req_delete_orders(id);
            }
    }

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Успешно");
    msgBox.setText("Изменения приняты");
    msgBox.exec();

}
