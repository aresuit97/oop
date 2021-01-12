#include "mayVip.h"

int mayVip::thanhtien()
{
    return giaTienMayVip;
};
string mayVip::info()
{
    return "VIP";
}

mayVip::mayVip(int n){
    trangThai=false;
    ID=n;
}
