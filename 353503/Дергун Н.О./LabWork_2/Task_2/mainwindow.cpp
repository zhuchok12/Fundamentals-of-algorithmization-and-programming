#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->addWidget(ui->sexGBox);
    ui->stackedWidget->addWidget(ui->searchBox);
    ui->stackedWidget->setCurrentWidget(ui->sexGBox);
    ui->centralwidget->setLayout(ui->mainLayout);

    //currentFileName = exampleFileName;
    patientList = new PatientList(this);
    connect(patientList, SIGNAL(invalidFile()), SLOT(slotInvalidFileL()));
    //patientList->setFile(exampleFileName);

    patientVector = patientList->getVector();
    this->updateTable();

    ui->addButton->setChecked(true);
    connect(ui->addButton, SIGNAL(toggled(bool)), SLOT(slotModeChanged()));
    connect(ui->editButton, SIGNAL(toggled(bool)), SLOT(slotModeChanged()));
    connect(ui->deleteButton, SIGNAL(toggled(bool)), SLOT(slotModeChanged()));
    connect(ui->findButton, SIGNAL(toggled(bool)), SLOT(slotModeChanged()));
    slotModeChanged();

    ui->idBox->setMinimum(0);
    ui->wardBox->setMinimum(0);
    ui->ageBox->setMinimum(0);
    connect(ui->idBox, SIGNAL(valueChanged(int)), this, SLOT(slotChangePatient()));
    slotChangePatient();

    connect(ui->saveBtn, SIGNAL(clicked(bool)), SLOT(slotSaveFile()));
    connect(ui->openBtn, SIGNAL(clicked(bool)), SLOT(slotOpenFile()));
    connect(ui->wardButton, SIGNAL(clicked(bool)), SLOT(slotSortWards()));

    connect(ui->applyButton, SIGNAL(clicked(bool)), SLOT(slotApply()));

    ui->wardBox->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//***********************************************************************************//


short MainWindow::getMode()
{
    short mode;

    if (ui->addButton->isChecked())
    {
        mode = 0;
    }
    else if (ui->editButton->isChecked())
    {
        mode = 1;
    }
    else if (ui->deleteButton->isChecked())
    {
        mode = 2;
    }
    else
    {
        mode = 3;
    }

    return mode;
}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setRowCount(ui->findButton->isChecked() ? returnSet.size() : patientVector.size());

    Patient patient;
    if (!ui->findButton->isChecked())
    {
        for (int i = 0; i < patientVector.size(); ++i)
        {
            patient = patientVector.at(i);

            QTableWidgetItem *item = new QTableWidgetItem(QString::number(i));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 0, item);
            item = new QTableWidgetItem(patient.getName());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 1, item);
            item = new QTableWidgetItem(patient.getSurname());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 2, item);
            item = new QTableWidgetItem(patient.getPatronymic());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 3, item);
            item = new QTableWidgetItem(patient.getMale() ? "Male" : "Female");
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 4, item);
            item = new QTableWidgetItem(QString::number(patient.getAge()));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 5, item);
            item = new QTableWidgetItem(patient.getDiagnosis());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 6, item);
            item = new QTableWidgetItem(QString::number(patient.getWard()));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 7, item);
        }
    }
    else
    {
        int i = 0;
        for (auto now : returnSet)
        {
            patient = patientVector.at(now);

            QTableWidgetItem *item = new QTableWidgetItem(QString::number(now));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 0, item);
            item = new QTableWidgetItem(patient.getName());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 1, item);
            item = new QTableWidgetItem(patient.getSurname());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 2, item);
            item = new QTableWidgetItem(patient.getPatronymic());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 3, item);
            item = new QTableWidgetItem(patient.getMale() ? "Male" : "Female");
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 4, item);
            item = new QTableWidgetItem(QString::number(patient.getAge()));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 5, item);
            item = new QTableWidgetItem(patient.getDiagnosis());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 6, item);
            item = new QTableWidgetItem(QString::number(patient.getWard()));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget->setItem(i, 7, item);

            ++i;
        }
    }
}



//***********************************************************************************//


void MainWindow::slotApply()///////////////////////////Учесть -1 0 в пустом
{
    short mode = getMode();

    switch (mode)
    {
    case 0:
        patientVector.push_back(Patient
                                (
                                    ui->nameEdit->text(),
                                    ui->surnameEdit->text(),
                                    ui->patronymicEdit->text(),
                                    ui->maleRadioButton->isChecked(),
                                    ui->ageBox->value(),
                                    ui->dgnsEdit->toPlainText()
                                ));


        ui->idBox->setMaximum(patientVector.size());
        ui->idBox->setValue(patientVector.size());
        patientList->setVector(patientVector);
        break;

    case 1:
        if (ui->idBox->value() >= 0 && ui->idBox->value() < patientVector.size())
        {
            patientVector[ui->idBox->value()] = Patient
                (
                    ui->nameEdit->text(),
                    ui->surnameEdit->text(),
                    ui->patronymicEdit->text(),
                    ui->maleRadioButton->isChecked(),
                    ui->ageBox->value(),
                    ui->dgnsEdit->toPlainText()
                    );
            patientList->setVector(patientVector);
            this->slotChangePatient();
        }
        break;

    case 2:
        if (ui->idBox->value() >= 0 && ui->idBox->value() < patientVector.size())
        {
            patientVector.remove(ui->idBox->value());
        ui->idBox->setMaximum(patientVector.size() - 1);
        patientList->setVector(patientVector);
        this->slotChangePatient();
        }
        break;

    default:

        returnSet.clear();
        for (int i = 0; i < patientVector.size(); ++i)
        {
            returnSet.insert(i);
        }

        if (ui->nameBox->isChecked())
        {
            filteredVector = patientList->findName
                                          (
                                              ui->nameEdit->text(),
                                              ui->surnameEdit->text(),
                                              ui->patronymicEdit->text()
                                          );

            filteredSet = QSet<unsigned>(filteredVector.begin(), filteredVector.end());

            returnSet.intersect(filteredSet);
        }
        if (ui->diagnosisBox->isChecked())
        {
            filteredVector = patientList->findDiagnosis(ui->dgnsEdit->toPlainText());

            filteredSet = QSet<unsigned>(filteredVector.begin(), filteredVector.end());

            returnSet.intersect(filteredSet);
        }
        if (ui->wardCBox->isChecked())
        {
            filteredVector = patientList->findWard(ui->wardBox->value());

            filteredSet = QSet<unsigned>(filteredVector.begin(), filteredVector.end());

            returnSet.intersect(filteredSet);
        }

        break;
    }

    patientList->setVector(patientVector);
    updateTable();
}

void MainWindow::slotChangePatient()
{
    if (ui->editButton->isChecked())
    {
        if (!patientVector.empty())
        {
            ui->idBox->setMaximum(patientVector.size() - 1);
        }
        else
        {
            ui->idBox->setMaximum(0);
        }

        ui->idBox->setMinimum(0);

        if (!patientVector.empty())
        {
            int i = ui->idBox->value();
            ui->surnameEdit->setText(patientVector.at(i).getSurname());
            ui->nameEdit->setText(patientVector.at(i).getName());
            ui->patronymicEdit->setText(patientVector.at(i).getPatronymic());
            ui->ageBox->setValue(patientVector.at(i).getAge());

            if (patientVector.at(i).getMale())
            {
                ui->maleRadioButton->setChecked(true);
            }
            else
            {
                ui->femaleRadioButton->setChecked(true);
            }

            ui->dgnsEdit->setText(patientVector.at(i).getDiagnosis());
            ui->wardBox->setValue(patientVector.at(i).getWard());
        }
    }
}

void MainWindow::slotModeChanged()
{
    short mode = getMode();

    switch (mode)
    {
        case 0:
            ui->idBox->setReadOnly(true);
            ui->idBox->setMaximum(patientVector.size());
            ui->idBox->setValue(patientVector.size());

            ui->stackedWidget->setCurrentWidget(ui->sexGBox);

            ui->nameEdit->setReadOnly(false);
            ui->surnameEdit->setReadOnly(false);
            ui->patronymicEdit->setReadOnly(false);
            ui->maleRadioButton->setEnabled(true);
            ui->femaleRadioButton->setEnabled(true);
            ui->ageBox->setReadOnly(false);
            ui->dgnsEdit->setReadOnly(false);
            ui->wardBox->setReadOnly(true);

            this->updateTable();

            break;

        case 1:
            ui->idBox->setMaximum(patientVector.size() - 1);
            ui->idBox->setReadOnly(false);

            ui->stackedWidget->setCurrentWidget(ui->sexGBox);

            ui->nameEdit->setReadOnly(false);
            ui->surnameEdit->setReadOnly(false);
            ui->patronymicEdit->setReadOnly(false);
            ui->maleRadioButton->setEnabled(true);
            ui->femaleRadioButton->setEnabled(true);
            ui->ageBox->setReadOnly(false);
            ui->dgnsEdit->setReadOnly(false);
            ui->wardBox->setReadOnly(true);
            ui->wardBox->setReadOnly(true);

            this->slotChangePatient();

            this->updateTable();

            break;

        case 2:
            ui->idBox->setMaximum(patientVector.size() - 1);
            ui->idBox->setReadOnly(false);

            ui->stackedWidget->setCurrentWidget(ui->sexGBox);

            ui->nameEdit->setReadOnly(true);
            ui->surnameEdit->setReadOnly(true);
            ui->patronymicEdit->setReadOnly(true);
            ui->maleRadioButton->setEnabled(false);
            ui->femaleRadioButton->setEnabled(false);
            ui->ageBox->setReadOnly(true);
            ui->dgnsEdit->setReadOnly(true);
            ui->wardBox->setReadOnly(true);

            this->updateTable();

            break;

        default:
            ui->stackedWidget->setCurrentWidget(ui->searchBox);

            ui->wardBox->setReadOnly(false);
            ui->wardBox->setMinimum(-1);
            ui->wardBox->setMaximum(patientVector.size() - 1);

            ui->idBox->setReadOnly(true);
            ui->nameEdit->setReadOnly(false);
            ui->surnameEdit->setReadOnly(false);
            ui->patronymicEdit->setReadOnly(false);
            ui->maleRadioButton->setEnabled(false);
            ui->femaleRadioButton->setEnabled(false);
            ui->ageBox->setReadOnly(true);
            ui->dgnsEdit->setReadOnly(false);

            break;
    }
}

void MainWindow::slotOpenFile()
{
    currentFileName = QFileDialog::getOpenFileName(this, "Open file", "");
    patientList->setFile(currentFileName);
    patientVector = patientList->getVector();

    updateTable();
    this->slotChangePatient();
}

void MainWindow::slotSaveFile() //////////////////////////////////////////////////////////
{
    saveFileName = QFileDialog::getSaveFileName(this, "Save file", "");
    saveList = new PatientList(saveFileName, this);
    saveList->setVector(patientVector);
    delete saveList;
}

void MainWindow::slotSortWards()
{
    patientList->toWards(wardNumber);
    patientVector = patientList->getVector();

    this->updateTable();
    this->slotChangePatient();
}
