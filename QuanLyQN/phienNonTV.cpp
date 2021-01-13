#include "phienNonTV.h"

phienNonTV::phienNonTV()
{

    mayID=-1;
    m=nullptr;
    timeTemp=time(0);
    thoiGian=0;
    tienChoi=0;
    trangThaiPhien=false;
    tenTV="";
    tv=nullptr;
}
phienNonTV::phienNonTV(May* may)
{
    timeTemp=time(0);
    mayID=may->getID();
    m=may;
    thoiGian=0;
    tienChoi=0;
    trangThaiPhien=true;
    if(!m->getTrangThai())
        m->doiTrangThai();
}

phienNonTV::phienNonTV(int mayid,int thoigian,int tienchoi,bool trangthai)
{
    mayID=mayid;
    thoiGian=thoigian;
    tienChoi=tienchoi;
    trangThaiPhien=trangthai;
    m=nullptr;
    timeTemp=time(0);
}
int phienNonTV::type()
{
    return 0;
};

void phienNonTV::tinhTien()
{
    int tempSec= difftime(time(0),timeTemp);
    timeTemp=time(0);
    thoiGian+=tempSec;
    float tempF=(float)tienChoi*m->thanhtien()*tempSec;
    tienChoi+=(int)tempF;
    this->setTime(timeTemp);
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

void phienNonTV::display()
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

}

void phienNonTV::update()
{

}
phienNonTV::~phienNonTV() {};
