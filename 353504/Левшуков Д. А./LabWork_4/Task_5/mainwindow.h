#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pair.h"
//#include "iterator.h"
#include "myvector.cpp"
//#include "ebanoe_kazino.h"

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
    void show_matrix();

private:
    Ui::MainWindow *ui;
    vector<Pair<vector<int>, vector<Pair<int, double>>>> matrix;
    vector<int>f;
    vector<Pair<int,double>>s;
};
#endif // MAINWINDOW_H
