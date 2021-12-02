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
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(count);
    for(int i = 0; i < count; i++)
    {
        QVector<QString> under_vec;
        QVector<QString> goods = get_data_at_id(vec[i][1].toInt());
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
        for(int j = 0; j < 6; j++)
        {
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(res[i][j]));
            ui->tableWidget->setItem(i,j, itm);
            if(j == 0)
            {
                addCheckBoxAt(i, 6,0,"Принять");
                addCheckBoxAt(i, 7,0,"Отказать");
            }
        }

    }
}

void ProcessOrdersWindow::addCheckBoxAt(int row_number, int column_number, int state, QString name)
{

    // Create a widget that will contain a checkbox
     QWidget *checkBoxWidget = new QWidget();
     QCheckBox *checkBox = new QCheckBox();      // We declare and initialize the checkbox
     checkBox->setText(name);
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
