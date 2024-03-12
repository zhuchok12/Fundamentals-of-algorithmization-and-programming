#ifndef PATIENT_H
#define PATIENT_H

#include <QVector>
#include <QString>
#include <QDataStream>

class Patient
{
    QString name;
    QString surname;
    QString patronymic;
    bool male;
    int age;
    int ward;
    QString diagnosis;

public:
    Patient();
    Patient(QString name, QString surname, QString patronymic, bool male, int age, QString diagnosis);
    Patient(QString name, QString surname, QString patronymic, bool male, int age, QString diagnosis, int ward);

    void setPatient(QString name, QString surname, QString patronymic, bool male, int age, QString diagnosis);
    void setPatient(QString name, QString surname, QString patronymic, bool male, int age, QString diagnosis, int ward);
    QString getName() const;
    QString getSurname() const;
    QString getPatronymic() const;
    bool getMale() const;
    int getAge() const;
    int getWard() const;
    void setWard(int newWard);

    Patient& operator = (const Patient);

    friend QDataStream &operator << (QDataStream &out, const Patient &patient);
    friend QDataStream &operator >> (QDataStream &in, Patient &patient);
    QString getDiagnosis() const;
};

#endif // PATIENT_H
