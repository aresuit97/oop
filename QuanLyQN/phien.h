#ifndef PHIEN_H_INCLUDED
#define PHIEN_H_INCLUDED
#include "thanhVien.h"
#include "may.h"
#include "qlMay.h"
#include "qlThanhVien.h"


class Phien{
protected:
    time_t timeTemp;
    int mayID;
    long long thoiGian;
    long long tienChoi;
    May* m;
    bool trangThaiPhien();
public:
    virtual int type ();

//    void doiTrangThai(){
//        trangThaiPhien=(trangThaiPhien==true)?false:true;
//    }
    time_t getTime(){return timeTemp;};

};


#endif // PHIEN_H_INCLUDED
