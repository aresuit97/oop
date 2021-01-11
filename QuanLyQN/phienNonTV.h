#ifndef PHIENNONTV_H_INCLUDED
#define PHIENNONTV_H_INCLUDED
#include "phien.h"

class phienNonTV:public Phien
{


public:
    int type();
    PhienNonTV();
    void tatMay();
    void update();
    void tinhTien();

};

#endif // PHIENNONTV_H_INCLUDED
