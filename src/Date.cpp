#include "Date.h"
#include <iostream>
using namespace std;
Date::Date()
{
    Day=Month=Year=0;
}
Date::Date(int Day,int Month,int Year)
{
    if(Day<=0||(Month%2==0&&Day>30)||(Month==2&&Day>28)||Day>31)
    {
A1:
        cout<<"The Day You entered is incorrect you have to re-enter :";
        cin>>this->Day;
        if(this->Day<=0||(Month%2==0&&this->Day>30)||(Month==2&&this->Day>28)||this->Day>31)
            goto A1;
    }
    this->Day=Day;
    if(Month<=0||Month>12)
    {
A2:
        cout<<"The Month You entered is incorrect you have to re-enter :";
        cin>>this->Month;
        if(this->Month<=0||this->Month>12)
            goto A2;
    }
    this->Month=Month;
    if(Year<1910||Year>2021)
    {
A3:
        cout<<"The Year You entered is incorrect you have to re-enter :";
        cin>>this->Year;
        if(this->Year<1910||this->Year>2021)
            goto A3;
    }
    this->Year=Year;
}
Date::Date(Date &ob)
{
    this->Year=ob.Year;
    this->Month=ob.Month;
    this->Day=ob.Day;
}
void Date::SetDay(int Day)
{
    if(Day<=0||(Month%2==0&&Day>30)||(Month==2&&Day>28)||Day>31)
    {
B1:
        cout<<"The Day You entered is incorrect you have to re-enter :";
        cin>>this->Day;
        if(this->Day<=0||(Month%2==0&&this->Day>30)||(Month==2&&this->Day>28)||this->Day>31)
            goto B1;
    }
    this->Day=Day;
}
void Date::SetMonth(int Month)
{
    if(Month<=0||Month>12)
    {
B2:
        cout<<"The Month You entered is incorrect you have to re-enter :";
        cin>>this->Month;
        if(this->Month<=0||this->Month>12)
            goto B2;
    }
    this->Month=Month;
}
void Date::SetYear(int Year)
{
    if(Year<1910||Year>2021)
    {
B3:
        cout<<"The Year You entered is incorrect you have to re-enter :";
        cin>>this->Year;
        if(this->Year<1910||this->Year>2021)
            goto B3;
    }
    this->Year=Year;
}
int Date::GetDay()
{
    return Day;
}
int Date::GetMonth()
{
    return Month;
}
int Date::GetYear()
{
    return Year;
}
void Date::input_Date()
{
C1:
    cout<<"Enter Year :";
    cin>>Year;
    if(Year<1910||Year>2021)
    {
        cout<<"The Year You entered is incorrect you have to re-enter :";
        cin>>this->Year;
        if(this->Year<1910||this->Year>2021)
            goto C1;
    }
C2:
    cout<<"Enter Month :";
    cin>>Month;
    if(Month<=0||Month>12)
    {
        cout<<"The Month You entered is incorrect you have to re-enter :";
        cin>>this->Month;
        if(this->Month<=0||this->Month>12)
            goto C2;
    }
C3:
    cout<<"Enter Day :";
    cin>>Day;
    if(Day<=0||(Month%2==0&&Day>30)||(Month==2&&Day>28)||Day>31)
    {
        cout<<"The Day You entered is incorrect you have to re-enter :";
        cin>>this->Day;
        if(this->Day<=0||(Month%2==0&&this->Day>30)||(Month==2&&this->Day>28)||this->Day>31)
            goto C3;
    }
}
void Date::print_Date()
{
    cout<<"the date is :"<<Year<<"/"<<Month<<"/"<<Day<<endl;
}
