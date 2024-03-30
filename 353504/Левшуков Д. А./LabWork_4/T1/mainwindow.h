#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sort.h"
#include "graph.h"
#include <QMessageBox>

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

    bool check(std::string s);
    void delar();
    void add(int ch);
    void paintEvent(QPaintEvent *event);

private slots:
    void on_sortButton_clicked();

private:
    Ui::MainWindow *ui;
    int *a=nullptr;
    long long siz=0;
    Graph g;
};
#endif // MAINWINDOW_H
