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
    void display();
};
#endif // MAYVIP_H_INCLUDED
