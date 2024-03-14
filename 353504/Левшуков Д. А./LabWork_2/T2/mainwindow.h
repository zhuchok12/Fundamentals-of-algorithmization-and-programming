#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "order.h"
#include "courier.h"
#include <string>
#include <QFileDialog>
#include <QDialog>

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

private slots:
    void on_OpenFileButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<courier>c;
    QVector<order>o;
    QVector<std::string>id;
    std::string file;
};
#endif // MAINWINDOW_H
