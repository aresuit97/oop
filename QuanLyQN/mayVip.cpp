#include "mayVip.h"

int mayVip::thanhtien()
{
    return giaTienMayVip;
};
string mayVip::info()
{
    return "VIP";
}
void mayVip::doiTrangThai()
{
    trangThai=(trangThai)?false:true;
}
void mayVip::setID(int id)
{
    ID=id;
}
