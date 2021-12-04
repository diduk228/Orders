#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_ids();
    init_table();
    set_cucki();
    if(get_mod() == "Order")
    {
        ui->menu_2->menuAction()->setVisible(false);
    }
}

MainWindow::~MainWindow()
{
    //save_settings();
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
    save_ids();
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
         get_picture(m_current_product_id.toInt());
         QString pic = get_picture(m_current_product_id.toInt());
         QPixmap pixmap(pic);
         ui->picture->setPixmap(pixmap);
     }
     save_current();
}

void MainWindow::on_add_to_basket_clicked()
{
    set_current();
    //set_ids();
    for(int i = 0; i < ids.length(); i++)
        if ( ids[i] == m_current_product_id ) return;
    ids.push_back(m_current_product_id);
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Успешно");
    msgBox.setText("Товар добавлен в корзину!");
    msgBox.exec();
}

void MainWindow::save_ids()
{
    QTextStream out(stdout);

    // Создаем объект класса QFile и связываем его с указанным именем файла
    QString filename = "C:\\Users\\danil\\Documents\\maket\\Orders\\Settings\\mainwindow_ids.txt";
    QFile file(filename);

    // Открываем файл в режиме "Только для записи"
    if (file.open(QIODevice::WriteOnly)) {
      QTextStream out(&file); // поток записываемых данных направляем в файл
      out << ids.length() << "\n";
      for(int i = 0; i < ids.length(); i++)
          out << ids[i] << "\n";
    } else {

      qWarning("Could not open file");
    }
    // Закрываем файл
    file.close();
}

void MainWindow::set_ids()
{

    // Создаем объект
    QFile file("C:\\Users\\danil\\Documents\\maket\\Orders\\Settings\\mainwindow_ids.txt");

    // С помощью метода open() открываем файл в режиме чтения
    if (!file.open(QIODevice::ReadOnly)) {
      qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
      return;
    }

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(&file);
    // Считываем файл строка за строкой
    int size = in.readLine().toInt();
    for(int i = 0; i < size; i++) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
      QString line = in.readLine(); // метод readLine() считывает одну строку из потока
       ids.push_back(line);
    }

    // Закрываем файл
    file.close();
}

void MainWindow::save_current()
{
    QTextStream out(stdout);

    // Создаем объект класса QFile и связываем его с указанным именем файла
    QString filename = "C:\\Users\\danil\\Documents\\maket\\Orders\\Settings\\mainwindow_current.txt";
    QFile file(filename);

    // Открываем файл в режиме "Только для записи"
    if (file.open(QIODevice::WriteOnly)) {
      QTextStream out(&file); // поток записываемых данных направляем в файл
      if(!m_current_product_id.isEmpty())
        out << m_current_product_id;
      else
          out << -1;
    } else {

      qWarning("Could not open file");
    }
    // Закрываем файл
    file.close();
}

void MainWindow::set_current()
{

    // Создаем объект
    QFile file("C:\\Users\\danil\\Documents\\maket\\Orders\\Settings\\mainwindow_current.txt");

    // С помощью метода open() открываем файл в режиме чтения
    if (!file.open(QIODevice::ReadOnly)) {
      qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
      return;
    }

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(&file);
    QString cur = in.readLine();
    if(QString::compare(cur, "-1", Qt::CaseInsensitive))
    {
        m_current_product_id = cur;
    }

    // Закрываем файл
    file.close();
}

void MainWindow::on_buy_product_clicked()
{
    set_current();
    QVector<QString> data;
    data.push_back(m_current_product_id);  //id продукта
    data.push_back(ui->count_buy->text());                   //количество купленного товара
    QVector<QString> vec = get_data_at_id(m_current_product_id.toInt());
    data.push_back(vec[3]); //цена продукта
    data.push_back(QString::number(vec[3].toFloat() * ui->count_buy->text().toFloat())); // Цена продукта * количество купленного товара
    data.push_back(QString::number(get_id()));    // id user'a
    add_order(data);
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Успешно");
    msgBox.setText("Ваш заказ направлен на обработку!");
    msgBox.exec();
}

void MainWindow::on_delete_from_basket_clicked()
{
    set_current();
    QMutableVectorIterator<QString> i(ids);
    while(i.hasNext()) {

      QString currentValue=i.next();
      if(m_current_product_id==currentValue)
        i.remove();
    }

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Успешно");
    msgBox.setText("Данный товар удалён из корзины!");
    msgBox.exec();
}

void MainWindow::set_m_current_product_id(QString current)
{
    m_current_product_id = current;
}

Ui::MainWindow& MainWindow::get_ui_mainwindow()
{
    return *ui;
}
