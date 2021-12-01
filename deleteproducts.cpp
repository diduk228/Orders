#include "deleteproducts.h"
#include "ui_deleteproducts.h"

DeleteProducts::DeleteProducts(QWidget *parent) :
    BaseData(parent),
    ui(new Ui::DeleteProducts)
{
    ui->setupUi(this);
    init_table();
}

DeleteProducts::~DeleteProducts()
{
    delete ui;
}

void DeleteProducts::init_table()
{
    int count =  get_count_products();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(count);
    QVector<QVector<QString>> vec =  get_all();
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(vec[i][j]));
            ui->tableWidget->setItem(i,j, itm);
            if(j == 0)
            {
                addCheckBoxAt(i, 4,0);
            }
        }

    }
}

void DeleteProducts::addCheckBoxAt(int row_number, int column_number,int state)
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

void DeleteProducts::on_pushButton_clicked()
{
    MainWindow *w = new MainWindow(this);
    this->close();
    w->show();
}
