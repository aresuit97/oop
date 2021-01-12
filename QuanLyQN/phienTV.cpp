#include "phienTV.h"
int phienTV::type()
{
    return 1;
}
phienTV::PhienTV()
{
    mayID=-1;
    m=nullptr;
    tenTV="";
    tv=nullptr;
    timeTemp=time(0);
    thoiGian=0;
    trangThaiPhien=false;
}
phienTV::PhienTV(int mayid,string tentv,int thoiGian,int soTien,bool trangthai){
    mayID=mayid;
    m=nullptr;
    tenTV=tentv;
    thoiGian=0;
    tienChoi=soTien;
    trangThaiPhien=trangthai;
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
    int tempSec= difftime(timeTemp,time(0));
    timeTemp=time(0);
    thoiGian+=tempSec;
    tienChoi+=m->thanhtien()*tempSec*tv->getUudai();
    tv->setTien(tv->getTien()-m->thanhtien()*tempSec*tv->getUudai());
    if(tv->getTien()<=0)
    {
        int tam= 0-tv->getTien();
        tv->setTien(0);
        tv->congThoiGian(tam*3600/m->thanhtien()/tv->getUudai());
        tatMay();
    }
}

void phienTV::display()
{
    time_t ts=time(0);
    char*t=ctime(&ts);
    cout<<"Mayid:"<<mayID<<"   So tien:"<<tienChoi<<"       Thoi gian:"<<thoiGian<<"        Trang thai:"<<trangThaiPhien<<endl;
    cout<<"Thanh Vien:"<<this->gettenTV()<<"           Thoi gian:"<<t;

}


