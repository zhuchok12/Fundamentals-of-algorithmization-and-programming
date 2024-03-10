#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dyarray_data.h"
#include "data.h"
#include <QThread>
#include <QTableWidgetItem>
#include <QShortcut>
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <string>

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
    void ShowTable();
    void Today();
private slots:
    void on_OpenFileButton_clicked();

    void on_DateOfBirthday_textChanged();

    void on_Table_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    dyarray *data=new dyarray;
    Date birthday;
    Date current;
    QString file="";
    Date t;
    QShortcut *ctrlo;
    bool showing;
    std::string s;
    char ch;
};
#endif // MAINWINDOW_H
