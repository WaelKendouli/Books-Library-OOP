#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "clsDate.h"

class clsPeriod : public clsDate
{
public:
    clsDate StartDate;
    clsDate EndDate;
    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }
    clsPeriod()
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }
 

    static   bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before ||
            CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
            return false;
        else
            return true;
    }
    bool IsOverlapPeriods(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    static  int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
    }
    int PeriodLengthInDays()
    {
        return PeriodLengthInDays(*this, true);
    }
    static bool IsDateWithinPeriod(clsDate Date, clsPeriod Period)
    {
        return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before ||
            CompareDates(Date, Period.EndDate) == enDateCompare::After);
    }
    bool IsDateWithinPeriod(clsDate Date)
    {
        return  IsDateWithinPeriod(Date, *this);
    }
 


    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};

