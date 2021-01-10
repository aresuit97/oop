#include "phien.h"

May* Phien::getMay()
{
    return m;
};
void Phien::setMay(May* may)
{
    m=may;
};
long long Phien::getThoiGian()
{
    return thoiGian;
};
void Phien::setThoiGian(long long tg )
{
    thoiGian=tg;
};
long long Phien::getTienChoi()
{
    return tienChoi;
};
void Phien::setTienChoi(long long tien)
{
    tienChoi=tien;
};
bool Phien::getTrangThai()
{
    return trangThaiPhien;
};
