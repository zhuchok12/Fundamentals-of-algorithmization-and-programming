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
    void ReadOrders(std::string);
    void ReadCouriers(std::string);
    void FileSave();
private slots:
    void on_OpenFileButton_clicked();

    void on_SaveFileButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<courier>c;
    QVector<order>o;
    QVector<std::string>id;
    QVector<QString>select_orders,select_couriers;
    std::string file,orders_in_file,couriers_in_file;
    QShortcut *ctrlo,*ctrls;
};
#endif // MAINWINDOW_H
