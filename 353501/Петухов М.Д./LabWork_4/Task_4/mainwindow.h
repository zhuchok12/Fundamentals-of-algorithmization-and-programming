#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QGraphicsRectItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
  
    Q_OBJECT

public: 
  MainWindow();
protected:
  Ui::MainWindow *ui;
};