#pragma once
#ifndef MAYVIP_H_INCLUDED
#define MAYVIP_H_INCLUDED
#include "may.h"

class mayVip:public May
{
public:
    float thanhtien();
    string info();
    mayVip(int n);
    void display(){
        cout<<"VIP"<<ID<<"  ";
        if(trangThai)cout<<"Dang dung"<<endl;
        else cout<<"Dang tat"<<endl;
    }
};
#endif // MAYVIP_H_INCLUDED
