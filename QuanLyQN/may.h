#pragma once
#ifndef MAY_H_INCLUDED
#define MAY_H_INCLUDED
#include <ctime>
#include <string>
#include <iostream>
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
    int getID();
    void doiTrangThai();
    void setID(int n);
    May(int n);
    May();
    virtual void display();

    bool getTrangThai();


};


#endif // MAY_H_INCLUDED
