#pragma once
#ifndef THANHVIEN_H_INCLUDED
#define THANHVIEN_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "tool.h"
using namespace std;
class ThanhVien
{
    int thoiGianChoi,soTien;
    string username,pw,ten,sdt;
    float uuDai;
public:
    ThanhVien();
    ThanhVien(string username,string pw,string ten,string sdt,int soTien,int thoiGianChoi,float uuDai);
    string getUsername();
    void thongTinTaiKhoan();
    void taoTV();
    void capNhatVip();
    void napTien();
    void suaThongTin();
    float getUudai();
    int getTien();
    void setTien (int i);
    void congThoiGian(int n);
    string getTen();
    string getPW();
    string getSDT();
    int getThoiGianChoi();
    void setUsername(string temp);
    void setPW(string temp);
    void  setTen(string temp);
    void setSDT(string temp);
    void setThoiGianChoi(int  thoiGian);
    void setUuDai(float uuDai);

};

#endif // THANHVIEN_H_INCLUDED
