#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Supplies
{
    public:
        class Order;
    private:
        string ID;
        string Ten;
        string Loai;
        int Count;
        string DonVi;
        string Origin;
    public:
        Supplies();
        ~Supplies();
        string GetID();
        void SetID(string id);
        string GetTen();
        void SetTen(string t);
        string GetLoai();
        void SetLoai(string l);
        int GetCount();
        void SetCount(int c);
        string GetDonVi();
        void SetDonVi(string dv);
        string GetOrigin();
        void SetOrigin(string nc);
        void Show();
        const Supplies& operator=( const Supplies&);
};

Supplies::Supplies()
{
    this->ID="";
    this->Ten="";
    this->Loai="";
    this->Count=0;
    this->DonVi="";
    this->Origin="";
}
Supplies::~Supplies()
{
}
string Supplies::GetID(){
    return this->ID;
}
string Supplies::GetTen(){
    return this->Ten;
}
string Supplies::GetLoai(){
    return this->Loai;
}
int Supplies::GetCount(){
    return this->Count;
}
string Supplies::GetDonVi(){
    return this->DonVi;
}
string Supplies::GetOrigin(){
    return this->Origin;
}
void Supplies::SetID(string id){
    this->ID=id;
}
void Supplies::SetTen(string t){
    this->Ten=t;
}
void Supplies::SetLoai(string l){
    this->Loai=l;
}
void Supplies::SetCount(int c){
    this->Count=c;
}
void Supplies::SetDonVi(string dv){
    this->DonVi=dv;
}
void Supplies::SetOrigin(string ori){
    this->Origin=ori;
}
void Supplies::Show(){
    cout << "|" << setw(3) << "     " << setw(9) << left << this->GetID() << left << "|"
    << setw(3) << "   " << setw(11) << left << this->GetTen() << left << "|"
    << setw(3) << "   " << setw(13) << left << this->GetLoai() << left << "|"
    << setw(3) << "    " << setw(7) << right << this->GetCount() << left << "   |"
    << setw(3) << "   " << setw(11) << left << this->GetDonVi() << left << "|"
    << setw(3) << "      " << setw(13) << left << this->GetOrigin() << left << "|" << endl;
}
const Supplies& Supplies::operator=(const Supplies& v)
{
    this->ID = v.ID;
    this->Ten = v.Ten;
    this->Loai = v.Loai;
    this->Count = v.Count;
    this->DonVi = v.DonVi;
    this->Origin = v.Origin;
    return *this;
}