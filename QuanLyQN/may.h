#pragma once
#ifndef MAY_H_INCLUDED
#define MAY_H_INCLUDED
#include <ctime>
#include <string>
 using namespace std;

static int giaTienMayThuong,giaTienMayVip;
class May
{
protected:
    int  ID;
    bool trangThai;
public:
    virtual string info();
    virtual int thanhtien();
    int getID(){return ID;};
    virtual void doiTrangThai();
    virtual void setID()=0;
};


#endif // MAY_H_INCLUDED
