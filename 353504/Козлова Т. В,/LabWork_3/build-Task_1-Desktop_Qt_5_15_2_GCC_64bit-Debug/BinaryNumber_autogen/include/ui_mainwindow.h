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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_enter_number;
    QLabel *label_answer;
    QLabel *label_answer_text;
    QPushButton *pushButton_convert;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(150, 20, 91, 22));
        doubleSpinBox->setMinimum(-150.000000000000000);
        doubleSpinBox->setMaximum(150.000000000000000);
        label_enter_number = new QLabel(centralwidget);
        label_enter_number->setObjectName(QString::fromUtf8("label_enter_number"));
        label_enter_number->setGeometry(QRect(37, 20, 91, 20));
        label_answer = new QLabel(centralwidget);
        label_answer->setObjectName(QString::fromUtf8("label_answer"));
        label_answer->setGeometry(QRect(40, 60, 58, 16));
        label_answer_text = new QLabel(centralwidget);
        label_answer_text->setObjectName(QString::fromUtf8("label_answer_text"));
        label_answer_text->setGeometry(QRect(140, 60, 271, 16));
        pushButton_convert = new QPushButton(centralwidget);
        pushButton_convert->setObjectName(QString::fromUtf8("pushButton_convert"));
        pushButton_convert->setGeometry(QRect(270, 30, 100, 32));
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
        label_answer->setText(QCoreApplication::translate("MainWindow", "Answer:", nullptr));
        label_answer_text->setText(QString());
        pushButton_convert->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
