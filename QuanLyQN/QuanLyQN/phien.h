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
    bool trangThaiPhien;
    ThanhVien* tv;
    string tenTV;
public:
    virtual int type ();

    void doiTrangThai(){
        trangThaiPhien=(trangThaiPhien)?false:true;
    }
    time_t getTime(){return timeTemp;};
    virtual void tatMay();
    virtual void moMay();
    May* getMay();
    void setMay(May* m);
    long long getThoiGian();
    void setThoiGian(long long tg);
    long long getTienChoi();
    void setTienChoi(long long tien);
    bool getTrangThai();
    int getId()
    {
        return mayID;
    };


};


#endif // PHIEN_H_INCLUDED
