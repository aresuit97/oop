#pragma once
#ifndef MAYVIP_H_INCLUDED
#define MAYVIP_H_INCLUDED
#include "may.h"

class mayVip:public may()
{
public:
    int thanhtien()
    {
        giaTienVip;
    };
    string info(){
    return "VIP";
    }

#endif // MAYVIP_H_INCLUDED
