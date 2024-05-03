/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSpinBox *spinBox_m;
    QSpinBox *spinBox_n;
    QPushButton *pushButton_ack;
    QLabel *label_answer;
    QLabel *label_answer_label;
    QLabel *label_m;
    QLabel *label_n;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        spinBox_m = new QSpinBox(centralwidget);
        spinBox_m->setObjectName(QString::fromUtf8("spinBox_m"));
        spinBox_m->setGeometry(QRect(80, 60, 42, 22));
        spinBox_n = new QSpinBox(centralwidget);
        spinBox_n->setObjectName(QString::fromUtf8("spinBox_n"));
        spinBox_n->setGeometry(QRect(160, 60, 42, 22));
        pushButton_ack = new QPushButton(centralwidget);
        pushButton_ack->setObjectName(QString::fromUtf8("pushButton_ack"));
        pushButton_ack->setGeometry(QRect(220, 60, 100, 32));
        label_answer = new QLabel(centralwidget);
        label_answer->setObjectName(QString::fromUtf8("label_answer"));
        label_answer->setGeometry(QRect(100, 110, 341, 16));
        label_answer_label = new QLabel(centralwidget);
        label_answer_label->setObjectName(QString::fromUtf8("label_answer_label"));
        label_answer_label->setGeometry(QRect(30, 110, 58, 16));
        label_m = new QLabel(centralwidget);
        label_m->setObjectName(QString::fromUtf8("label_m"));
        label_m->setGeometry(QRect(60, 60, 21, 16));
        label_n = new QLabel(centralwidget);
        label_n->setObjectName(QString::fromUtf8("label_n"));
        label_n->setGeometry(QRect(140, 60, 16, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_ack->setText(QCoreApplication::translate("MainWindow", "Ackermann", nullptr));
        label_answer->setText(QString());
        label_answer_label->setText(QCoreApplication::translate("MainWindow", "Answer: ", nullptr));
        label_m->setText(QCoreApplication::translate("MainWindow", "m:", nullptr));
        label_n->setText(QCoreApplication::translate("MainWindow", "n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
