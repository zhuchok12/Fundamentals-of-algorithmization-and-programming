#include "datefile.h"


DateFile::DateFile(QObject *parent)
    : QObject(parent)
{
    validFile = false;
}

DateFile::DateFile(const QString filePath, QObject *parent)
    : QObject(parent)
{
    file.setFileName(filePath);

    if (!this->fileIsValid())
    {
        emit invalidFile();
    }

    this->readFile();
}


//***********************************************************************************//


bool DateFile::setFile(const QString newFileName)
{
    file.setFileName(newFileName);

    if (!this->fileIsValid())
    {
        emit invalidFile();
        return false;
    }

    this->readFile();
    return true;
}

bool DateFile::fileIsValid()
{
    if (!file.exists())
    {
        emit invalidFile();
        validFile = false;
        return false;
    }

    if (!this->readFile())
    {
        emit invalidFile();
        validFile = false;
        return false;
    }

    validFile = true;
    return true;
}

bool DateFile::readFile()
{
    bool correctInput = true;
    dateVector.clear();

    QString tempLine;
    QStringList tempList;

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QTextStream in(&file);

    while (!in.atEnd() && correctInput)
    {
        tempLine = in.readLine().trimmed();
        tempList = tempLine.split(' ');

        for (const QString &tempString : tempList)
        {
            if (!dateCheck.match(tempString).hasMatch())
            {
                correctInput = false;
                emit invalidFile();
                break;
            }

            dateVector << Date(tempString.mid(0, 2).toInt(),
                               tempString.mid(3, 2).toInt(),
                               tempString.mid(6, 4).toInt());
        }
    }

    file.close();

    if (!correctInput)
    {
        dateVector.clear();
    }

    this->writeFile();

    return true;
}

void DateFile::writeFile()
{
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }

    QTextStream out(&file);

    for (int i = 0; i < dateVector.size(); ++i)
    {
        out << dateVector.at(i).getQStrDate();
        if (i + 1 != dateVector.size())
        {
            out << " ";
        }
    }

    file.close();
}

bool DateFile::editFile(unsigned int pos, Date newDate)
{
    if (!this->fileIsValid())
    {
        return false;
    }

    file.open(QIODevice::ReadWrite);
    QTextStream out(&file);

    if (!out.seek(pos * 11))
    {
        file.close();
        return false;
    }

    //file.write(newDate.getQStrDate().toStdString().c_str(), newDate.getQStrDate().length());
    out << newDate.getQStrDate();

    file.close();
    return true;
}

bool DateFile::addToFile(const Date newDate)
{
    if (!this->fileIsValid())
    {
        return false;
    }

    file.open(QIODevice::Append);
    QTextStream out(&file);

    out << " " << newDate.getQStrDate();

    file.close();
    return true;
}


//***********************************************************************************//


QVector<Date> DateFile::getVector() const
{
    return dateVector;
}

bool DateFile::editNthDate(const unsigned pos, const Date newDate)
{
    if (!validFile)
    {
        emit invalidFile();
        return false;
    }

    if (!this->editFile(pos, newDate))
    {
        emit invalidFile();
        return false;
    }

    this->fileIsValid();

    return true;
}

bool DateFile::addDate(const Date newDate)
{
    if (!validFile)
    {
        emit invalidFile();
        return false;
    }

    if (!this->addToFile(newDate))
    {
        emit invalidFile();
        return false;
    }

    this->fileIsValid();

    return true;
}

bool DateFile::setVector(QVector<Date> newDateVector)
{
    dateVector = newDateVector;
    this->writeFile();
}
