#ifndef PHIENTV_H_INCLUDED
#define PHIENTV_H_INCLUDED

#include "phien.h"

class phienTV:public Phien{
    ThanhVien* tv;
    string tenTV;
public:
    int type();
    PhienTV();
    void moMay();
    void tatMay();


};

#endif // PHIENTV_H_INCLUDED
