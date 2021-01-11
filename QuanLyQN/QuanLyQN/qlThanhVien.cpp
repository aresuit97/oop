#include "qlThanhVien.h"

qlThanhVien::qlThanhVien()
{
    soLuong=0;
    tv=nullptr;
}

void qlThanhVien:: display()
{
    for(int i=0; i<soLuong; i++)
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
    if(soLuong==0)
    {
        soLuong=1;
        tv=new ThanhVien*[1];
        tv[0]=tvien;
    }
    else
    {
        ThanhVien** temp=new ThanhVien*[soLuong+1];
        for (int i=0; i<soLuong; i++)
        {
            temp[i]=tv[i];
        }
        temp[soLuong]=tvien;
        delete[] tv;
        tv=temp;
        soLuong++;
    }
}

void qlThanhVien::reset(){
    soLuong=0;
    if(tv!=nullptr)delete[] tv;
    tv=nullptr;
}

void qlThanhVien::setDSTV(ThanhVien** tvi){
    tv=tvi;
};
