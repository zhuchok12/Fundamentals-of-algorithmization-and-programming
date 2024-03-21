#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainLayout = new QGridLayout(this);


    dateFile = new DateFile (exampleFileName, this);
    connect(dateFile, SIGNAL(invalidFile()), SLOT(slotInvalidFile()));
    fileDateTable = new DateTable(dateFile->getVector(), this);
    mainLayout->addWidget(fileDateTable, 0, 0, 3, 1);

    currentFileName = exampleFileName;
    dateVector = dateFile->getVector();


    resultDateTable = new DateTable(this->getResultDateVector(), this);
    resultDurationTable = new DurationTable(this->getResultDurationVector(), this);
    resultTable = new QStackedLayout(this);
    resultTable->addWidget(resultDateTable);
    resultTable->addWidget(resultDurationTable);
    resultTable->setCurrentIndex(0);
    mainLayout->addLayout(resultTable, 0, 1, 3, 1);/////////////////////////////????????????????????????///


    editLayout = new QFormLayout(this);

    yearSpinBox = new QSpinBox(this);
    yearSpinBox->setMinimum(1);
    yearSpinBox->setMaximum(9999);
    editLayout->addRow("Year: ", yearSpinBox);

    monthSpinBox = new QSpinBox(this);
    monthSpinBox->setMinimum(1);
    monthSpinBox->setMaximum(12);
    editLayout->addRow("Month: ", monthSpinBox);

    daySpinBox = new QSpinBox(this);
    daySpinBox->setMinimum(1);
    daySpinBox->setMaximum(Date(1, monthSpinBox->value(), yearSpinBox->value()).DaysInMonth());
    editLayout->addRow("Day: ", daySpinBox);

    changeResultBtn = new QPushButton("Change processing", this);
    connect(changeResultBtn, SIGNAL(clicked(bool)), SLOT(slotChangeResultBtn()));

    birthdayLbl = new QLabel(this);
    editLayout->addRow("Birthday: ", birthdayLbl);

    tillYourBithday = new QLabel();
    editLayout->addRow("Days till birthday: ", tillYourBithday);


    connect(daySpinBox, SIGNAL(valueChanged(int)), SLOT(slotUpdateBD()));
    connect(monthSpinBox, SIGNAL(valueChanged(int)), SLOT(slotUpdateBD()));
    connect(yearSpinBox, SIGNAL(valueChanged(int)), SLOT(slotUpdateBD()));


    editFileLayout = new QFormLayout(this);

    yearFileSpinBox = new QSpinBox(this);
    yearFileSpinBox->setMinimum(1);
    yearFileSpinBox->setMaximum(9999);
    editFileLayout->addRow("Year: ", yearFileSpinBox);

    monthFileSpinBox = new QSpinBox(this);
    monthFileSpinBox->setMinimum(1);
    monthFileSpinBox->setMaximum(12);
    editFileLayout->addRow("Month: ", monthFileSpinBox);

    dayFileSpinBox = new QSpinBox(this);
    dayFileSpinBox->setMinimum(1);
    dayFileSpinBox->setMaximum(Date(1, monthFileSpinBox->value(), yearFileSpinBox->value()).DaysInMonth());
    editFileLayout->addRow("Day: ", dayFileSpinBox);

    dayFileSpinBox->setValue(Date().Day());
    monthFileSpinBox->setValue(Date().Month());
    yearFileSpinBox->setValue(Date().Year());

    selectedDate = 0;
    addMode = 0;
    changeActionBtn = new QPushButton("Change the form of editing", this);
    connect(changeActionBtn, SIGNAL(clicked(bool)), SLOT(slotChangeActionBtn()));
    modeLbl = new QLabel("Add", this);
    editFileLayout->addRow(modeLbl, changeActionBtn);

    numberSpinBox = new QSpinBox(this);
    numberSpinBox->setMinimum(1);
    numberSpinBox->setMaximum(dateVector.size());
    editFileLayout->addRow("Selected date: ", numberSpinBox);


    setFilebtn = new QPushButton("Find file on the PC", this);
    editFileLayout->addRow("Change selected file: ", setFilebtn);

    connect(setFilebtn, SIGNAL(clicked(bool)), SLOT(slotChangeFile()));

    applyBtn = new QPushButton("Apply", this);
    editFileLayout->addRow("File update", applyBtn);

    connect(numberSpinBox, SIGNAL(valueChanged(int)), SLOT(slotSelectDate()));
    connect(applyBtn, SIGNAL(clicked(bool)), SLOT(slotApply()));

    connect(dayFileSpinBox, SIGNAL(valueChanged(int)), SLOT(slotUpdateDate()));
    connect(monthFileSpinBox, SIGNAL(valueChanged(int)), SLOT(slotUpdateDate()));
    connect(yearFileSpinBox, SIGNAL(valueChanged(int)), SLOT(slotUpdateDate()));


    slotUpdateBD();


    topBox = new QGroupBox;
    topBox->setLayout(editFileLayout);
    botBox = new QGroupBox;
    botBox->setLayout(editLayout);

    mainLayout->addWidget(topBox, 0, 2);
    mainLayout->addWidget(botBox, 1, 2);
    mainLayout->addWidget(changeResultBtn, 2, 2);

    ui->centralwidget->setLayout(mainLayout);


    mainLayout->setColumnStretch(0, 2);
    mainLayout->setColumnStretch(1, 2);
    mainLayout->setColumnStretch(2, 1);

    // mainLayout->setRowStretch(0, 1);
    // mainLayout->setRowStretch(1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//***********************************************************************************//


QVector<Date> MainWindow::getResultDateVector()
{
    QVector<Date> retVector (dateVector);

    for (Date& curDate : retVector)
    {
        curDate = curDate.NextDay();
    }

    return retVector;
}

QVector<int> MainWindow::getResultDurationVector()
{
    QVector<int> retVector;

    for (int i = 0; i + 1 < dateVector.size(); ++i)
    {
        retVector << dateVector.at(i).Duration(dateVector.at(i + 1));
    }

    return retVector;
}

//***********************************************************************************//

void MainWindow::slotInvalidFile()
{
    QMessageBox::warning(this, "Problem with the file", "The file contains incorrect data or is not textual. Example file have been opened.");
    currentFileName = exampleFileName;
    if (!dateFile->setFile(currentFileName))
    {
        QMessageBox::critical(this, "Problem with the example file", "The example file can not be opened.");
        dateVector.clear();
    }
    else
    {
        dateVector = dateFile->getVector();
    }

    fileDateTable->setVector(dateVector);
    numberSpinBox->setMinimum(1);
    numberSpinBox->setMaximum(dateVector.size());
    selectedDate = 0;
}

void MainWindow::slotChangeResultBtn()
{
    resultTable->setCurrentIndex((resultTable->currentIndex() + 1) % 2);
}

void MainWindow::slotChangeActionBtn()
{
    addMode = ++addMode % 3;

    switch(addMode)
    {
        case 0:
            modeLbl->setText("Add");
            numberSpinBox->setDisabled(true);
            dayFileSpinBox->setDisabled(false);
            monthFileSpinBox->setDisabled(false);
            yearFileSpinBox->setDisabled(false);
            dayFileSpinBox->setValue(Date().Day());
            monthFileSpinBox->setValue(Date().Month());
            yearFileSpinBox->setValue(Date().Year());
            break;
        case 1:
            modeLbl->setText("Edit");
            numberSpinBox->setDisabled(false);
            dayFileSpinBox->setValue(dateVector.at(numberSpinBox->value() - 1).Day());
            monthFileSpinBox->setValue(dateVector.at(numberSpinBox->value() - 1).Month());
            yearFileSpinBox->setValue(dateVector.at(numberSpinBox->value() - 1).Year());
            break;
        default:
            modeLbl->setText("Delete");
            dayFileSpinBox->setDisabled(true);
            monthFileSpinBox->setDisabled(true);
            yearFileSpinBox->setDisabled(true);
            break;
    }

    numberSpinBox->setValue(1);
}

void MainWindow::slotUpdateBD()
{
    daySpinBox->setMaximum(Date(1, monthSpinBox->value(), yearSpinBox->value()).DaysInMonth());

    birthday = Date(daySpinBox->value(), monthSpinBox->value(), yearSpinBox->value());
    birthdayLbl->setText(birthday.getQStrDate());

    tillYourBithday->setText(QString::number(dateVector.at(numberSpinBox->value() - 1).DaysTillYourBithday(birthday)));
}

void MainWindow::slotUpdateDate()
{
    dayFileSpinBox->setMaximum(Date(1, monthFileSpinBox->value(), yearFileSpinBox->value()).DaysInMonth());

    tillYourBithday->setText(QString::number(dateVector.at(numberSpinBox->value() - 1).DaysTillYourBithday(birthday)));
}

void MainWindow::slotSelectDate()
{
    dayFileSpinBox->setValue(dateVector.at(numberSpinBox->value() - 1).Day());
    monthFileSpinBox->setValue(dateVector.at(numberSpinBox->value() - 1).Month());
    yearFileSpinBox->setValue(dateVector.at(numberSpinBox->value() - 1).Year());
    yearFileSpinBox->update();

    tillYourBithday->setText(QString::number(dateVector.at(numberSpinBox->value() - 1).DaysTillYourBithday(birthday)));
}

void MainWindow::slotChangeFile()
{
    currentFileName = QFileDialog::getOpenFileName(this, "Open a file you want to edit", "");
    dateFile->setFile(currentFileName);
    dateVector = dateFile->getVector();

    fileDateTable->setVector(dateVector);
    resultDateTable->setVector(this->getResultDateVector());
    resultDateTable->update();
    resultDurationTable->setVector(this->getResultDurationVector());
    resultDurationTable->update();
}

void MainWindow::slotApply()
{
    switch(addMode)
    {
    case 0:
        dateFile->addDate(Date(dayFileSpinBox->value(), monthFileSpinBox->value(), yearFileSpinBox->value()));
        break;
    case 1:
        dateFile->editNthDate(numberSpinBox->value() - 1, Date(dayFileSpinBox->value(), monthFileSpinBox->value(), yearFileSpinBox->value()));
        break;
    default:

        if (dateVector.size() > 1)
        {
            dateVector.erase(dateVector.cbegin() + numberSpinBox->value() - 1);

            dateFile->setVector(dateVector);
        }
        else
        {
            QMessageBox::warning(this, "Invalid deleting", "It's not possible to delete your only date");
        }

        break;
    }


    dateVector = dateFile->getVector();
    fileDateTable->setVector(dateVector);
    resultDateTable->setVector(this->getResultDateVector());
    resultDateTable->update();
    resultDurationTable->setVector(this->getResultDurationVector());
    resultDurationTable->update();
}
