#ifndef PHIEN_H_INCLUDED
#define PHIEN_H_INCLUDED
#include "thanhVien.h"
#include "may.h"
#include "qlMay.h"
#include "qlThanhVien.h"


class Phien
{
protected:
    time_t timeTemp;
    int mayID;
    int thoiGian;
    May* m;
    bool trangThaiPhien;
    int tienChoi;
    ThanhVien* tv;
    string tenTV;
public:
    virtual int type ()=0;
    void doiTrangThai();
    virtual void tatMay()=0;
    virtual void tinhTien()=0;
    May* getMay();                          //cac ham setter getter
    void setMay(May* m);
    int  getThoiGian();
    void setThoiGian(int tg);
    int getTienChoi(){
    return tienChoi;};
    void setTienChoi(int tien){tienChoi=tien;};
    bool getTrangThai();
    int getId();

    string gettenTV();
    time_t getTime(){return timeTemp;};
    void setTime(time_t time);
    void  setID(int id);
    void setUsername(string tenTV);
    void setTrangThai(bool b);

    virtual void display()=0;
    ThanhVien* getTV();
    void setTV(ThanhVien* tvien);
};


#endif // PHIEN_H_INCLUDED
