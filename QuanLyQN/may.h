#pragma once
#ifndef MAY_H_INCLUDED
#define MAY_H_INCLUDED
#include <ctime>

class May
{
    //static int giaTienMayThuong,giaTienMayVip;
    unsigned int  ID;
    bool trangThai;
    time_t timeIn;
public:
    virtual string info();
    virtual int thanhtien();
    void moMay();
    unsigned int getID();
    void doiTrangThai();
};


#endif // MAY_H_INCLUDED
