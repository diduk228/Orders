#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QModelIndex>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // Слот для записи скриншота в базу данных
    void on_screenButton_clicked();
    // Слот для получения изображения из базы данных
    void slotCurrentPic(QModelIndex index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel  *model;

private:
    /* Также присутствуют два метода, которые формируют модель
     * и внешний вид TableView
     * */
    void setupModel(QStringList &headers,QString tableName);
    void createUI();
};

#endif // MAINWINDOW_H
