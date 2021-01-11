#pragma once
#ifndef MAYVIP_H_INCLUDED
#define MAYVIP_H_INCLUDED
#include "may.h"

class mayVip:public May
{
public:
    int thanhtien();
    string info();
    mayVip(int n);
    void display(){
        cout<<"VIP"<<ID<<"  "<<trangThai;
    }
};
#endif // MAYVIP_H_INCLUDED
