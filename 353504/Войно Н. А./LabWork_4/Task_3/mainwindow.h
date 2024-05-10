#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QVector>
#include <algorithm>

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

    void calculateMedians();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void printA();

private:
    Ui::MainWindow *ui;
    int sizeOfArray;
    QVector<int> a;
    QVector<int> temp;
    QVector<int> b;

    bool calculated;
    bool generated;


};
#endif // MAINWINDOW_H
