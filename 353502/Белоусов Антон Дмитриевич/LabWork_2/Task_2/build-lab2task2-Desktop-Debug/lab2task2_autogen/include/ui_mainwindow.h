/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *open_button;
    QPushButton *save_button;
    QPushButton *addGroup_textEdit;
    QTextEdit *newGroup_textEdit;
    QComboBox *group_comboBox;
    QTextEdit *code_textEdit;
    QLabel *label_2;
    QLabel *label_4;
    QTextEdit *price_textEdit;
    QLabel *label_3;
    QLabel *label_5;
    QTextEdit *name_textEdit;
    QTextEdit *quantity_textEdit;
    QLabel *label;
    QTextEdit *less_then_textEdit;
    QPushButton *add_button;
    QTextEdit *find_with_textEdit;
    QPushButton *find_with_button;
    QPushButton *less_then_button;
    QPushButton *sort_button;
    QPushButton *endEdit_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(240, 10, 511, 471));
        open_button = new QPushButton(centralwidget);
        open_button->setObjectName(QString::fromUtf8("open_button"));
        open_button->setGeometry(QRect(690, 500, 88, 31));
        save_button = new QPushButton(centralwidget);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setGeometry(QRect(580, 500, 88, 31));
        addGroup_textEdit = new QPushButton(centralwidget);
        addGroup_textEdit->setObjectName(QString::fromUtf8("addGroup_textEdit"));
        addGroup_textEdit->setGeometry(QRect(440, 500, 88, 31));
        newGroup_textEdit = new QTextEdit(centralwidget);
        newGroup_textEdit->setObjectName(QString::fromUtf8("newGroup_textEdit"));
        newGroup_textEdit->setGeometry(QRect(240, 499, 181, 31));
        group_comboBox = new QComboBox(centralwidget);
        group_comboBox->setObjectName(QString::fromUtf8("group_comboBox"));
        group_comboBox->setGeometry(QRect(106, 76, 123, 25));
        code_textEdit = new QTextEdit(centralwidget);
        code_textEdit->setObjectName(QString::fromUtf8("code_textEdit"));
        code_textEdit->setGeometry(QRect(106, 178, 123, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 178, 35, 28));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 76, 42, 25));
        price_textEdit = new QTextEdit(centralwidget);
        price_textEdit->setObjectName(QString::fromUtf8("price_textEdit"));
        price_textEdit->setGeometry(QRect(106, 230, 123, 29));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 125, 60, 29));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 23, 40, 29));
        name_textEdit = new QTextEdit(centralwidget);
        name_textEdit->setObjectName(QString::fromUtf8("name_textEdit"));
        name_textEdit->setGeometry(QRect(106, 23, 123, 29));
        quantity_textEdit = new QTextEdit(centralwidget);
        quantity_textEdit->setObjectName(QString::fromUtf8("quantity_textEdit"));
        quantity_textEdit->setGeometry(QRect(106, 125, 123, 29));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 230, 34, 29));
        less_then_textEdit = new QTextEdit(centralwidget);
        less_then_textEdit->setObjectName(QString::fromUtf8("less_then_textEdit"));
        less_then_textEdit->setGeometry(QRect(106, 452, 123, 31));
        add_button = new QPushButton(centralwidget);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setGeometry(QRect(20, 280, 80, 31));
        find_with_textEdit = new QTextEdit(centralwidget);
        find_with_textEdit->setObjectName(QString::fromUtf8("find_with_textEdit"));
        find_with_textEdit->setGeometry(QRect(106, 410, 123, 31));
        find_with_button = new QPushButton(centralwidget);
        find_with_button->setObjectName(QString::fromUtf8("find_with_button"));
        find_with_button->setGeometry(QRect(20, 410, 80, 31));
        less_then_button = new QPushButton(centralwidget);
        less_then_button->setObjectName(QString::fromUtf8("less_then_button"));
        less_then_button->setGeometry(QRect(20, 452, 80, 31));
        sort_button = new QPushButton(centralwidget);
        sort_button->setObjectName(QString::fromUtf8("sort_button"));
        sort_button->setGeometry(QRect(20, 490, 80, 31));
        endEdit_button = new QPushButton(centralwidget);
        endEdit_button->setObjectName(QString::fromUtf8("endEdit_button"));
        endEdit_button->setGeometry(QRect(150, 280, 80, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Group", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        open_button->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        save_button->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        addGroup_textEdit->setText(QCoreApplication::translate("MainWindow", "Add group", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Group", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        add_button->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        find_with_button->setText(QCoreApplication::translate("MainWindow", "Find with", nullptr));
        less_then_button->setText(QCoreApplication::translate("MainWindow", "Less then", nullptr));
        sort_button->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        endEdit_button->setText(QCoreApplication::translate("MainWindow", "End edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
