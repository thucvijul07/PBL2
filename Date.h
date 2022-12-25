#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Date {
    private:
        int D,M,Y;
    public:
        Date();
        ~Date();
        void SetDay(int day);
        int GetDay();
        void SetMonth(int month);
        int GetMonth();
        void SetYear(int year);
        int GetYear();
};
Date::Date(){
    this->D=0;
    this->M=0;
    this->Y=0;
}
Date::~Date(){
}
void Date::SetDay(int day){
    if (day>=1 && day<=31) this->D=day;
}
void Date::SetMonth(int month){
    if (month>=1 && month<=12) this->M=month;
}
void Date::SetYear(int year)
{
    this->Y=year;
}
int Date::GetDay()
{
    return this->D;
}
int Date::GetMonth()
{
    return this->M;
}
int Date::GetYear()
{
    return this->Y;
}
