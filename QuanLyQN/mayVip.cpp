#include "mayVip.h"
#include <iomanip>
float mayVip::thanhtien()
{
    float giaTienMayVip;
};
string mayVip::info()
{
    return "VIP";
}

mayVip::mayVip(int n)
{
    trangThai=false;
    ID=n;
}
void mayVip::display()
{
    cout<<" VIP"<<ID<<"  ";
    if(ID<10)cout<<" ";
    if(trangThai)cout<<setw(30)<<right<<"Dang dung";
    else cout<<setw(30)<<right<<"Dang tat";
}
