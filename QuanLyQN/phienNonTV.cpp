#include "phienNonTV.h"

phienNonTV::PhienNonTV()
{
    timeTemp=time(0);
    cin>>mayID;
    cin>>thoiGian;
    cin>>tienChoi;
}
int phienNonTV::type()
{
    return 0;
};

void phienNonTV::tinhTien(){
        long long tempSec= difftime(timeTemp,time(0));
        timeTemp=time(0);
        thoiGian+=tempSec;
        tienChoi+=m->thanhtien()*tempSec;

}
void phienNonTV::tatMay()
{
    if(trangThaiPhien)
    {
        trangThaiPhien=false;
        tinhTien();
        m->doiTrangThai();
        m=nullptr;
    }
}


