#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "order.h"
#include "courier.h"
#include <string>
#include <QFileDialog>
#include <QDialog>
#include <fstream>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void FileRead();
    bool ReadOrders(std::string);
    bool ReadCouriers(std::string);
    void FileSave();
    void Clear();
    void FileUpdate(long long pos, bool del);
    bool CheckCourierForm();
    void FileAdd(long long pos,std::string s);
    bool CheckOrderForm();
private slots:
    void on_OpenFileButton_clicked();

    void on_SaveFileButton_clicked();

    void on_DeleteCourierButton_clicked();

    void on_DeleteOrderButton_clicked();

    void on_CourierNumberSelect_currentIndexChanged(int index);

    void on_AddCourierButton_clicked();

    void on_ClearCourierForm_clicked();

    void on_ClearOrderForm_clicked();

    void on_OrderNumberSelect_currentIndexChanged(int index);

    void on_AddOrderButton_clicked();

    void on_EditCourierInfoButton_clicked();

    void on_EditOrderInfoButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<courier>c;
    courier c_from_form;
    order o_from_form;
    QVector<order>o;
    QVector<std::pair<long long,long long>>order_position_in_file,courier_position_in_file;
    QVector<QString>select_orders,select_couriers;
    std::string file,orders_in_file,couriers_in_file;
    QShortcut *ctrlo,*ctrls;
    const std::string orders_head="------=======Orders=======------",couriers_head="------=======Couriers=======------";
};
#endif // MAINWINDOW_H
