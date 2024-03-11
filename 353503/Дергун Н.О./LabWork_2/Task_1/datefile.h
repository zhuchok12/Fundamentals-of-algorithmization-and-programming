#ifndef DATEFILE_H
#define DATEFILE_H

#include <QFile>
#include <QFileInfo>
#include <QRegularExpression>
#include "date.h"

class DateFile : public QObject
{
    Q_OBJECT

    QFile file;
    QVector<Date> dateVector;
    const QRegularExpression dateCheck = QRegularExpression("\\b(0[1-9]|1[0-9]|2[0-9]|3[01]).(0[1-9]|1[012]).([0-9]{4})\\b");
    //01.01.0000 -- 31.12.9999

    bool fileIsValid();
    bool validFile;

    bool readFile();
    void writeFile();
    bool editFile(unsigned, Date);
    bool addToFile(const Date);

public:
    DateFile(QObject *parent = nullptr);
    DateFile(const QString, QObject *parent = nullptr);

    bool setFile(const QString);

    QVector<Date> getVector() const;
    bool editNthDate(const unsigned, const Date);
    bool setVector(const QVector<Date>);
    bool addDate(const Date);

signals:
    void invalidFile();

};

#endif // DATEFILE_H
