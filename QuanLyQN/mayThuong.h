#pragma once
#ifndef MAYTHUONG_H_INCLUDED
#define MAYTHUONG_H_INCLUDED
#include "may.h"

class mayThuong:public may()
{
public:

    int thanhtien()
    {
            return giaTienThuong;
    }
    string info(){
            return "thuong";
    }

};


#endif // MAYTHUONG_H_INCLUDED
