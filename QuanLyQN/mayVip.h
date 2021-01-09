#pragma once
#ifndef MAYVIP_H_INCLUDED
#define MAYVIP_H_INCLUDED
#include "may.h"

class mayVip:public may()
{
   public:
        int thanhtien()
    {
            if(tv!=null)
                return difftime(time(0),timeIn)*giaTienVip*tv.uuDai;
            else return difftime(time(0),timeIn)*giaTienVip;
    }
};

#endif // MAYVIP_H_INCLUDED
