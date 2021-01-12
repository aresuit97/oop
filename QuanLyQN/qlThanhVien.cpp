#include "qlThanhVien.h"

qlThanhVien::qlThanhVien()
{
    soLuongTV=0;
    tv=nullptr;
}

void qlThanhVien:: display()
{
    for(int i=0; i<soLuongTV; i++)
    {
        tv[i]->thongTinTaiKhoan();cout<<endl;
    }

    cout << endl;
}

ThanhVien** qlThanhVien::getds(){
        return tv;
    }

void qlThanhVien::themTV(ThanhVien* tvien )
{
    if(soLuongTV==0)
    {
        soLuongTV=1;
        tv=new ThanhVien*[1];
        tv[0]=tvien;
    }
    else
    {
        ThanhVien** temp=new ThanhVien*[soLuongTV+1];
        for (int i=0; i<soLuongTV; i++)
        {
            temp[i]=tv[i];
        }
        temp[soLuongTV]=tvien;
        delete[] tv;
        tv=temp;
        soLuongTV++;
    }
}

void qlThanhVien::reset(){
    soLuongTV=0;
    if(tv!=nullptr)delete[] tv;
    tv=nullptr;
}

void qlThanhVien::setDSTV(ThanhVien** tvi){
    tv=tvi;
};

bool qlThanhVien::check(string user){
    for (int i=0;i<soLuongTV;i++){
        if(user==tv[i]->getUsername())return true;
    }
    return false;
}

void qlThanhVien::xoaThanhVien(int pos){

    ThanhVien** temp= new ThanhVien*[soLuongTV-1];
    for (int i=0;i<pos;i++){
        temp[i]=tv[i];
    }
    for (int i=pos;i<soLuongTV-1;i++){
        temp[i]=tv[i+1];
    }
    delete[] tv;
    tv=temp;
    soLuongTV--;
    cout<<soLuongTV;
}
