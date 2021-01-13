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
    int tempSec= difftime(time(0),timeTemp);
    timeTemp=time(0);
    this->thoiGian=thoiGian+tempSec;
    if(tv!=nullptr){
    float tempTien= (float)tienChoi+(float)tienChoi+m->thanhtien()*(float)tempSec*tv->getUudai();
    tienChoi=(int)tempTien;
    tv->setTien(tv->getTien()-(tienChoi-(int)tempTien));
        if(tv->getTien()<=0)
        {
            tatMay();
        }
    }
}

void phienTV::display()
{
    cout<<"Mayid:"<<mayID<<"   So tien:"<<tienChoi<<"       Thoi gian:"<<thoiGian<<"        Trang thai:"<<trangThaiPhien;
    cout<<"Thanh Vien:"<<this->gettenTV()<<endl;

}


