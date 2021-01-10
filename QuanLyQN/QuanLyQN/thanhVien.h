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
    ThanhVien();
    string getUsername();
    void taoTV();
    void thongTinTaiKhoan();
    void capNhapVip();
    void napTien();
    void suaThongTin();

};

#endif // THANHVIEN_H_INCLUDED
