#include "phienTV.h"
int phienTV::type()
{
    return 1;
}
phienTV::PhienTV()
{
    timeTemp=time(0);
    cin>>mayID;
    cin>>thoiGian;
    cin>>tienChoi;
    cin>>tenTV;
    trangThaiPhien=false;
}

void phienTV::tatMay()
{
    if(trangThaiPhien)
    {
        trangThaiPhien=false;
        tinhTien();
        m->doiTrangThai();
        tv->congThoiGian(thoiGian);
        m=nullptr;
        tv=nullptr;
    }
}

void phienTV::tinhTien()
{
    long long tempSec= difftime(timeTemp,time(0));
    timeTemp=time(0);
    thoiGian+=tempSec;
    tienChoi+=m->thanhtien()*tempSec*tv->getUudai();
    tv->setTien(tv->getTien()-m->thanhtien()*tempSec*tv->getUudai());
    if(tv->getTien()<=0){
        int tam= 0-tv->getTien();
        tv->setTien(0);
        tv->congThoiGian(tam*3600/m->thanhtien()/tv->getUudai());
        tatMay();
    }
}


