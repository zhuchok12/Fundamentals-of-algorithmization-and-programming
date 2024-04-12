#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //Pair<Vector<int>,int> v;
    //Vector<std::string>* abc = new Vector<std::string>[1]();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
