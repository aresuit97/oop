#include "qlPhien.h"


qlPhien::qlPhien()
{
    if(qP!=NULL)delete[] qP;
    qP=nullptr;
    soLuong=0;
}

void qlPhien::themPhien(phienTV p)
{
    if(soLuong==0)
    {
        soLuong=1;
        qP=new Phien*[1];
        qP[0]=&p;
    }
    else
    {
        Phien** temp=new Phien*[soLuong+1];
        for (int i=0; i<soLuong; i++)
        {
            *(temp[i])=*(qP[i]);
        }
        temp[soLuong]=&p;
        delete[] qP;

        qP=temp;
        soLuong++;
    }
}

void qlPhien::themPhien(phienNonTV p)
{
    if(soLuong==0)
    {
        soLuong=1;
        qP=new Phien*[1];
        qP[0]=&p;
    }
    else
    {
        Phien** temp=new Phien*[soLuong+1];
        for (int i=0; i<soLuong; i++)
        {
            *(temp[i])=*(qP[i]);
        }
        temp[soLuong]=&p;
        delete[] qP;

        qP=temp;
        soLuong++;
    }
}

//void qlPhien::update()
//{
//    for (int i=0; i<soLuong; i++)
//    {
//        if(qP[i]->trangThaiPhien())
//        {
//            long long temp=difftime(qP[i]->getTime(),time(0));
//
//        }
//    }
//
//}

