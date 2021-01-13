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
    void taoThanhVien(ThanhVien* tv);
    void display();
    int getSL();
    void setSL(int sl);
    ThanhVien** getds();
    void reset();
    void setDSTV(ThanhVien** tv);
    bool check(string user);
    void xoaThanhVien (int pos);
    void capNhatVip();
    ThanhVien* searcH(string tentv);
};

#endif // QLTHANHVIEN_H_INCLUDED
