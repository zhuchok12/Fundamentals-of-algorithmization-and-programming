#include "mainwindow.h"
#include "movrect.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QGridLayout* pgrdLayout = new QGridLayout;

    QPushButton* pbch = new QPushButton ("Change active hand");
    QPushButton* pbcw1 = new QPushButton ("Cw");
    QPushButton* pbccw1 = new QPushButton ("Ccw");
    QPushButton* pbcw2 = new QPushButton ("Cw");
    QPushButton* pbccw2 = new QPushButton ("Ccw");
    QPushButton* pbcc = new QPushButton ("Change center of the rotation");
    QPushButton* pbr = new QPushButton ("Reset the position");

    MovRect* r = new MovRect();
    Signalman* s = new Signalman();

    pgrdLayout->addWidget(s, 0, 0, 1, 2);
    pgrdLayout->addWidget(r, 0, 2, 1, 2);
    pgrdLayout->addWidget(pbch, 1, 0, 1, 2);
    pgrdLayout->addWidget(pbcw1, 2, 0);
    pgrdLayout->addWidget(pbccw1, 2, 1);
    pgrdLayout->addWidget(pbcw2, 2, 2);
    pgrdLayout->addWidget(pbccw2, 2, 3);
    pgrdLayout->addWidget(pbcc, 1, 2);
    pgrdLayout->addWidget(pbr, 1, 3);

    w.setLayout(pgrdLayout);

    QObject::connect(pbcw2, SIGNAL(pressed()), r, SLOT(slotBeginCW()));
    QObject::connect(pbcw2, SIGNAL(released()), r, SLOT(slotEndCW()));
    QObject::connect(pbccw2, SIGNAL(pressed()), r, SLOT(slotBeginCntrCW()));
    QObject::connect(pbccw2, SIGNAL(released()), r, SLOT(slotEndCntrCW()));
    QObject::connect(pbcc, SIGNAL(released()), r, SLOT(slotChangeCenter()));
    QObject::connect(pbr, SIGNAL(released()), r, SLOT(slotReset()));

    QObject::connect(pbcw1, SIGNAL(pressed()), s, SLOT(slotBeginCW()));
    QObject::connect(pbcw1, SIGNAL(released()), s, SLOT(slotEndCW()));
    QObject::connect(pbccw1, SIGNAL(pressed()), s, SLOT(slotBeginCntrCW()));
    QObject::connect(pbccw1, SIGNAL(released()), s, SLOT(slotEndCntrCW()));
    QObject::connect(pbch, SIGNAL(released()), s, SLOT(slotChangeActiveHand()));

    w.show();
    return a.exec();
}
