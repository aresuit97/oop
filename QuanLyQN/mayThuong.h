#pragma once
#ifndef MAYTHUONG_H_INCLUDED
#define MAYTHUONG_H_INCLUDED
#include "may.h"

using namespace std;

class mayThuong:public May
{
public:

    int thanhtien();
    string info();
    void doiTrangThai();
    void setID(int id);

};


#endif // MAYTHUONG_H_INCLUDED
