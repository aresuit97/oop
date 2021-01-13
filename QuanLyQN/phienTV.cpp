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
phienTV::PhienTV(int mayid,string tentv,int thoiGian,int soTien,bool trangthai)
{

    mayID=mayid;
    m=nullptr;
    tenTV=tentv;
    thoiGian=0;
    tienChoi=soTien;
    trangThaiPhien=trangthai;
    this->timeTemp=time(0);
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
    if(tv!=nullptr)
    {
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
    Tool t;
    cout<<"  ";
    cout<<setw(9)<<left<<mayID<<setw(8)<<t.lamtrontien(tienChoi)<<setw(10)<<right<<thoiGian/3600<<":";
    if(thoiGian%3600/60<10)cout<<"0"<<thoiGian%3600/60;
    else cout<<thoiGian%3600/60;
    if(trangThaiPhien)
    {
        cout<<setw(15)<<right<<"                  Dang hoat dong";
    }
    else cout<<setw(15)<<right<< "                         Da dung";
    cout<<setw(24)<<right<<this->gettenTV();

}


