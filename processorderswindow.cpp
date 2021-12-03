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
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setRowCount(count);
    for(int i = 0; i < count; i++)
    {
        QVector<QString> under_vec;
        QVector<QString> goods = get_data_at_id(vec[i][1].toInt());
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
        for(int j = 0; j < 7; j++)
        {
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(res[i][j]));
            ui->tableWidget->setItem(i,j, itm);
            if(j == 0)
            {
                addCheckBoxAt(i, 7,"Принять");
                addCheckBoxAt(i, 8,"Отказать");
            }
        }

    }
    addCheckBoxAt(count, 7,"Принять");
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



     // Another way to add check box as item
    /*

   // QTableWidgetItem *checkBoxItem = new QTableWidgetItem("checkbox string ");
    QTableWidgetItem *checkBoxItem = new QTableWidgetItem();
    checkBoxItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    checkBoxItem->setCheckState(Qt::Checked);
    ui->job_table_view->setItem(row_number,column_number,checkBoxItem);

    */
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


            if (ui->tableWidget->item(i, 7)->checkState()==Qt::Checked) //принять
            {
                QString count_buy = ui->tableWidget->item(i, 3)->text(); // количество купленного
                QString id = ui->tableWidget->item(i, 0)->text(); //id
                req_change_goods(id, count_buy);

            }
            /*
            QCheckBox* pCheckB2(qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i, 8))); //принять
            if(pCheckB2->isChecked())  // отказать
            {

            }*/
    }

}
