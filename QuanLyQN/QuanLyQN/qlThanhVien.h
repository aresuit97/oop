#pragma once
#ifndef QLTHANHVIEN_H_INCLUDED
#define QLTHANHVIEN_H_INCLUDED

#include "thanhVien.h"

class qlThanhVien
{
    int soLuong;
    ThanhVien** tv;
public:
    qlThanhVien();
    void themTV(ThanhVien* tv);
    void nhapTuFile();
    void xuatraFile();
    void taoThanhVien(ThanhVien* tv);
    void display();
    bool check(string username);
    int getSL(){return soLuong;}
    void setSL(int sl){soLuong=sl;}
    ThanhVien** getds();
    void reset();
    void setDSTV(ThanhVien** tv);
};

#endif // QLTHANHVIEN_H_INCLUDED
