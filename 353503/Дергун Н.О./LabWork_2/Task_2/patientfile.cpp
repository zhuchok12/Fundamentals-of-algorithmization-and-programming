#include "patientfile.h"


PatientFile::PatientFile(QObject *parent)
    : QObject{parent}
{}

PatientFile::PatientFile(const QString filePath, QObject *parent)
    : QObject{parent}
{
    this->setFile(filePath);
}


//***********************************************************************************//


void PatientFile::readFile()
{
    patientVector.clear();

    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    Patient tempPatient;
    while (!in.atEnd())
    {
        in >> tempPatient;
        patientVector.push_back(tempPatient);
    }

    file.close();
}

void PatientFile::writeFile()
{
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    for (int i = 0; i < patientVector.size(); ++i)
    {
        out << patientVector.at(i);
    }

    file.close();
}

void PatientFile::editFile(const unsigned int pos, const Patient newPatient)
{
    file.open(QIODevice::ReadWrite);
    QDataStream out(&file);

    Patient tresh;
    for (int i = 0; i < pos; ++i)
    {
        out >> tresh;
    }
    //out.device()->seek(pos * sizeof(Patient));

    out << newPatient;

    file.close();
}

void PatientFile::addToFile(const Patient newPatient)
{
    file.open(QIODevice::Append);
    QDataStream out(&file);

    out << newPatient;

    file.close();
}

bool PatientFile::setFile(const QString newFileName)
{
    file.setFileName(newFileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    file.close();

    this->readFile();
    return true;
}


//***********************************************************************************//


QVector<Patient> PatientFile::getVector() const
{
    return patientVector;
}

void PatientFile::setVector(const QVector<Patient> newVector)
{
    patientVector = newVector;
    this->writeFile();
}


//***********************************************************************************//


bool PatientFile::editNthPatient(const unsigned int pos, const Patient newPatient)
{
    if (pos + 1 > patientVector.size())
    {
        return false;
    }

    this->editFile(pos, newPatient);
    return true;
}

void PatientFile::addPatient(const Patient newPatient)
{
    this->addToFile(newPatient);
}

bool PatientFile::deletePatient(const unsigned pos)
{
    if (pos + 1 > patientVector.size())
    {
        return false;
    }

    patientVector.removeAt(pos);
    this->writeFile();

    return true;
}
