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
    int thoiGianChoi,soTien;
    string username,pw,ten;
    string sdt;
    float uuDai;
public:
    ThanhVien();
    string getUsername();
    void taoTV();
    void thongTinTaiKhoan();
    void capNhapVip();
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
