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
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(ids.size());
    for(int i = 0; i < ids.size(); i++)
    {
        QVector<QString> vec =  get_data_at_id(ids[i].toInt());
        QVector<QString> under;
        under.push_back(vec[0]);
        under.push_back(vec[1]);
        under.push_back(vec[2]);
        under.push_back(vec[3]);
        res.push_back(under);
    }
    for(int i = 0; i < ids.size(); i++)
    {
        for(int j = 0; j < 4; j++) {

            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(res[i][j]));
            ui->tableWidget->setItem(i,j, itm);
            if(j == 0)
            {
                addCheckBoxAt(i, 4,0);
            }
        }

    }
}

void MenuBasket::addCheckBoxAt(int row_number, int column_number,int state)
{

    // Create a widget that will contain a checkbox
     QWidget *checkBoxWidget = new QWidget();
     QCheckBox *checkBox = new QCheckBox();      // We declare and initialize the checkbox
     checkBox->setText("Выбрать");
     QHBoxLayout *layoutCheckBox = new QHBoxLayout(checkBoxWidget); // create a layer with reference to the widget
     layoutCheckBox->addWidget(checkBox);            // Set the checkbox in the layer
     layoutCheckBox->setAlignment(Qt::AlignCenter);  // Center the checkbox
     layoutCheckBox->setContentsMargins(0,0,0,0);    // Set the zero padding
     /* Check on the status of odd if an odd device,
       * exhibiting state of the checkbox in the Checked, Unchecked otherwise
       * */

      if(state == 1){
          checkBox->setChecked(true);
      } else {
          checkBox->setChecked(false);
      }
      ui->tableWidget->setCellWidget(row_number,column_number, checkBoxWidget);


     // Another way to add check box as item
    /*

   // QTableWidgetItem *checkBoxItem = new QTableWidgetItem("checkbox string ");
    QTableWidgetItem *checkBoxItem = new QTableWidgetItem();
    checkBoxItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    checkBoxItem->setCheckState(Qt::Checked);
    ui->job_table_view->setItem(row_number,column_number,checkBoxItem);

    */
}

void MenuBasket::on_return_to_menu_clicked()
{
    MainWindow *w = new MainWindow(this);
    this->close();
    w->show();
}
