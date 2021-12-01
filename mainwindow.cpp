#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_process_products_2_triggered()
{
    ProcessOrdersWindow *pro = new ProcessOrdersWindow(this);
    this->close();
    pro->show();
}

void MainWindow::on_delete_products_triggered()
{
    DeleteProducts *del = new DeleteProducts(this);
    this->close();
    del->show();
}

void MainWindow::on_add_goods_triggered()
{
    AddGoods *add = new AddGoods(this);
    this->close();
    add->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    MenuBasket *add = new MenuBasket(this);
    this->close();
    add->show();
}

void MainWindow::init_table()
{
    int count =  get_count_products();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(count);
    QVector<QVector<QString>> vec =  get_all();
    for(int i = 0; i < count; i++)
    {
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(vec[i][1]));
            ui->tableWidget->setItem(i,0, itm);
            addBtnAt(i, 1);

    }
}

void MainWindow::addBtnAt(int row_number, int column_number)
{
    // Create a widget that will contain a checkbox
     QWidget *checkBoxWidget = new QWidget();
     QPushButton *quitBtn = new QPushButton();      // We declare and initialize the checkbox
     quitBtn->setText("Выбрать");
     QHBoxLayout *layoutCheckBox = new QHBoxLayout(checkBoxWidget); // create a layer with reference to the widget
     layoutCheckBox->addWidget(quitBtn);            // Set the checkbox in the layer
     layoutCheckBox->setAlignment(Qt::AlignCenter);  // Center the checkbox
     layoutCheckBox->setContentsMargins(0,0,0,0);    // Set the zero padding
     /* Check on the status of odd if an odd device,
       * exhibiting state of the checkbox in the Checked, Unchecked otherwise
       * */


      ui->tableWidget->setCellWidget(row_number,column_number, checkBoxWidget);
}
