#include "qlPhien.h"


qlPhien::qlPhien()
{
    if(qP!=NULL)delete[] qP;
    qP=nullptr;
    soLuong=0;
}

void qlPhien::themPhien(phienTV* p)
{
    if(soLuong==0)
    {
        soLuong=1;
        qP=new Phien*[1];
        qP[0]=p;
    }
    else
    {
        Phien** temp=new Phien*[soLuong+1];
        for (int i=0; i<soLuong; i++)
        {
            temp[i]=qP[i];
        }
        temp[soLuong]=p;
        delete[] qP;

        qP=temp;
        soLuong++;
    }
}

void qlPhien::themPhien(phienNonTV* p)
{
    if(soLuong==0)
    {
        soLuong=1;
        qP=new Phien*[1];
        qP[0]=p;
    }
    else
    {
        Phien** temp=new Phien*[soLuong+1];
        for (int i=0; i<soLuong; i++)
        {
            temp[i]=qP[i];
        }
        temp[soLuong]=p;
        delete[] qP;

        qP=temp;
        soLuong++;
    }
}

void qlPhien::update()
{
    for (int i=0; i<soLuong; i++)
    {
        if(!qP[i]->getTrangThai())continue;
        if(qP[i]->getMay()==nullptr)
        {
            qP[i]->setMay(qM.getDsMay()[qP[i]->getId()]);
            if(qP[i]->type()==1)
            {
                ThanhVien** tempDS= qTV.getds();
                for (int j=0; j<qTV.getSL(); j++)
                {
                    if(qP[i]->getTV()->getUsername()==tempDS[i]->getUsername())
                    {
                        qP[i]->setTV(tempDS[i]);
                    }
                }
            }

        }
        long long tempSec=difftime(qP[i]->getTime(),time(0));
        time_t temp= time(0);
        if(qP[i]->type()==0)
        {
            qP[i]->tinhTien();
            qP[i]->setTime(temp);
        }

    }

}

long long qlPhien::tongDoanhthu(){
    long long sum =0;
    for (int i=0;i<soLuong;i++){
        sum+=qP[i]->getTienChoi();
    }
    return sum;
};

void qlPhien::xuatDSMay()
{
    ofstream fo("DSMay.txt",ios::binary|ios::out);
    May** temp= qM.getDsMay();
    for (int i=0;qM.getSL();i++){
        fo<<temp[i]->info()<<endl;
        fo<<temp[i]->getID()<<endl;
    }
    fo.close();
}

void qlPhien::nhapDSMay(){
    ifstream fi("DSMay.txt",ios::binary|ios::in);
    qlMay tempDSMay;
    while (!fi.eof()){
        string x;
        fi>>x;
        if(x=="NOR"){
            int tID;
            fi>>tID;
            mayThuong* tempM;
            tempM->setID(tID);
            tempDSMay.them(tempM);
        }
        if(x=="VIP"){
            int tID;
            fi>>tID;
            mayVip* tempMV;
            tempMV->setID(tID);
            tempDSMay.them(tempMV);
        }
    }
    fi.close();
    qM=tempDSMay;
}

void qlPhien::xuatDSTV(){
    ofstream fo("DSTV.txt",ios::binary|ios::out);
    ThanhVien** temp= qTV.getds();
    for (int i=0;qTV.getSL();i++){
        fo<<temp[i]->getUsername()<<endl;
        fo<<temp[i]->getPW()<<endl;
        fo<<temp[i]->getTen()<<endl;
        fo<<temp[i]->getSDT()<<endl;
        fo<<temp[i]->getTien()<<endl;
        fo<<temp[i]->getThoiGianChoi()<<endl;
        fo<<setprecision(2)<<temp[i]->getUudai()<<endl;
    }
    fo.close();
}
void qlPhien::nhapDSTV(){
    ifstream fi("DSTV.txt",ios::binary|ios::out);
    qlThanhVien tempQLTV;
    while(!fi.eof()){
        ThanhVien* tempTV;
        string temp;
        fi>>temp;
        tempTV->setUsername(temp);
        fi>>temp;
        tempTV->setPW(temp);
        getline(fi,temp);
        tempTV->setTen(temp);
        fi>>temp;
        tempTV->setSDT(temp);
        int tien;
        fi>>tien;
        tempTV->setTien(tien);
        int thoiGian;
        fi>>thoiGian;
        tempTV->setThoiGianChoi(thoiGian);
        float uuDai;
        fi>>uuDai;
        tempTV->setUuDai(uuDai);
        tempQLTV.themTV(tempTV);
    }
    qTV=tempQLTV;
    fi.close();
}

void qlPhien::xuatDSPhien(){
        ofstream  fo("DSPhien.txt",ios::binary|ios::out);
        for (int i=0;i<soLuong;i++){
            fo<<qP[i]->type()<<endl;
            fo<<qP[i]->getMay()->getID()<<endl;
            if(qP[i]->type()==1)fo<<qP[i]->getTV()->getUsername()<<endl;
            fo<<qP[i]->getThoiGian()<<endl;
            fo<<qP[i]->getTienChoi()<<endl;
            fo<<qP[i]->getTrangThai()<<endl;
        }
        fo.close();
    }

void qlPhien::nhapDSPhien()
{
    ifstream fi("DSPhien.txt",ios::binary|ios::in);
    soLuong=0;
    if(qP!=nullptr)delete[] qP;
    while (!fi.eof())
    {
        int i;
        fi>>i;
        phienTV* tempP;
        if(i==0){
            delete tempP;
            phienNonTV* tempP;
            }
        fi>>i;
        tempP->setID(i);
        if(tempP->type()==1)
        {
            string tempS;
            fi>>tempS;
            tempP->setUsername(tempS);
        }
        int temp;
        fi>>temp;
        tempP->setThoiGian(temp);
        fi>>temp;
        tempP->setTienChoi(temp);
        bool b;
        fi>>b;
        tempP->setTrangThai(b);
        if(soLuong==0)
        {
            soLuong=1;
            qP=new Phien*[1];
            qP[0]=tempP;
        }
        else
        {
            Phien** temp=new Phien*[soLuong+1];
            for (int i=0; i<soLuong; i++)
            {
                temp[i]=qP[i];
            }
            temp[soLuong]=tempP;
            delete[] qP;

            qP=temp;
            soLuong++;
        }
    }
}

