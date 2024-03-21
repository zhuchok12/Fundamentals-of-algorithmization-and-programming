#include "datetable.h"

DateTable::DateTable(QWidget *parent)
    : QWidget(parent)
{
    formLayout = new QFormLayout (this);
    scrollArea = new QScrollArea (this);

    scrollWidget = new QWidget(this);
    scrollWidget->setLayout(formLayout);
    scrollArea->setWidget(scrollWidget);
}

DateTable::DateTable(QVector<Date> dateVector, QWidget *parent)
    : QWidget(parent)
{
    formLayout = new QFormLayout (this);
    scrollArea = new QScrollArea (this);

    this->dateVector = dateVector;

    for (Date curDate : dateVector)
    {
        QLabel* tempLabel = new QLabel(curDate.getQStrDate(), this);
        labelVector << tempLabel;
    }

    for (int i = 0; i < labelVector.size(); ++i)
    {
        formLayout->addRow(QString::number(i+1) + ": ", labelVector.at(i));
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


void DateTable::setVector(const QVector<Date> dateVector)
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

    for (Date curDate : dateVector)
    {
        QLabel* tempLabel = new QLabel(curDate.getQStrDate(), this);
        labelVector << tempLabel;
    }

    for (int i = 0; i < labelVector.size(); ++i)
    {
        formLayout->addRow(QString::number(i+1) + ": ", labelVector.at(i));
    }

    scrollWidget->resize(150, 20 * dateVector.size());
}

QVector<Date> DateTable::getVector() const
{
    return dateVector;
}
