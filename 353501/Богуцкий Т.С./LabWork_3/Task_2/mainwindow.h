#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "ackermann.h"

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

private slots:
    void calculateRes();

protected:
    Ui::MainWindow *ui;
};
