#include "mayThuong.h"

int mayThuong::thanhtien()
{
    return giaTienMayThuong;
}

string mayThuong::info()
{
    return "NOR";
}
void mayThuong::doiTrangThai()
{
    trangThai=(trangThai)?false:true;
}
void mayThuong::setID(int id)
{
    ID=id;
}
