#pragma once
#ifndef MAY_H_INCLUDED
#define MAY_H_INCLUDED
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

static int giaTienMayThuong=8000,giaTienMayVip=1000;
class May
{
protected:
    int  ID;
    bool trangThai;
public:
    virtual string info();
    virtual float thanhtien();
    int getID();
    void doiTrangThai();
    void setID(int n);
    May(int n);
    May();
    virtual void display();

    bool getTrangThai();


};


#endif // MAY_H_INCLUDED
