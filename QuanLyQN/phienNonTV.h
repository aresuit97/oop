#ifndef PHIENNONTV_H_INCLUDED
#define PHIENNONTV_H_INCLUDED
#include "phien.h"

class phienNonTV:public Phien
{
public:
    int type();
    phienNonTV();
    void tatMay();
    void update();
    void tinhTien();
    void display();
    phienNonTV(May* may);
    phienNonTV(int id)
    {
        mayID=id;
        trangThaiPhien=1;
    };
    phienNonTV(int mayid,int thoigian,int tienchoi,bool trangthai);
    ~phienNonTV();

};

#endif // PHIENNONTV_H_INCLUDED
