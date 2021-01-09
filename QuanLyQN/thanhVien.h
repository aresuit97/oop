#pragma once
#ifndef THANHVIEN_H_INCLUDED
#define THANHVIEN_H_INCLUDED
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include "menu.h"

using namespace std;

class ThanhVien
{
    float soGioChoi;
    int soTien;
    string username,pw,ten;
    string sdt;
    float uuDai;
public:
    ThanhVien()
    {
        soGioChoi=0;
        soTien=0;
        username=pw=ten=sdt="";
        uuDai=1;
    }
    string getUsername()
    {
        return username;
    }

    string getPW()
    {
        return pw;
    }

    void taoTV()
    {
        fflush(stdin);
        cout<<"Nhap ten moi: ";
        getline(cin,this->ten);
        cout<<"Nhap sdt moi: ";
        cin>>sdt;
        cout<<"Nhap mat khau: " ;
        string newPW;
        cin >>newPW;
        cout<<"Nhap lai mat khau: ";
        string tempPW;
        cin >>tempPW;
        while (newPW!=tempPW)
        {
            cout<<"Mat khau ban nhap khong trung khop. Vui long nhap lai."<<endl;
            cout<<"Nhap mat khau moi: " ;
            cin >>newPW;
            cout<<"Nhap lai mat khau: ";
            cin >>tempPW;
        }
        pw=newPW;
        cout<<"Nhap so tien nap lan dau: ";
        cin>>soTien;
        cout<<"Da tao thanh vien moi.";
    }

    void thongTinTaiKhoan()
    {
        cout<<setw(10)<<left<<"Username "<<":"<<setw(40)<<right<< username<<endl;
        cout<<setw(10)<<left<<"Ten "<<":"<<setw(40)<<right<< ten<<endl;
        cout<<setw(10)<<left<<"SDT "<<":"<<setw(40)<<right<< sdt<<endl;
        cout<<setw(10)<<left<<"Loai TK"<<":";
        if(uuDai==1)cout<<setw(40)<<right<<"Thuong"<<endl;
        else cout<<setw(40)<<right<<"VIP"<<endl;
    }
};

#endif // THANHVIEN_H_INCLUDED
