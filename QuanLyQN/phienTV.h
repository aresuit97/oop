#ifndef PHIENTV_H_INCLUDED
#define PHIENTV_H_INCLUDED
#include <string>
#include "phien.h"

class phienTV:public Phien
{

    ThanhVien* tv;
    string tenTV;
public:
    int type();
    PhienTV();
    void tatMay();
    void tinhTien();
    void display();
    PhienTV(int mayid,string tentv,int thoiGian,int soTien,bool trangthai);


};

#endif // PHIENTV_H_INCLUDED
