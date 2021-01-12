#include "qlMay.h"

void qlMay::them(May* m)
{
    if(soLuong==0)
    {
        soLuong=1;
        qMay= new May*[1];
        qMay[0]=m;
    }
    else
    {
        May** temp=new May*[soLuong+1];
        for (int i=0; i<soLuong; i++)
        {
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


qlMay::qlMay()
{
    soLuong=0;
    qMay=nullptr;
}

void qlMay::setDsMay(May** pt)
{
    qMay=pt;
}

void qlMay::reset(){
    soLuong=0;
    if(qMay!=nullptr)delete[] qMay;
    }

void qlMay::display(){
    for (int i=0;i<soLuong;i++){
        qMay[i]->display();
    }
}


