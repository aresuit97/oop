#include "phien.h"

May* Phien::getMay()
{
    return m;
};
void Phien::setMay(May* may)
{
    m=may;
};
int Phien::getThoiGian()
{
    return thoiGian;
};
void Phien::setThoiGian(int tg )
{
    thoiGian=tg;
};
int Phien::getTienChoi()
{
    return tienChoi;
};
void Phien::setTienChoi(int tien)
{
    tienChoi=tien;
};
bool Phien::getTrangThai()
{
    return trangThaiPhien;
};

int Phien::getId()
    {
        return mayID;
    };

void Phien::setTime(time_t time){
        timeTemp=time;
    }
