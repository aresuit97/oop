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

void qlPhien::update()
{
    for (int i=0; i<soLuong; i++)
    {
        if(qP[i]->getMay()==nullptr)
        {
            qP[i]->setMay(qM.getDsMay()[qP[i]->getId()]);
            qP[i]->getMay()->doiTrangThai();
            if(qP[i]->type()==1)
            {
                for (int j=0; j<qTV.getSL(); j++)
                {
                    if(qP[i]->tenTV==qTV.tv[i]->getUsername()))
                    {
                            qP[i]->tv=qTV.tv[i];
                    }
                }
            }

        }
        if(qP[i]->trangThaiPhien())
        {
            long long tempSec=difftime(qP[i]->getTime(),time(0));
            time_t temp= time(0);
            if(qP->type()==0)
            {
                qP[i]->tienChoi=tempSec*qP[i]->m->thanhtien();
                qP[i]->timeTemp=temp;
            }
                else {
                        qP[i]->tienChoi+=tempSec*qP[i]->getMay()->thanhtien()*qP[i]->tv->uuDai;
                        qP[i]->timeTemp=temp;
                }

        }
    }

}

