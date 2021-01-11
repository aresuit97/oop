#pragma once
#ifndef MAYVIP_H_INCLUDED
#define MAYVIP_H_INCLUDED
#include "may.h"

class mayVip:public May
{
public:
    int thanhtien();
    string info();
    void doiTrangThai();
    void setID(int id);
};
#endif // MAYVIP_H_INCLUDED
