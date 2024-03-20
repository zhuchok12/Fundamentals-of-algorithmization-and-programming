#ifndef DATE_H
#define DATE_H

#include <QTime>


class Date
{
    const int y400 = 146097;
    const int y100 = 36524;
    const int y4 = 1461;

    unsigned day, month, year, dayNum;

    unsigned daysFromTheStart();
    void standardize();
    Date copy() const;

public:
    Date();
    Date(unsigned, unsigned, unsigned);

    unsigned Year() const;
    unsigned Day() const;
    unsigned Month() const;

    Date NextDay() const;
    Date PreviousDay() const;
    bool IsLeap() const;
    short WeekNumber() const;
    int DaysTillYourBithday(Date) const;
    int Duration(Date) const;
    unsigned DaysInMonth() const;

    QString getQStrDate() const;

    Date& operator = (const Date);
};

#endif // DATE_H
