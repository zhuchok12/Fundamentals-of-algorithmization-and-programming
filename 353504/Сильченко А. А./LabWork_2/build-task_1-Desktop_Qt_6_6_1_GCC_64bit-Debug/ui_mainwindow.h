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
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QLineEdit *line_main_date;
    QPushButton *pushButton_set_date;
    QGroupBox *groupBox;
    QPushButton *pushButton_Save_to_File;
    QLabel *label_SaveFileMessage;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *on_buttonCreateSave_clicked;
    QPushButton *on_buttonCreateAdd_clicked;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_day;
    QLabel *label_month;
    QLabel *label_year;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *line_create_day;
    QLineEdit *line_create_month;
    QLineEdit *line_create_year;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_next_day;
    QLabel *label_prev_day;
    QLabel *label_is_leap;
    QLabel *label_week_num;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_next_date;
    QLabel *label_prev_date;
    QLabel *label_leap_date;
    QLabel *label_week_date;
    QPushButton *pushAlarm;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 290, 341, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 90, 351, 41));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 10, 111, 16));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(390, 270, 391, 271));
        line_main_date = new QLineEdit(centralwidget);
        line_main_date->setObjectName("line_main_date");
        line_main_date->setGeometry(QRect(570, 10, 113, 21));
        pushButton_set_date = new QPushButton(centralwidget);
        pushButton_set_date->setObjectName("pushButton_set_date");
        pushButton_set_date->setGeometry(QRect(440, 40, 131, 31));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 401, 251));
        pushButton_Save_to_File = new QPushButton(groupBox);
        pushButton_Save_to_File->setObjectName("pushButton_Save_to_File");
        pushButton_Save_to_File->setGeometry(QRect(100, 30, 181, 32));
        label_SaveFileMessage = new QLabel(groupBox);
        label_SaveFileMessage->setObjectName("label_SaveFileMessage");
        label_SaveFileMessage->setGeometry(QRect(0, 240, 391, 31));
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 189, 401, 91));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        on_buttonCreateSave_clicked = new QPushButton(horizontalLayoutWidget_2);
        on_buttonCreateSave_clicked->setObjectName("on_buttonCreateSave_clicked");

        horizontalLayout_2->addWidget(on_buttonCreateSave_clicked);

        on_buttonCreateAdd_clicked = new QPushButton(horizontalLayoutWidget_2);
        on_buttonCreateAdd_clicked->setObjectName("on_buttonCreateAdd_clicked");

        horizontalLayout_2->addWidget(on_buttonCreateAdd_clicked);

        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 90, 381, 91));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_day = new QLabel(horizontalLayoutWidget_3);
        label_day->setObjectName("label_day");

        verticalLayout_3->addWidget(label_day);

        label_month = new QLabel(horizontalLayoutWidget_3);
        label_month->setObjectName("label_month");

        verticalLayout_3->addWidget(label_month);

        label_year = new QLabel(horizontalLayoutWidget_3);
        label_year->setObjectName("label_year");

        verticalLayout_3->addWidget(label_year);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        line_create_day = new QLineEdit(horizontalLayoutWidget_3);
        line_create_day->setObjectName("line_create_day");

        verticalLayout_4->addWidget(line_create_day);

        line_create_month = new QLineEdit(horizontalLayoutWidget_3);
        line_create_month->setObjectName("line_create_month");

        verticalLayout_4->addWidget(line_create_month);

        line_create_year = new QLineEdit(horizontalLayoutWidget_3);
        line_create_year->setObjectName("line_create_year");

        verticalLayout_4->addWidget(line_create_year);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(440, 100, 301, 151));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_next_day = new QLabel(horizontalLayoutWidget);
        label_next_day->setObjectName("label_next_day");

        verticalLayout->addWidget(label_next_day);

        label_prev_day = new QLabel(horizontalLayoutWidget);
        label_prev_day->setObjectName("label_prev_day");

        verticalLayout->addWidget(label_prev_day);

        label_is_leap = new QLabel(horizontalLayoutWidget);
        label_is_leap->setObjectName("label_is_leap");

        verticalLayout->addWidget(label_is_leap);

        label_week_num = new QLabel(horizontalLayoutWidget);
        label_week_num->setObjectName("label_week_num");

        verticalLayout->addWidget(label_week_num);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_next_date = new QLabel(horizontalLayoutWidget);
        label_next_date->setObjectName("label_next_date");

        verticalLayout_2->addWidget(label_next_date);

        label_prev_date = new QLabel(horizontalLayoutWidget);
        label_prev_date->setObjectName("label_prev_date");

        verticalLayout_2->addWidget(label_prev_date);

        label_leap_date = new QLabel(horizontalLayoutWidget);
        label_leap_date->setObjectName("label_leap_date");

        verticalLayout_2->addWidget(label_leap_date);

        label_week_date = new QLabel(horizontalLayoutWidget);
        label_week_date->setObjectName("label_week_date");

        verticalLayout_2->addWidget(label_week_date);


        horizontalLayout->addLayout(verticalLayout_2);

        pushAlarm = new QPushButton(centralwidget);
        pushAlarm->setObjectName("pushAlarm");
        pushAlarm->setGeometry(QRect(70, 530, 231, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(45, 336, 331, 181));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 360, 291, 20));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\264\320\260\321\202\320\260:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264. \320\264\320\265\320\275\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264. \320\264\320\265\320\275\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\275\320\270\321\206\320\260 ", nullptr));
        pushButton_set_date->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\260\321\202\321\203", nullptr));
        groupBox->setTitle(QString());
        pushButton_Save_to_File->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        label_SaveFileMessage->setText(QString());
        on_buttonCreateSave_clicked->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        on_buttonCreateAdd_clicked->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_day->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\275\321\214", nullptr));
        label_month->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        label_year->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\320\264", nullptr));
        label_next_day->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", nullptr));
        label_prev_day->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", nullptr));
        label_is_leap->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\201\320\276\320\272\320\276\321\201\320\275\321\213\320\271", nullptr));
        label_week_num->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        label_next_date->setText(QString());
        label_prev_date->setText(QString());
        label_leap_date->setText(QString());
        label_week_date->setText(QString());
        pushAlarm->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\266\320\260\321\202\321\214, \320\272\320\276\320\263\320\264\320\260 \320\262\321\201\321\221 \320\277\320\273\320\276\321\205\320\276", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
