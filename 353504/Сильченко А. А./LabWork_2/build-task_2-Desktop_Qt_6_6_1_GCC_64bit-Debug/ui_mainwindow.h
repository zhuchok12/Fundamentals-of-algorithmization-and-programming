/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLabel *label_SaveFileMessage;
    QGroupBox *groupBox;
    QPushButton *buttonCreateAdd;
    QLabel *label_Id;
    QPushButton *buttonCreateSave;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *line_create_author;
    QLineEdit *line_create_bookName;
    QLineEdit *line_create_companyName;
    QLineEdit *line_create_bookYear;
    QLineEdit *line_create_pageQuantity;
    QLineEdit *line_create_pageQuantity_2;
    QLabel *label_8;
    QPushButton *pushAlarm;
    QLabel *label_9;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_Save;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *line_search;
    QPushButton *search_button;
    QPushButton *sort_year;
    QLabel *label;
    QComboBox *comboBox_Company;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(180, 320, 611, 231));
        label_SaveFileMessage = new QLabel(centralwidget);
        label_SaveFileMessage->setObjectName("label_SaveFileMessage");
        label_SaveFileMessage->setGeometry(QRect(0, 290, 281, 16));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 421, 261));
        buttonCreateAdd = new QPushButton(groupBox);
        buttonCreateAdd->setObjectName("buttonCreateAdd");
        buttonCreateAdd->setGeometry(QRect(280, 160, 100, 32));
        label_Id = new QLabel(groupBox);
        label_Id->setObjectName("label_Id");
        label_Id->setGeometry(QRect(310, 50, 21, 21));
        buttonCreateSave = new QPushButton(groupBox);
        buttonCreateSave->setObjectName("buttonCreateSave");
        buttonCreateSave->setGeometry(QRect(280, 110, 100, 32));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 13, 251, 221));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        line_create_author = new QLineEdit(horizontalLayoutWidget);
        line_create_author->setObjectName("line_create_author");

        verticalLayout_2->addWidget(line_create_author);

        line_create_bookName = new QLineEdit(horizontalLayoutWidget);
        line_create_bookName->setObjectName("line_create_bookName");

        verticalLayout_2->addWidget(line_create_bookName);

        line_create_companyName = new QLineEdit(horizontalLayoutWidget);
        line_create_companyName->setObjectName("line_create_companyName");

        verticalLayout_2->addWidget(line_create_companyName);

        line_create_bookYear = new QLineEdit(horizontalLayoutWidget);
        line_create_bookYear->setObjectName("line_create_bookYear");

        verticalLayout_2->addWidget(line_create_bookYear);

        line_create_pageQuantity = new QLineEdit(horizontalLayoutWidget);
        line_create_pageQuantity->setObjectName("line_create_pageQuantity");

        verticalLayout_2->addWidget(line_create_pageQuantity);

        line_create_pageQuantity_2 = new QLineEdit(horizontalLayoutWidget);
        line_create_pageQuantity_2->setObjectName("line_create_pageQuantity_2");

        verticalLayout_2->addWidget(line_create_pageQuantity_2);


        horizontalLayout->addLayout(verticalLayout_2);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(25, 246, 251, 261));
        pushAlarm = new QPushButton(centralwidget);
        pushAlarm->setObjectName("pushAlarm");
        pushAlarm->setGeometry(QRect(0, 520, 171, 25));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 280, 301, 41));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(290, 280, 501, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_Save = new QPushButton(horizontalLayoutWidget_2);
        pushButton_Save->setObjectName("pushButton_Save");

        horizontalLayout_2->addWidget(pushButton_Save);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(440, 10, 351, 261));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        line_search = new QLineEdit(verticalLayoutWidget_3);
        line_search->setObjectName("line_search");

        horizontalLayout_3->addWidget(line_search);

        search_button = new QPushButton(verticalLayoutWidget_3);
        search_button->setObjectName("search_button");

        horizontalLayout_3->addWidget(search_button);


        verticalLayout_3->addLayout(horizontalLayout_3);

        sort_year = new QPushButton(verticalLayoutWidget_3);
        sort_year->setObjectName("sort_year");

        verticalLayout_3->addWidget(sort_year);

        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        comboBox_Company = new QComboBox(verticalLayoutWidget_3);
        comboBox_Company->setObjectName("comboBox_Company");

        verticalLayout_3->addWidget(comboBox_Company);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\321\202\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\265\321\201\321\201\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\260\321\200\321\202\320\270\320\270", nullptr));
        label_SaveFileMessage->setText(QString());
        groupBox->setTitle(QString());
        buttonCreateAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_Id->setText(QString());
        buttonCreateSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\321\202\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\265\321\201\321\201\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\276\320\272\321\200\321\203\320\263\320\260", nullptr));
        label_8->setText(QString());
        pushAlarm->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\266\320\260\321\202\321\214, \320\272\320\276\320\263\320\264\320\260 \320\262\321\201\321\221 \320\277\320\273\320\276\321\205\320\276", nullptr));
        label_9->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        pushButton_Save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        search_button->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\272\320\260\321\202\321\214", nullptr));
        sort_year->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\321\203", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\321\200\320\276\321\204\320\265\321\201\321\201\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
