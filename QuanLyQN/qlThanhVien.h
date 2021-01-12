#pragma once
#ifndef QLTHANHVIEN_H_INCLUDED
#define QLTHANHVIEN_H_INCLUDED

#include "thanhVien.h"

class qlThanhVien
{
    int soLuongTV;
    ThanhVien** tv;
public:
    qlThanhVien();
    void themTV(ThanhVien* tv);
    void nhapTuFile();
    void xuatraFile();
    void taoThanhVien(ThanhVien* tv);
    void display();
    int getSL(){return soLuongTV;}
    void setSL(int sl){soLuongTV=sl;}
    ThanhVien** getds();
    void reset();
    void setDSTV(ThanhVien** tv);
    bool check(string user);
    void xoaThanhVien (int pos);
};

#endif // QLTHANHVIEN_H_INCLUDED
