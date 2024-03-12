#ifndef PATIENTFILE_H
#define PATIENTFILE_H

#include <QObject>
#include <QFile>
#include <QDataStream>
#include "patient.h"

class PatientFile : public QObject
{
    Q_OBJECT

protected:
    QFile file;
    QVector<Patient> patientVector;

    void readFile();
    void writeFile();
    void editFile(const unsigned, const Patient);
    void addToFile(const Patient);

public:
    explicit PatientFile(QObject *parent = nullptr);
    PatientFile(const QString, QObject *parent = nullptr);

    bool setFile(const QString);

    QVector<Patient> getVector() const;
    void setVector(const QVector<Patient>);

    bool editNthPatient(const unsigned, const Patient);
    void addPatient(const Patient);
    bool deletePatient(const unsigned);

signals:
    void invalidFile();
};

#endif // PATIENTFILE_H
