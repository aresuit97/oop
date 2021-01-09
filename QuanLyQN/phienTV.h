#ifndef PHIENTV_H_INCLUDED
#define PHIENTV_H_INCLUDED

#include "phien.h"

class phienTV:public Phien{
    ThanhVien* tv;
    string tenTV;
public:
    int type(){return 1;}
    PhienTV(){
        timeTemp=time(0);
        cin>>mayID;
        cin>>thoiGian;
        cin>>tienChoi;
        cin>>tenTV;
//        trangThaiPhien=true;
    }

};

#endif // PHIENTV_H_INCLUDED
