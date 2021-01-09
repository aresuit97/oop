#pragma once
#ifndef MAYTHUONG_H_INCLUDED
#define MAYTHUONG_H_INCLUDED
#include "may.h"

class mayThuong:public may()
{
public:

    int thanhtien()
    {
        if(tv!=null)
            return difftime(time(0),timeIn)*giaTienThuong*tv.uuDai;
        else return difftime(time(0),timeIn)*giaTienThuong;
    }

};


#endif // MAYTHUONG_H_INCLUDED
