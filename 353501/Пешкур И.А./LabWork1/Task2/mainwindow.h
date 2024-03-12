#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figure.h"
#include "hexagon.h"

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

private:

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Figure* figure;
    void putHexagon();
    void setValue();

private slots:
    void change_figure( int currentIndex );
};
#endif // MAINWINDOW_H
