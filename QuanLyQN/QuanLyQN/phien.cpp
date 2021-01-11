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

bool Phien::getTrangThai()
{
    return trangThaiPhien;
};

int Phien::getId()
{
    return mayID;
};

void Phien::setTime(time_t time)
{
    timeTemp=time;
}

void  Phien::setID(int id)
{
    mayID=id;
}
void Phien::setUsername(string tentv)
{
    tenTV=tentv;
};
void Phien::setTrangThai(bool b)
{
    trangThaiPhien=b;
};
string Phien::gettenTV()
{
    return tenTV;
}

ThanhVien* Phien::getTV()
{
    return tv;
};
void Phien::setTV(ThanhVien* tvien)
{
    tv=tvien;
};
