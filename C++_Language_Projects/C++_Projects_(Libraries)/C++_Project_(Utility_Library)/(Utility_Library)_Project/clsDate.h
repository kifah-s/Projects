#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "clsString.h"

using namespace std;

class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:
    // ==================== Constructors ====================
    clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(string sDate)
    {
        vector<string> vDate = clsString::Split(sDate, "/");
        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(short DateOrderInYear, short Year)
    {
        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date1.GetDay();
        _Month = Date1.GetMonth();
        _Year = Date1.GetYear();
    }

    // ==================== Getters & Setters (Clear & Portable) ====================
    void SetDay(short Day) { _Day = Day; }
    short GetDay() const { return _Day; }

    void SetMonth(short Month) { _Month = Month; }
    short GetMonth() const { return _Month; }

    void SetYear(short Year) { _Year = Year; }
    short GetYear() const { return _Year; }
    // =============================================================================

    void Print()
    {
        cout << DateToString() << endl;
    }

    // ==================== Static Helpers ====================
    static clsDate GetSystemDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        return clsDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    }

    static bool IsValidDate(clsDate Date)
    {
        if (Date.GetDay() < 1 || Date.GetDay() > 31)
            return false;
        if (Date.GetMonth() < 1 || Date.GetMonth() > 12)
            return false;

        if (Date.GetMonth() == 2)
        {
            if (isLeapYear(Date.GetYear()))
                return Date.GetDay() <= 29;
            else
                return Date.GetDay() <= 28;
        }

        return Date.GetDay() <= NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
    }

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date.GetDay()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetYear());
    }

    string DateToString()
    {
        return DateToString(*this);
    }

    static bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear() const
    {
        return isLeapYear(_Year);
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365;
    }

    short NumberOfDaysInAYear() const
    {
        return NumberOfDaysInAYear(_Year);
    }

    static short NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }

    short NumberOfHoursInAYear() const
    {
        return NumberOfHoursInAYear(_Year);
    }

    static int NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }

    int NumberOfMinutesInAYear() const
    {
        return NumberOfMinutesInAYear(_Year);
    }

    static int NumberOfSecondsInAYear(short Year)
    {
        return NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfSecondsInAYear() const
    {
        return NumberOfSecondsInAYear(_Year);
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    short NumberOfDaysInAMonth() const
    {
        return NumberOfDaysInAMonth(_Month, _Year);
    }

    static short NumberOfHoursInAMonth(short Month, short Year)
    {
        return NumberOfDaysInAMonth(Month, Year) * 24;
    }

    short NumberOfHoursInAMonth() const
    {
        return NumberOfDaysInAMonth(_Month, _Year) * 24;
    }

    static int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return NumberOfHoursInAMonth(Month, Year) * 60;
    }

    int NumberOfMinutesInAMonth() const
    {
        return NumberOfHoursInAMonth(_Month, _Year) * 60;
    }

    static int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return NumberOfMinutesInAMonth(Month, Year) * 60;
    }

    int NumberOfSecondsInAMonth() const
    {
        return NumberOfMinutesInAMonth(_Month, _Year) * 60;
    }

    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + 12 * a - 2;
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
    }

    short DayOfWeekOrder() const
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        string arr[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return arr[DayOfWeekOrder];
    }

    static string DayShortName(short Day, short Month, short Year)
    {
        return DayShortName(DayOfWeekOrder(Day, Month, Year));
    }

    string DayShortName() const
    {
        return DayShortName(DayOfWeekOrder());
    }

    static string MonthShortName(short MonthNumber)
    {
        string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        return Months[MonthNumber - 1];
    }

    string MonthShortName() const
    {
        return MonthShortName(_Month);
    }

    static void PrintMonthCalendar(short Month, short Year)
    {
        int current = DayOfWeekOrder(1, Month, Year);
        int NumberOfDays = NumberOfDaysInAMonth(Month, Year);

        printf("\n _______________%s_______________\n\n", MonthShortName(Month).c_str());
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        for (int i = 0; i < current; i++)
            printf("    ");

        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%4d", j);
            if (++current == 7)
            {
                current = 0;
                printf("\n");
            }
        }
        printf("\n _________________________________\n");
    }

    void PrintMonthCalendar() const
    {
        PrintMonthCalendar(_Month, _Year);
    }

    static void PrintYearCalendar(int Year)
    {
        printf("\n _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf(" _________________________________\n");
        for (int i = 1; i <= 12; i++)
            PrintMonthCalendar(i, Year);
    }

    void PrintYearCalendar() const
    {
        PrintYearCalendar(_Year);
    }

    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {
        short Total = 0;
        for (int i = 1; i < Month; i++)
            Total += NumberOfDaysInAMonth(i, Year);
        return Total + Day;
    }

    short DaysFromTheBeginingOfTheYear() const
    {
        return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate Date;
        short RemainingDays = DateOrderInYear;
        Date.SetYear(Year);
        Date.SetMonth(1);

        while (true)
        {
            short MonthDays = NumberOfDaysInAMonth(Date.GetMonth(), Year);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.SetMonth(Date.GetMonth() + 1);
            }
            else
            {
                Date.SetDay(RemainingDays);
                break;
            }
        }
        return Date;
    }

    void AddDays(short Days)
    {
        short RemainingDays = Days + DaysFromTheBeginingOfTheYear();
        _Month = 1;
        while (true)
        {
            short MonthDays = NumberOfDaysInAMonth(_Month, _Year);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                _Month++;
                if (_Month > 12)
                {
                    _Month = 1;
                    _Year++;
                }
            }
            else
            {
                _Day = RemainingDays;
                break;
            }
        }
    }

    // ==================== Date Comparison ====================
    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.GetYear() < Date2.GetYear()) ? true : (Date1.GetYear() == Date2.GetYear()) ? (Date1.GetMonth() < Date2.GetMonth() ? true : (Date1.GetMonth() == Date2.GetMonth() ? Date1.GetDay() < Date2.GetDay() : false))
                                                                                                 : false;
    }

    bool IsDateBeforeDate2(clsDate Date2) const
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return Date1.GetYear() == Date2.GetYear() &&
               Date1.GetMonth() == Date2.GetMonth() &&
               Date1.GetDay() == Date2.GetDay();
    }

    bool IsDateEqualDate2(clsDate Date2) const
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return Date.GetDay() == NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
    }

    bool IsLastDayInMonth() const
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return Month == 12;
    }

    static clsDate AddOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.GetMonth()))
            {
                Date.SetMonth(1);
                Date.SetDay(1);
                Date.SetYear(Date.GetYear() + 1);
            }
            else
            {
                Date.SetDay(1);
                Date.SetMonth(Date.GetMonth() + 1);
            }
        }
        else
        {
            Date.SetDay(Date.GetDay() + 1);
        }
        return Date;
    }

    void AddOneDay()
    {
        *this = AddOneDay(*this);
    }

    static void SwapDates(clsDate &Date1, clsDate &Date2)
    {
        clsDate Temp = Date1;
        Date1 = Date2;
        Date2 = Temp;
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlag = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SwapFlag = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = AddOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SwapFlag : Days * SwapFlag;
    }

    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false) const
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return GetDifferenceInDays(DateOfBirth, GetSystemDate(), true);
    }

    // ==================== Increase Date ====================
    static clsDate IncreaseDateByOneWeek(clsDate &Date)
    {
        for (int i = 0; i < 7; i++)
            Date = AddOneDay(Date);
        return Date;
    }

    void IncreaseDateByOneWeek()
    {
        IncreaseDateByOneWeek(*this);
    }

    clsDate IncreaseDateByXWeeks(short Weeks, clsDate &Date)
    {
        for (short i = 0; i < Weeks; i++)
            Date = IncreaseDateByOneWeek(Date);
        return Date;
    }

    void IncreaseDateByXWeeks(short Weeks)
    {
        IncreaseDateByXWeeks(Weeks, *this);
    }

    static clsDate IncreaseDateByOneMonth(clsDate &Date)
    {
        if (Date.GetMonth() == 12)
        {
            Date.SetMonth(1);
            Date.SetYear(Date.GetYear() + 1);
        }
        else
            Date.SetMonth(Date.GetMonth() + 1);

        short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > DaysInMonth)
            Date.SetDay(DaysInMonth);
        return Date;
    }

    void IncreaseDateByOneMonth()
    {
        IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXDays(short Days, clsDate &Date)
    {
        for (short i = 0; i < Days; i++)
            Date = AddOneDay(Date);
        return Date;
    }

    void IncreaseDateByXDays(short Days)
    {
        IncreaseDateByXDays(Days, *this);
    }

    static clsDate IncreaseDateByXMonths(short Months, clsDate &Date)
    {
        for (short i = 0; i < Months; i++)
            Date = IncreaseDateByOneMonth(Date);
        return Date;
    }

    void IncreaseDateByXMonths(short Months)
    {
        IncreaseDateByXMonths(Months, *this);
    }

    static clsDate IncreaseDateByOneYear(clsDate &Date)
    {
        Date.SetYear(Date.GetYear() + 1);
        return Date;
    }

    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYears(short Years, clsDate &Date)
    {
        Date.SetYear(Date.GetYear() + Years);
        return Date;
    }

    void IncreaseDateByXYears(short Years)
    {
        IncreaseDateByXYears(Years, *this);
    }

    static clsDate IncreaseDateByOneDecade(clsDate &Date)
    {
        Date.SetYear(Date.GetYear() + 10);
        return Date;
    }

    void IncreaseDateByOneDecade()
    {
        IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecades(short Decades, clsDate &Date)
    {
        Date.SetYear(Date.GetYear() + Decades * 10);
        return Date;
    }

    void IncreaseDateByXDecades(short Decades)
    {
        IncreaseDateByXDecades(Decades, *this);
    }

    static clsDate IncreaseDateByOneCentury(clsDate &Date)
    {
        Date.SetYear(Date.GetYear() + 100);
        return Date;
    }

    void IncreaseDateByOneCentury()
    {
        IncreaseDateByOneCentury(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate &Date)
    {
        Date.SetYear(Date.GetYear() + 1000);
        return Date;
    }

    void IncreaseDateByOneMillennium()
    {
        IncreaseDateByOneMillennium(*this);
    }

    // ==================== Decrease Date ====================
    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date.GetDay() == 1)
        {
            if (Date.GetMonth() == 1)
            {
                Date.SetMonth(12);
                Date.SetDay(31);
                Date.SetYear(Date.GetYear() - 1);
            }
            else
            {
                Date.SetMonth(Date.GetMonth() - 1);
                Date.SetDay(NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear()));
            }
        }
        else
        {
            Date.SetDay(Date.GetDay() - 1);
        }
        return Date;
    }

    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByOneWeek(clsDate &Date)
    {
        for (int i = 0; i < 7; i++)
            Date = DecreaseDateByOneDay(Date);
        return Date;
    }

    void DecreaseDateByOneWeek()
    {
        DecreaseDateByOneWeek(*this);
    }

    // ==================== Business & Vacation ====================
    static bool IsEndOfWeek(clsDate Date)
    {
        return DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()) == 6;
    }

    bool IsEndOfWeek() const
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        short d = DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear());
        return d == 5 || d == 6;
    }

    bool IsWeekEnd() const
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay() const
    {
        return IsBusinessDay(*this);
    }

    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;
            DateFrom = AddOneDay(DateFrom);
        }
        return Days;
    }

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {
        short WeekEndCounter = 0;
        for (short i = 1; i <= VacationDays; i++)
        {
            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;
            DateFrom = AddOneDay(DateFrom);
        }
        for (short i = 1; i <= WeekEndCounter; i++)
            DateFrom = AddOneDay(DateFrom);
        return DateFrom;
    }

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return Before;
        if (IsDate1EqualDate2(Date1, Date2))
            return Equal;
        return After;
    }

    enDateCompare CompareDates(clsDate Date2) const
    {
        return CompareDates(*this, Date2);
    }
};