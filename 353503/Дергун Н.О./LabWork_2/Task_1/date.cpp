#include "date.h"


Date::Date()
{
    day = 1 + time(nullptr) / (24 * 60 * 60);
    month = 1;
    year = 1970;
    
    this->standardize();

    dayNum = this->daysFromTheStart();
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
    this->day = day;
    this->month = month;
    this->year = year;

    this->standardize();
    
    dayNum = this->daysFromTheStart();
}


//***********************************************************************************//


unsigned int Date::Year() const
{
    return year;
}

unsigned int Date::Day() const
{
    return day;
}

unsigned int Date::Month() const
{
    return month;
}


//***********************************************************************************//


Date Date::NextDay() const
{
    Date retDate = Date(this->Day() + 1, this->Month(), this->Year());
    retDate.standardize();
    return retDate;
}

Date Date::PreviousDay() const
{
    Date retDate = Date(this->Day() - 1, this->Month(), this->Year());
    retDate.standardize();
    return retDate;
}

bool Date::IsLeap() const
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short Date::WeekNumber() const
{
    return (dayNum - Date(1, 1, year).daysFromTheStart()) / 7 + 1;
}

int Date::DaysTillYourBithday(Date bithdaydate) const
{
    if (this->copy().daysFromTheStart() < Date(bithdaydate.Day(), bithdaydate.Month(), year).daysFromTheStart())
    {
        return this->copy().Duration(Date(bithdaydate.Day(), bithdaydate.Month(), year));
    }
    else if (this->copy().daysFromTheStart() > Date(bithdaydate.Day(), bithdaydate.Month(), year).daysFromTheStart())
    {
        return this->Duration(Date(bithdaydate.Day(), bithdaydate.Month(), year + 1));
    }
    else
    {
        return 0;
    }
}

int Date::Duration(Date date) const
{
    return qAbs(date.daysFromTheStart() - this->copy().daysFromTheStart());
}


//***********************************************************************************//


unsigned Date::daysFromTheStart()
{
    dayNum = 0;
    int tYear = year - 1;


    if (tYear >= 400)
    {
        dayNum += y400 * (tYear / 400);
        tYear %= 400;
    }
    if (tYear >= 100)
    {
        dayNum += y100 * (tYear / 100);
        tYear %= 100;
    }
    if (tYear >= 4)
    {
        dayNum += y4 * (tYear / 4);
        tYear %= 4;
    }
    dayNum += 365 * tYear;

    for (int i = 1; i < month; ++i)
    {
        dayNum += Date (1, i, year).DaysInMonth();
    }
    dayNum += day;

    return dayNum;
}

unsigned Date::DaysInMonth() const
{
    if (month == 4 ||
        month == 6 ||
        month == 9 ||
        month == 11)
    {
        return 30u;
    }
    if (month == 2)
    {
        return this->IsLeap() ? 29u : 28u;
    }
    else
    {
        return 31u;
    }
}

QString Date::getQStrDate() const
{
    QString retString;
    retString += QString::number(day / 10) + QString::number(day % 10) + '.' +
                 QString::number(month / 10) + QString::number(month % 10) + '.';
    int tYear = year;
    retString += ("    ");
    for (int i = 4; i > 0; --i)
    {
        retString.replace(5 + i, 1, char(tYear % 10 + '0'));
        tYear /= 10;
    }

    return retString;
}

void Date::standardize()
{
    if (year == 0)
    {
        year = 1;
    }
    if (month > 12)
    {
        year += month / 12;
        if (year == 0)
        {
            year = 1;
        }
        month %= 12;
    }

    while (day > this->DaysInMonth())
    {
        day -= this->DaysInMonth();
        ++month;

        if (month > 12)
        {
            year += month / 12;
            if (year == 0)
            {
                year = 1;
            }
            month %= 12;
        }
    }

    this->daysFromTheStart();
}

Date Date::copy() const
{
    return Date(this->Day(), this->Month(), this->Year());
}


//***********************************************************************************//


Date& Date::operator = (const Date otherDate)
{
    this->day = otherDate.Day();
    this->month = otherDate.Month();
    this->year = otherDate.Year();

    return *this;
}
