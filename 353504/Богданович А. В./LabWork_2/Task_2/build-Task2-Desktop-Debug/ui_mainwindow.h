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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QFrame *addFrame;
    QLabel *label;
    QLineEdit *fioAdd_line;
    QLabel *label_3;
    QLineEdit *specAdd_line;
    QLabel *label_4;
    QLineEdit *groupAdd_line;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *oaipAdd_spinBox;
    QSpinBox *maAdd_spinBox;
    QLabel *label_7;
    QSpinBox *agilaAdd_spinBox;
    QLabel *label_8;
    QSpinBox *mlAdd_spinBox;
    QLabel *label_9;
    QSpinBox *hisoryAdd_spinBox;
    QLabel *label_10;
    QPushButton *AddButton;
    QLabel *label_2;
    QLabel *label_11;
    QFrame *editFrame;
    QLabel *label_75;
    QLineEdit *fioEdit_line;
    QLabel *label_76;
    QLineEdit *specEdit_line;
    QLabel *label_77;
    QLineEdit *groupEdit_line;
    QLabel *label_78;
    QLabel *label_79;
    QSpinBox *oaipEdit_spinBox;
    QSpinBox *maEdit_spinBox;
    QLabel *label_80;
    QSpinBox *agilaEdit_spinBox;
    QLabel *label_81;
    QSpinBox *mlEdit_spinBOx;
    QLabel *label_82;
    QSpinBox *historyEdit_spinBox;
    QLabel *label_83;
    QPushButton *delete_button;
    QPushButton *edit_button;
    QComboBox *studentSelect_comboBox;
    QLabel *label_84;
    QFrame *frame;
    QLabel *label_85;
    QComboBox *selectGroup_comboBox;
    QPushButton *sort_button;
    QFrame *frame_2;
    QPushButton *openFile_button;
    QPushButton *saveFile_button;
    QFrame *frame_3;
    QPushButton *find_button;
    QLabel *label_95;
    QLineEdit *lineEdit;
    QFrame *frame_4;
    QLabel *label_96;
    QLabel *oaipLabel;
    QLabel *maLabel;
    QLabel *agilaLabel;
    QLabel *mlLabel;
    QLabel *historyLabel;
    QLabel *Group_Label;
    QLabel *Spec_Label;
    QLabel *Fio_Label;
    QLabel *AvMark_Label;
    QLabel *label_13;
    QPushButton *_createVed_button;
    QLabel *label_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1207, 860);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
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
        tableWidget->setGeometry(QRect(280, 60, 611, 421));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->horizontalHeader()->setDefaultSectionSize(152);
        addFrame = new QFrame(centralwidget);
        addFrame->setObjectName("addFrame");
        addFrame->setGeometry(QRect(10, 60, 251, 491));
        addFrame->setFrameShape(QFrame::StyledPanel);
        addFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(addFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 101, 17));
        fioAdd_line = new QLineEdit(addFrame);
        fioAdd_line->setObjectName("fioAdd_line");
        fioAdd_line->setGeometry(QRect(10, 40, 221, 25));
        label_3 = new QLabel(addFrame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 221, 17));
        specAdd_line = new QLineEdit(addFrame);
        specAdd_line->setObjectName("specAdd_line");
        specAdd_line->setGeometry(QRect(10, 100, 221, 25));
        label_4 = new QLabel(addFrame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 140, 221, 17));
        groupAdd_line = new QLineEdit(addFrame);
        groupAdd_line->setObjectName("groupAdd_line");
        groupAdd_line->setGeometry(QRect(10, 160, 221, 25));
        label_5 = new QLabel(addFrame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 200, 241, 17));
        label_6 = new QLabel(addFrame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 233, 66, 17));
        oaipAdd_spinBox = new QSpinBox(addFrame);
        oaipAdd_spinBox->setObjectName("oaipAdd_spinBox");
        oaipAdd_spinBox->setGeometry(QRect(150, 229, 44, 26));
        oaipAdd_spinBox->setMaximum(10);
        maAdd_spinBox = new QSpinBox(addFrame);
        maAdd_spinBox->setObjectName("maAdd_spinBox");
        maAdd_spinBox->setGeometry(QRect(150, 266, 44, 26));
        maAdd_spinBox->setMaximum(10);
        label_7 = new QLabel(addFrame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 270, 91, 17));
        agilaAdd_spinBox = new QSpinBox(addFrame);
        agilaAdd_spinBox->setObjectName("agilaAdd_spinBox");
        agilaAdd_spinBox->setGeometry(QRect(150, 306, 44, 26));
        agilaAdd_spinBox->setMaximum(10);
        label_8 = new QLabel(addFrame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 310, 91, 17));
        mlAdd_spinBox = new QSpinBox(addFrame);
        mlAdd_spinBox->setObjectName("mlAdd_spinBox");
        mlAdd_spinBox->setGeometry(QRect(150, 346, 44, 26));
        mlAdd_spinBox->setMaximum(10);
        label_9 = new QLabel(addFrame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 350, 91, 17));
        hisoryAdd_spinBox = new QSpinBox(addFrame);
        hisoryAdd_spinBox->setObjectName("hisoryAdd_spinBox");
        hisoryAdd_spinBox->setGeometry(QRect(150, 386, 44, 26));
        hisoryAdd_spinBox->setMaximum(10);
        label_10 = new QLabel(addFrame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 390, 91, 17));
        AddButton = new QPushButton(addFrame);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(20, 430, 201, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 141, 17));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(280, 30, 141, 17));
        editFrame = new QFrame(centralwidget);
        editFrame->setObjectName("editFrame");
        editFrame->setGeometry(QRect(910, 60, 251, 581));
        editFrame->setFrameShape(QFrame::StyledPanel);
        editFrame->setFrameShadow(QFrame::Raised);
        label_75 = new QLabel(editFrame);
        label_75->setObjectName("label_75");
        label_75->setGeometry(QRect(10, 54, 101, 17));
        fioEdit_line = new QLineEdit(editFrame);
        fioEdit_line->setObjectName("fioEdit_line");
        fioEdit_line->setGeometry(QRect(10, 74, 221, 25));
        label_76 = new QLabel(editFrame);
        label_76->setObjectName("label_76");
        label_76->setGeometry(QRect(10, 114, 221, 17));
        specEdit_line = new QLineEdit(editFrame);
        specEdit_line->setObjectName("specEdit_line");
        specEdit_line->setGeometry(QRect(10, 134, 221, 25));
        label_77 = new QLabel(editFrame);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(10, 174, 221, 17));
        groupEdit_line = new QLineEdit(editFrame);
        groupEdit_line->setObjectName("groupEdit_line");
        groupEdit_line->setGeometry(QRect(10, 194, 221, 25));
        label_78 = new QLabel(editFrame);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(10, 234, 241, 17));
        label_79 = new QLabel(editFrame);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(40, 267, 66, 17));
        oaipEdit_spinBox = new QSpinBox(editFrame);
        oaipEdit_spinBox->setObjectName("oaipEdit_spinBox");
        oaipEdit_spinBox->setGeometry(QRect(150, 263, 44, 26));
        oaipEdit_spinBox->setMaximum(10);
        maEdit_spinBox = new QSpinBox(editFrame);
        maEdit_spinBox->setObjectName("maEdit_spinBox");
        maEdit_spinBox->setGeometry(QRect(150, 300, 44, 26));
        maEdit_spinBox->setMaximum(10);
        label_80 = new QLabel(editFrame);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(40, 304, 91, 17));
        agilaEdit_spinBox = new QSpinBox(editFrame);
        agilaEdit_spinBox->setObjectName("agilaEdit_spinBox");
        agilaEdit_spinBox->setGeometry(QRect(150, 340, 44, 26));
        agilaEdit_spinBox->setMaximum(10);
        label_81 = new QLabel(editFrame);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(40, 344, 91, 17));
        mlEdit_spinBOx = new QSpinBox(editFrame);
        mlEdit_spinBOx->setObjectName("mlEdit_spinBOx");
        mlEdit_spinBOx->setGeometry(QRect(150, 380, 44, 26));
        mlEdit_spinBOx->setMaximum(10);
        label_82 = new QLabel(editFrame);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(40, 384, 91, 17));
        historyEdit_spinBox = new QSpinBox(editFrame);
        historyEdit_spinBox->setObjectName("historyEdit_spinBox");
        historyEdit_spinBox->setGeometry(QRect(150, 420, 44, 26));
        historyEdit_spinBox->setMaximum(10);
        label_83 = new QLabel(editFrame);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(40, 424, 91, 17));
        delete_button = new QPushButton(editFrame);
        delete_button->setObjectName("delete_button");
        delete_button->setGeometry(QRect(20, 520, 201, 41));
        edit_button = new QPushButton(editFrame);
        edit_button->setObjectName("edit_button");
        edit_button->setGeometry(QRect(20, 470, 201, 41));
        studentSelect_comboBox = new QComboBox(editFrame);
        studentSelect_comboBox->addItem(QString());
        studentSelect_comboBox->setObjectName("studentSelect_comboBox");
        studentSelect_comboBox->setGeometry(QRect(10, 20, 221, 25));
        label_84 = new QLabel(centralwidget);
        label_84->setObjectName("label_84");
        label_84->setGeometry(QRect(910, 30, 141, 17));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(280, 490, 291, 151));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_85 = new QLabel(frame);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(10, 10, 121, 17));
        selectGroup_comboBox = new QComboBox(frame);
        selectGroup_comboBox->addItem(QString());
        selectGroup_comboBox->setObjectName("selectGroup_comboBox");
        selectGroup_comboBox->setGeometry(QRect(10, 40, 270, 31));
        sort_button = new QPushButton(frame);
        sort_button->setObjectName("sort_button");
        sort_button->setGeometry(QRect(10, 90, 270, 41));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(580, 490, 311, 151));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        openFile_button = new QPushButton(frame_2);
        openFile_button->setObjectName("openFile_button");
        openFile_button->setGeometry(QRect(10, 10, 291, 61));
        saveFile_button = new QPushButton(frame_2);
        saveFile_button->setObjectName("saveFile_button");
        saveFile_button->setGeometry(QRect(10, 80, 291, 61));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(280, 650, 881, 161));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        find_button = new QPushButton(frame_3);
        find_button->setObjectName("find_button");
        find_button->setGeometry(QRect(10, 70, 281, 25));
        label_95 = new QLabel(frame_3);
        label_95->setObjectName("label_95");
        label_95->setGeometry(QRect(10, 10, 281, 17));
        lineEdit = new QLineEdit(frame_3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 40, 281, 25));
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(300, 10, 571, 141));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_96 = new QLabel(frame_4);
        label_96->setObjectName("label_96");
        label_96->setGeometry(QRect(330, 10, 66, 17));
        oaipLabel = new QLabel(frame_4);
        oaipLabel->setObjectName("oaipLabel");
        oaipLabel->setGeometry(QRect(330, 30, 171, 17));
        maLabel = new QLabel(frame_4);
        maLabel->setObjectName("maLabel");
        maLabel->setGeometry(QRect(330, 50, 171, 17));
        agilaLabel = new QLabel(frame_4);
        agilaLabel->setObjectName("agilaLabel");
        agilaLabel->setGeometry(QRect(330, 70, 171, 17));
        mlLabel = new QLabel(frame_4);
        mlLabel->setObjectName("mlLabel");
        mlLabel->setGeometry(QRect(330, 90, 171, 17));
        historyLabel = new QLabel(frame_4);
        historyLabel->setObjectName("historyLabel");
        historyLabel->setGeometry(QRect(330, 110, 171, 17));
        Group_Label = new QLabel(frame_4);
        Group_Label->setObjectName("Group_Label");
        Group_Label->setGeometry(QRect(20, 80, 291, 17));
        Spec_Label = new QLabel(frame_4);
        Spec_Label->setObjectName("Spec_Label");
        Spec_Label->setGeometry(QRect(20, 50, 291, 17));
        Fio_Label = new QLabel(frame_4);
        Fio_Label->setObjectName("Fio_Label");
        Fio_Label->setGeometry(QRect(20, 20, 291, 17));
        AvMark_Label = new QLabel(frame_4);
        AvMark_Label->setObjectName("AvMark_Label");
        AvMark_Label->setGeometry(QRect(20, 110, 291, 17));
        label_13 = new QLabel(frame_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(220, 60, 151, 17));
        _createVed_button = new QPushButton(centralwidget);
        _createVed_button->setObjectName("_createVed_button");
        _createVed_button->setGeometry(QRect(10, 570, 251, 81));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 670, 231, 81));
        QFont font;
        font.setKerning(true);
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8(""));
        label_12->setTextFormat(Qt::AutoText);
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_12->setWordWrap(false);
        label_12->setIndent(-1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1207, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Task2 \320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217 \320\276\321\206\320\265\320\275\320\272\320\260 \320\267\320\260 \n"
"\321\201\320\265\320\274\320\265\321\201\321\202\321\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\270 \320\267\320\260 \320\277\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \321\201\320\265\320\274\320\265\321\201\321\202\321\200:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\236\320\220\320\270\320\237", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202 \320\260\320\275\320\260\320\273\320\270\320\267", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\220\320\223\320\270\320\233\320\220", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202 \320\273\320\276\320\263\320\270\320\272\320\260", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202\321\213", nullptr));
        label_75->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        label_76->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        label_78->setText(QCoreApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\270 \320\267\320\260 \320\277\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \321\201\320\265\320\274\320\265\321\201\321\202\321\200:", nullptr));
        label_79->setText(QCoreApplication::translate("MainWindow", "\320\236\320\220\320\270\320\237", nullptr));
        label_80->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202 \320\260\320\275\320\260\320\273\320\270\320\267", nullptr));
        label_81->setText(QCoreApplication::translate("MainWindow", "\320\220\320\223\320\270\320\233\320\220", nullptr));
        label_82->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202 \320\273\320\276\320\263\320\270\320\272\320\260", nullptr));
        label_83->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217", nullptr));
        delete_button->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        edit_button->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        studentSelect_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));

        label_84->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        label_85->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        selectGroup_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));

        sort_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        openFile_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        saveFile_button->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        find_button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        label_95->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\244\320\230\320\236 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260 (\320\270\320\273\320\270 \321\207\320\260\321\201\321\202\321\214 \320\244\320\230\320\236)", nullptr));
        label_96->setText(QCoreApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\270:", nullptr));
        oaipLabel->setText(QString());
        maLabel->setText(QString());
        agilaLabel->setText(QString());
        mlLabel->setText(QString());
        historyLabel->setText(QString());
        Group_Label->setText(QString());
        Spec_Label->setText(QString());
        Fio_Label->setText(QString());
        AvMark_Label->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202 \320\275\320\265 \320\275\320\260\320\271\320\264\320\265\320\275", nullptr));
        _createVed_button->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\237\321\200\320\270 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\320\270 \320\275\320\276\320\262\320\276\320\271 \320\262\320\265\320\264\320\276\320\274\320\276\321\201\321\202\320\270, </p><p>\320\275\320\265\321\201\320\276\321\205\321\200\320\260\320\275\321\221\320\275\320\275\321\213\320\265 \320\264\320\260\320\275\321\213\320\265 \320\261\321\203\320\264\321\203\321\202 </p><p>\321\203\320\264\320\260\320\273\320\265\320\275\321\213</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
