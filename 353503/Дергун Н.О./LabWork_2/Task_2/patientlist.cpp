#include "patientlist.h"


PatientList::PatientList(QObject *parent)
    : PatientFile(parent)
{

}

PatientList::PatientList(const QString filePath, QObject *parent)
    : PatientFile(filePath, parent)
{
    this->setFile(filePath);
}


//***********************************************************************************//


unsigned PatientList::sortBasedOnSex()
{
    if (this->patientVector.empty())
    {
        return 0;
    }

    std::sort(this->patientVector.begin(), this->patientVector.end(), [](Patient a, Patient b){return a.getMale() == b.getMale();});
    this->writeFile();

    unsigned changePos = std::find_if(this->patientVector.begin(), this->patientVector.end(), [](Patient a){return a.getMale();}) - this->patientVector.begin();

    if (changePos == patientVector.size())
    {
        changePos = -1;
    }

    return changePos;
}

QVector<unsigned int> PatientList::findWard(int wardNum)
{
    QVector<unsigned int> requiredPatients;

    auto it = std::find_if(this->patientVector.begin(), this->patientVector.end(), [wardNum] (Patient patient) { return patient.getWard() == wardNum; });

    while (it != this->patientVector.end())
    {
        requiredPatients.push_back(it - this->patientVector.begin());
        it = std::find_if(it + 1, this->patientVector.end(), [wardNum] (Patient patient) { return patient.getWard() == wardNum; });
    }

    return requiredPatients;
}

QVector<unsigned int> PatientList::findDiagnosis(QString aimDiagnosis)
{
    QVector<unsigned int> requiredPatients;

    auto it = std::find_if(this->patientVector.begin(), this->patientVector.end(), [aimDiagnosis] (Patient patient) { return patient.getDiagnosis() == aimDiagnosis; });

    while (it != this->patientVector.end())
    {
        requiredPatients.push_back(it - this->patientVector.begin());
        it = std::find_if(it + 1, this->patientVector.end(), [aimDiagnosis] (Patient patient) { return patient.getDiagnosis() == aimDiagnosis; });
    }

    return requiredPatients;
}

QVector<unsigned> PatientList::findName(QString name, QString surname, QString patronymic)
{
    QVector<unsigned> requiredPatients;

    auto comp = [name, surname, patronymic] (Patient patient)
    {
        bool nameMatch = true, surnameMatch = true, patronymicMatch = true;

        if (!name.isEmpty())
        {
            nameMatch = patient.getName() == name;
        }
        if (!surname.isEmpty())
        {
            surnameMatch = patient.getSurname() == surname;
        }
        if (!patronymic.isEmpty())
        {
            patronymicMatch = patient.getPatronymic() == patronymic;
        }

        return nameMatch && surnameMatch && patronymicMatch;
    };

    auto it = std::find_if(this->patientVector.begin(), this->patientVector.end(), comp);

    while (it != this->patientVector.end())
    {
        requiredPatients.push_back(it - this->patientVector.begin());
        it = std::find_if(it + 1, this->patientVector.end(), comp);
    }

    return requiredPatients;
}


//***********************************************************************************//


QVector<unsigned> PatientList::toWards(const unsigned amnt)
{
    int malePos = this->sortBasedOnSex();
    int womenCnt = malePos;
    int menCnt = patientVector.size() - womenCnt;
    if (womenCnt == -1)
    {
        menCnt = 0;
        womenCnt = patientVector.size();
    }
    menCnt = (menCnt + wardCapacity - 1) / wardCapacity;
    womenCnt = (womenCnt + wardCapacity - 1) / wardCapacity;

    QVector<unsigned> extraPatients;
    if (this->patientVector.empty())
    {
        return extraPatients;
    }

    for (int i = 0; i < patientVector.size(); ++i)
    {
        patientVector[i].setWard(-1);
    }

    bool* hasWard = new bool[this->patientVector.size()] {};

    int wardSize;

    int wardCnt = amnt;
    int start, end;
    while (wardCnt > 0 && (womenCnt > 0 || menCnt > 0))
    {
        if (womenCnt < menCnt)
        {
            start = malePos;
            end = patientVector.size();
            --menCnt;
        }
        else
        {
            start = 0;
            if (malePos != -1)
            {
                end = malePos;
            }
            else
            {
                end = patientVector.size();
            }
            --womenCnt;
        }

        for (int i = start; i < end; ++i)
        {
            if (!hasWard[i])
            {
                this->patientVector[i].setWard(amnt - wardCnt + 1);
                hasWard[i] = true;
                wardSize = 1;

                QVector<unsigned int> sameDiagnosis = this->findDiagnosis(this->patientVector.at(i).getDiagnosis());
                for (int j = 0; j < sameDiagnosis.size() && wardSize < 4; ++j)
                {
                    if (!hasWard[sameDiagnosis.at(j)] && this->patientVector.at(i).getMale() == this->patientVector.at(sameDiagnosis.at(j)).getMale() && i != sameDiagnosis.at(j))
                    {
                        this->patientVector[sameDiagnosis.at(j)].setWard(amnt - wardCnt + 1);
                        hasWard[sameDiagnosis.at(j)] = true;
                        ++wardSize;
                    }
                }

                for (int j = i; j < end && wardSize < 4; ++j)
                {
                    if (!hasWard[j])
                    {
                        this->patientVector[j].setWard(amnt - wardCnt + 1);
                        hasWard[j] = true;
                        ++wardSize;
                    }
                }

                break;
            }
        }

        --wardCnt;
    }

    for (int i = 0; i < this->patientVector.size(); ++i)
    {
        if (!hasWard[i])
        {
            extraPatients.push_back(i);
        }
    }

    delete[] hasWard;
    return extraPatients;
}
