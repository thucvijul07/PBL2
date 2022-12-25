#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
#include "Date.h"
#include "Supplies.h"
using namespace std;

class Order : public Date, public Supplies
{
    private:
        string IDorder;
        int SLorder;
        int Gia;
    public:
        Order();
        ~Order();
        string GetIDorder();
        void SetIDorder(string ido);
        int GetSLorder();
        void SetSLorder(int sl);
        int GetGia();
        void SetGia(int g);
        void Show();
};

Order::Order()
{
    this->IDorder="";
    this->SLorder=0;
    this->Gia=0;
}
Order::~Order()
{
}
string Order::GetIDorder(){
    return this->IDorder;
}

int Order::GetSLorder(){
    return this->SLorder;
}
int Order::GetGia(){
    return this->Gia;
}
void Order::SetIDorder(string ido){
    this->IDorder=ido;
}
void Order::SetSLorder(int sl){
    this->SLorder=sl;
}
void Order::SetGia(int g){
    this->Gia=g;
}
void Order::Show(){
    cout << "|" << setw(3) << "     " << setw(10) << left << this->GetIDorder() << "|"
    << setw(3) << "   " << right << setw(2) << this->GetDay()<< "/" << setw(2) << this->GetMonth() << "/" << this->GetYear() << "   "<< left << "|"
    << setw(4) << "    " << setw(9) << left << this->GetID() << left << "|"
    << setw(3) << "   " << setw(11) << left << this->GetTen() << left << "|"
    << setw(3) << "   " << setw(13) << left << this->GetLoai() << left << "|"
    << setw(5) << "     " << setw(6) << right << this->GetSLorder() << left << "   |"
    << setw(3) << "      " << setw(9) << right << this->GetGia() << left << "  |" << endl;
}


