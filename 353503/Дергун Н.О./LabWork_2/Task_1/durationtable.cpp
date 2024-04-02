#include "durationtable.h"

DurationTable::DurationTable(QWidget *parent)
    : QWidget(parent)
{
    formLayout = new QFormLayout (this);
    scrollArea = new QScrollArea (this);

    scrollWidget = new QWidget(this);
    scrollWidget->setLayout(formLayout);
    scrollArea->setWidget(scrollWidget);
}

DurationTable::DurationTable(QVector<int> dateVector, QWidget *parent)
    : QWidget(parent)
{
    formLayout = new QFormLayout (this);
    scrollArea = new QScrollArea (this);

    this->dateVector = dateVector;

    for (int curDur : dateVector)
    {
        QLabel* tempLabel = new QLabel(QString::number(curDur), this);
        labelVector << tempLabel;
    }

    for (int i = 0; i < labelVector.size(); ++i)
    {
        formLayout->addRow(QString::number(i + 1) + ": Days until the next date from the table: ", labelVector.at(i));
    }

    scrollWidget = new QWidget(this);
    scrollWidget->setLayout(formLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    this->setLayout(mainLayout);
}


//***********************************************************************************//


void DurationTable::setVector(const QVector<int> dateVector)
{
    this->dateVector = dateVector; 

    QLayoutItem *item;
    while ((item = formLayout->takeAt(0)))
    {
        if (QWidget* widget = item->widget())
            widget->deleteLater();
        delete item;
    }

    labelVector.clear();

    for (int curDur : dateVector)
    {
        QLabel* tempLabel = new QLabel(QString::number(curDur), this);
        labelVector << tempLabel;
    }

    for (int i = 0; i < labelVector.size(); ++i)
    {
        formLayout->addRow(QString::number(i + 1) + ": Days until the next date from the table: ", labelVector.at(i));
    }
}

QVector<int> DurationTable::getVector() const
{
    return dateVector;
}
