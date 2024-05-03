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
    QLabel *label_enter_number;
    QLabel *label_inverted_num;
    QLabel *label_answer;
    QPushButton *pushButton_result;
    QSpinBox *spinBox_number;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_enter_number = new QLabel(centralwidget);
        label_enter_number->setObjectName(QString::fromUtf8("label_enter_number"));
        label_enter_number->setGeometry(QRect(40, 20, 91, 16));
        label_inverted_num = new QLabel(centralwidget);
        label_inverted_num->setObjectName(QString::fromUtf8("label_inverted_num"));
        label_inverted_num->setGeometry(QRect(40, 70, 111, 16));
        label_answer = new QLabel(centralwidget);
        label_answer->setObjectName(QString::fromUtf8("label_answer"));
        label_answer->setGeometry(QRect(170, 70, 161, 16));
        pushButton_result = new QPushButton(centralwidget);
        pushButton_result->setObjectName(QString::fromUtf8("pushButton_result"));
        pushButton_result->setGeometry(QRect(310, 20, 100, 32));
        spinBox_number = new QSpinBox(centralwidget);
        spinBox_number->setObjectName(QString::fromUtf8("spinBox_number"));
        spinBox_number->setGeometry(QRect(150, 20, 141, 21));
        spinBox_number->setMaximum(1000000000);
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
        label_enter_number->setText(QCoreApplication::translate("MainWindow", "Enter number:", nullptr));
        label_inverted_num->setText(QCoreApplication::translate("MainWindow", "Inverted number:", nullptr));
        label_answer->setText(QString());
        pushButton_result->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
