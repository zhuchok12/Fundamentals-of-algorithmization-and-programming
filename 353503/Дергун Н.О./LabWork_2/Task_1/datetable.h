#ifndef DATETABLE_H
#define DATETABLE_H

#include <QFormLayout>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include "date.h"

class DateTable : public QWidget
{
    QVector<Date> dateVector;
    QScrollArea* scrollArea;
    QFormLayout* formLayout;
    QVector<QLabel*> labelVector;
    QWidget *scrollWidget;
    QVBoxLayout *mainLayout;

public:
    DateTable(QWidget *parent = nullptr);
    DateTable(QVector<Date>, QWidget *parent = nullptr);

    void setVector(const QVector<Date>);
    QVector<Date> getVector() const;

};

#endif // DATETABLE_H
