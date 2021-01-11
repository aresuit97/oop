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
    int thoiGian,tienChoi;
    May* m;
    bool trangThaiPhien;
    ThanhVien* tv;
    string tenTV;
public:
    virtual int type ()=0;
    virtual void doiTrangThai()=0;
    time_t getTime(){return timeTemp;};
    virtual void tatMay();
    May* getMay();
    void setMay(May* m);
    int  getThoiGian();
    void setThoiGian(int tg);
    int getTienChoi();
    void setTienChoi(int tien);
    bool getTrangThai();
    int getId();
    ThanhVien* getTV(){return tv;};
    void setTV(ThanhVien* tvien){tv=tvien;}
    virtual void tinhTien();
    void setTime(time_t time);
    void  setID(int id){mayID=id;}
    void setUsername(string tenTV){tenTV=tenTV;};
    void setTrangThai(bool b){trangThaiPhien=b;};
    virtual ~Phien(){};
};


#endif // PHIEN_H_INCLUDED
