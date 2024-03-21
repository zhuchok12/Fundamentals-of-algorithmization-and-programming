#ifndef PATIENTLIST_H
#define PATIENTLIST_H

#include "patientfile.h"
#include <algorithm>

class PatientList : public PatientFile
{
    Q_OBJECT

    const int wardCapacity = 4;

public:
    explicit PatientList(QObject *parent = nullptr);
    PatientList(const QString, QObject *parent = nullptr);

    unsigned sortBasedOnSex();

    QVector<unsigned> findWard(int wardNum);
    QVector<unsigned> findDiagnosis(QString aimDiagnosis);
    QVector<unsigned> findName(QString name, QString surname, QString patronymic);

    QVector<unsigned> toWards(const unsigned wardCnt);
};


#endif // PATIENTLIST_H
