#ifndef DURATIONTABLE_H
#define DURATIONTABLE_H

#include <QFormLayout>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>

class DurationTable : public QWidget
{
    QVector<int> dateVector;
    QScrollArea* scrollArea;
    QFormLayout* formLayout;
    QVector<QLabel*> labelVector;
    QWidget *scrollWidget;
    QVBoxLayout *mainLayout;

public:
    DurationTable(QWidget *parent = nullptr);
    DurationTable(QVector<int>, QWidget *parent = nullptr);

    void setVector(const QVector<int>);
    QVector<int> getVector() const;

};

#endif // DURATIONTABLE_H
