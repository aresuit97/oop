#include "qlMay.h"

void qlMay::them(mayThuong* m)
{
    if(soLuong==0)
    {
        soLuong=1;
        if(qMay!=nullptr)delete[] qMay;
        qMay= new May*[1];
        qMay[0]=m;
    }
    else
    {
        May** temp=new May*[soLuong+1];
        for (int i=0;i<soLuong;i++){
            temp[i]=qMay[i];
        }
        temp[soLuong]=m;
        delete[] qMay;
        qMay=temp;
        soLuong++;
    }
}

void qlMay::them(mayVip* m)
{
    if(soLuong==0)
    {
        soLuong=1;
        if(qMay!=nullptr)delete[] qMay;
        qMay= new May*[1];
        qMay[0]=m;
    }
    else
    {
        May** temp=new May*[soLuong+1];
        for (int i=0;i<soLuong;i++){
            temp[i]=qMay[i];
        }
        temp[soLuong]=m;
        delete[] qMay;
        qMay=temp;
        soLuong++;
    }
}

May** qlMay::getDsMay()
{
    return qMay;
}


qlMay::qlMay(){
     soLuong=0;
     qMay=nullptr;
    }


