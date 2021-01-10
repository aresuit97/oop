#pragma once
#ifndef MAY_H_INCLUDED
#define MAY_H_INCLUDED
#include <ctime>
#include <string>
 using namespace std;

static int giaTienMayThuong,giaTienMayVip;
class May
{

     int  ID;
    bool trangThai;
    string s;
public:
    virtual string info();
    virtual int thanhtien();
     int getID();
    void doiTrangThai();
};


#endif // MAY_H_INCLUDED
