#include "patient.h"


Patient::Patient()
{
    name = "no data";
    surname = "no data";
    patronymic = "no data";
    male = false;
    age = -1;
    ward = -1;
}

Patient::Patient(QString name, QString surname, QString patronymic, bool male, int age, QString diagnosis)
{
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->male = male;
    this->age = age;
    this->diagnosis = diagnosis;
    ward = -1;
}

Patient::Patient(QString name, QString surname, QString patronymic, bool male, int age, QString diagnosis, int ward)
{
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->male = male;
    this->age = age;
    this->ward = ward;
    this->diagnosis = diagnosis;
}


//***********************************************************************************//


void Patient::setPatient(QString name, QString surname, QString patronymic, bool male, int age, QString diagnosis)
{
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->male = male;
    this->age = age;
    this->diagnosis = diagnosis;
}

void Patient::setPatient(QString name, QString surname, QString patronymic, bool male, int age, QString diagnosis, int ward)
{
    this->name = name;
    this->surname = surname;
    this->patronymic = patronymic;
    this->male = male;
    this->age = age;
    this->diagnosis = diagnosis;
    this->ward = ward;
}


//***********************************************************************************//


QString Patient::getName() const
{
    return name;
}

QString Patient::getSurname() const
{
    return surname;
}

QString Patient::getPatronymic() const
{
    return patronymic;
}

bool Patient::getMale() const
{
    return male;
}

int Patient::getAge() const
{
    return age;
}

int Patient::getWard() const
{
    return ward;
}

QString Patient::getDiagnosis() const
{
    return diagnosis;
}

void Patient::setWard(int newWard)
{
    ward = newWard;
}


//***********************************************************************************//


Patient &Patient::operator = (const Patient newPatient)
{
    this->name = newPatient.name;
    this->surname = newPatient.surname;
    this->patronymic = newPatient.patronymic;
    this->male = newPatient.male;
    this->age = newPatient.age;
    this->diagnosis = newPatient.diagnosis;
    this->ward = newPatient.ward;

    return *this;
}


//***********************************************************************************//


QDataStream &operator << (QDataStream &out, const Patient &patient)
{
    out << patient.name;
    out << patient.surname;
    out << patient.patronymic;
    out << patient.male;
    out << patient.age;
    out << patient.diagnosis;
    out << patient.ward;
    return out;
}

QDataStream &operator >> (QDataStream &in, Patient &patient)
{
    in >> patient.name;
    in >> patient.surname;
    in >> patient.patronymic;
    in >> patient.male;
    in >> patient.age;
    in >> patient.diagnosis;
    in >> patient.ward;
    return in;
}
