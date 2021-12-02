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


void MainWindow::init_table()
{
    int count =  get_count_products();
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(count);
    QVector<QVector<QString>> vec =  get_all();
    for(int i = 0; i < count; i++)
    {
            QTableWidgetItem *itm2 = new QTableWidgetItem(tr("%1").arg(vec[i][0]));
            ui->tableWidget->setItem(i,0, itm2);
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(vec[i][1]));
            ui->tableWidget->setItem(i,1, itm);
            addBtnAt(i, 2);

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

      connect( quitBtn, SIGNAL( clicked() ), SLOT( onBtnClicked() ) );
      ui->tableWidget->setCellWidget(row_number,column_number, checkBoxWidget);
}

void MainWindow::on_go_to_basket_clicked()
{
    MenuBasket *add = new MenuBasket(ids, this);
    this->close();
    add->show();
}

void MainWindow::onBtnClicked()
{
     if( QPushButton* btn = qobject_cast< QPushButton* >( sender() ) )
     {
         QModelIndex index = ui->tableWidget->indexAt( btn->parentWidget()->pos() );
         QTableWidgetItem *item = ui->tableWidget->item(index.row(), index.column()-2);
         m_current_product_id = item->text();
     }
}

void MainWindow::on_add_to_basket_clicked()
{
    if (std::find(ids.begin(), ids.end(), m_current_product_id) == m_current_product_id) return;
    ids.push_back(m_current_product_id);
}

void MainWindow::save_settings()
{
    QTextStream out(stdout);

    // Создаем объект класса QFile и связываем его с указанным именем файла
    QString filename = "C:\\Users\\danil\\Documents\\maket\\Orders\\Settings\\mainwindow.txt";
    QFile file(filename);

    // Открываем файл в режиме "Только для записи"
    if (file.open(QIODevice::WriteOnly)) {
      QTextStream out(&file); // поток записываемых данных направляем в файл

      for(int i = 0; i < ids.length(); i++)
          out << ids[i] << "\n";
      out << m_current_product_id;

    } else {

      qWarning("Could not open file");
    }

    // Закрываем файл
    file.close();
}
