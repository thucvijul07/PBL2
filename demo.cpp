#include <iostream>
#include "Management.h"
#include <conio.h>
#include <fstream>
#include <sstream>
using namespace std;
Management H;

void menuTX()
{
    char optionX;
    do {
        cout << endl<< "      1. Them vat tu  " << endl;
        cout << "      2. Xoa vat tu" << endl;
        cout << "      3. Quay lai" << endl;
        cout << "Moi ban lua chon: ";
        cin >> optionX;
        system("cls");
        switch (optionX)
        {
            case ('1'):
            {
                H.Add();
                system("pause");
                system("cls");
                break;
            }
        case ('2'):
        {
            H.Delete();
            system("pause");
            system("cls");
            break;
        }
        }
    } while (optionX != '3');
}
void menuSort()
{
    int Op;
    do{
        cout << "   1. Sap xep theo thu tu tang dan"<< endl;
        cout << "   2. Sap xep theo thu tu giam dan"<< endl;
        cout << "   3. Quay lai" << endl<<endl;
        cout << "Moi ban lua chon: ";
        cin >> Op;
        system("cls");
        switch (Op)
        {
            case(1):
            {
                H.Sort(Op);
                system("pause");
                system("cls");
                break;
            }
            case(2):
            {
                H.Sort(Op);
                system("pause");
                system("cls");
                break;      
            }
        }
        } while(Op != 3);
    }
void menuNhap()
{
    char optionA;
    do {
        cout << endl<< "      1. Don Nhap " << endl;
        cout << "      2. Danh sach vat tu da nhap" << endl;
        cout << "      3. Quay lai" << endl;
        cout << "Moi ban lua chon: ";
        cin >> optionA;
        system("cls");
        switch (optionA)
        {
            case ('1'):
            {
                H.InsertOrderIn();
                system("pause");
                system("cls");
                break;
            }
        case ('2'):
        {
            H.ShowListIn();
            system("pause");
            system("cls");
            break;
        }
        }
    } while (optionA != '3');
}
void menuXuat()
{
    char optionB;
    do{
        cout << endl << "    1. Don xuat " << endl;
        cout << "    2. Danh sach vat tu da xuat" << endl;
        cout << "    3. Quay lai" << endl;
        cout << "Moi ban lua chon: ";
        cin >> optionB;
        system("cls");
        switch (optionB)
            {
            case ('1'):
            {
                H.InsertOrderOut();
                system("pause");
                system("cls");
                break;
            }
            case ('2'):
            {
                H.ShowListOut();
                system("pause");
                system("cls");
                break;
            }
            }
    } while (optionB != '3');
} 
void menuUpdate()
{
    int uOption;
    do{
        cout << "1. Ten vat tu"<< endl;
        cout << "2. Loai vat tu"<< endl;
        cout << "3. So luong vat tu"<< endl;
        cout << "4. Don vi vat tu"<< endl;
        cout << "5. Nuoc san xuat"<< endl;
        cout << "6. Quay lai" << endl<<endl;
        cout << "Moi ban lua chon: ";
        cin >> uOption;
        system("cls");
        switch (uOption)
        {
            case(1):
            {
                H.Update(uOption);
                system("pause");
                system("cls");
                break;
            }
            case(2):
            {
                H.Update(uOption);
                system("pause");
                system("cls");
                break;      
            }
            case(3):
            {
                H.Update(uOption);
                system("pause");
                system("cls");
                break;  
            }
            case(4):
            {
                H.Update(uOption);
                system("pause");
                system("cls");
                break;   
            }
            case(5):
            {
                H.Update(uOption);
                system("pause");
                system("cls");
                break;   
            }
        }
    } while(uOption != 6);
}
char menu()
{
    char choice;
    cout << "*----------------------TRUONG DAI HOC BACH KHOA DAI HOC DA NANG-----------------------*"<< endl
         << "*                             KHOA CONG NGHE THONG TIN                                *"<< endl
         << "*                                                                                     *" << endl
         << "*                            PBL2: DO AN CO SO LAP TRINH                              *" << endl
         << "*                      DE TAI: XAY DUNG HE THONG QUAN LI VAT TU                       *" << endl
         << "*                                                                                     *" << endl
         << "*--------------------------------------MENU-------------------------------------------*" << endl
         << "*            1. Hien thi thong tin vat tu                                             *" << endl
         << "*            2. Them hoac xoa vat tu                                                  *" << endl
         << "*            3. Thong tin ve nhap vat tu                                              *" << endl
         << "*            4. Thong tin ve xuat vat tu                                              *" << endl
         << "*            5. Tim kiem thong tin vat tu                                             *" << endl
         << "*            6. Sap xep danh sach vat tu theo so luong                                *" << endl
         << "*            7. Thong ke vat tu                                                       *" << endl
         << "*            8. Cap nhat lai thong tin vat tu                                         *" << endl
         << "*            9. Thoat                                                                 *" << endl
         << "*-------------------------------------------------------------------------------------*" << endl
         << "Moi ban lua chon: ";
    cin >> choice;
    return (choice);
}
int main()
{
    // mo dau
    H.Start();
    char choice;
    system("cls");
    do
    {
        choice = menu();
        system("cls");
        switch (choice)
        {
            case ('1'):
            {
                H.ShowListSup();
                system("pause");
                system("cls");
                break;
            }
            case ('2'):
            {
                system("cls");
                menuTX();
                break;
            }
            case ('3'):
            {
                system("cls");
                menuNhap();
                break;
            }
            case ('4'):
            {
                system("cls");
                menuXuat();
                break;
            }
            case ('5'):
            {
                H.Search();
                system("pause");
                system("cls");
                break;
            }
            case ('6'):
            {
                system("cls");
                menuSort();
                break;
            }
            case ('7'):
            {
                H.ThongKe();
                system("pause");
                system("cls");
                break;
            }
            case ('8'):
            {
                menuUpdate();
                break;
            }
            default:
            {
                cout << "Vui long chon lai tu 1 -> 9 "<<endl << endl << endl;
                break;
            }
        }
    } while (choice != '9');
    return 0;
}