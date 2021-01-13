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
phienNonTV::phienNonTV(May* may){
    timeTemp=time(0);
    mayID=may->getID();
    m=may;
    thoiGian=0;
    tienChoi=0;
    trangThaiPhien=true;
    if(!m->getTrangThai())
        m->doiTrangThai();
}

phienNonTV::phienNonTV(int mayid,int thoigian,int tienchoi,bool trangthai){
    mayID=mayid;
    thoiGian=thoigian;
    tienChoi=tienchoi;
    trangThaiPhien=trangthai;
    m=nullptr;
}
int phienNonTV::type()
{
    return 0;
};

void phienNonTV::tinhTien(){
        int tempSec= difftime(time(0),timeTemp);
        timeTemp=time(0);
        thoiGian+=tempSec;
        float tempF=(float)tienChoi*m->thanhtien()*tempSec;
        tienChoi=(int)tempF;
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

void phienNonTV::display(){
    cout<<"Mayid:"<<mayID<<"   So tien:"<<tienChoi<<"       Thoi gian:"<<thoiGian<<"        Trang thai:"<<trangThaiPhien<<endl;
}

void phienNonTV::update(){

}
phienNonTV::~phienNonTV(){};
