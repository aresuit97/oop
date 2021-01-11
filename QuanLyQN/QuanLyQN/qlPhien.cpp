#include "qlPhien.h"

qlPhien::qlPhien()
{
    qP=nullptr;
    soLuong=0;
    qM.reset();
    qTV.reset();
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
                    if(qP[i]->gettenTV()==tempDS[i]->getUsername())
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

long long qlPhien::tongDoanhthu()
{
    long long sum =0;
    for (int i=0; i<soLuong; i++)
    {
        sum+=qP[i]->getTienChoi();
    }
    return sum;
};

void qlPhien::xuatDSMay()
{
    ofstream fo("DSMay.txt",ios::binary|ios::out);
    May** temp= qM.getDsMay();
    for (int i=0; qM.getSL(); i++)
    {
        fo<<temp[i]->info()<<endl;
        fo<<temp[i]->getID()<<endl;
    }
    fo.close();
}

void qlPhien::nhapDSMay()
{
    ifstream fi("DSMay.txt",ios::binary|ios::in);
    qM.reset();
    while (!fi.eof())
    {
        string x;
        fi>>x;
        if(x=="NOR")
        {
            int tID;
            fi>>tID;
            May* tempM=new May(tID);
            qM.them(tempM);
        }
        if(x=="VIP")
        {
            int tID;
            fi>>tID;
            May*tempMV=new mayVip(tID);
            qM.them(tempMV);
        }
    }
    fi.close();

}

void qlPhien::xuatDSTV()
{
    ofstream fo("DSTV.txt",ios::binary|ios::out);
    ThanhVien** temp= qTV.getds();
    for (int i=0; i<qTV.getSL(); i++)
    {
        fo<<temp[i]->getUsername()<<endl;
        fo<<temp[i]->getPW()<<endl;
        fo<<temp[i]->getTen()<<endl;
        fo<<temp[i]->getSDT()<<endl;
        fo<<temp[i]->getTien()<<endl;
        fo<<setprecision(2)<<temp[i]->getUudai()<<endl;
        if(i==qTV.getSL()-1)fo<<temp[i]->getThoiGianChoi();
        else fo<<temp[i]->getThoiGianChoi()<<endl;
    }
    fo.close();
}
void qlPhien::nhapDSTV()
{
    ifstream fi("DSTV.txt",ios::in);
    qTV.reset();
    while(!fi.eof())
    {
        if(fi.good())
        {
            string temp;
            ThanhVien* tempTV=new ThanhVien();
            fi>>temp;
            fi.ignore();
            tempTV->setUsername(temp);
            fi>>temp;
            fi.ignore();
            tempTV->setPW(temp);
            getline(fi,temp);
            tempTV->setTen(temp);
            fi>>temp;
            fi.ignore();
            tempTV->setSDT(temp);
            int tempI;
            fi>>tempI;
            fi.ignore();
            tempTV->setTien(tempI);
            float uuDai;
            fi>>uuDai;
            fi.ignore();
            tempTV->setUuDai(uuDai);
            fi>>tempI;
            tempTV->setThoiGianChoi(tempI);;
            cout<<endl;
            qTV.themTV(tempTV);
            tempTV=nullptr;
        }
    }
    fi.close();
}

void qlPhien::xuatDSPhien()
{
    ofstream  fo("DSPhien.txt",ios::binary|ios::out);
    for (int i=0; i<soLuong; i++)
    {
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
    delete[] qP;
    while (!fi.eof())
    {
        int i;
        fi>>i;
        Phien* tempP;
        if(i==1)
        {
            tempP=new phienTV();
        }
        else tempP=new phienNonTV();
        fi>>i;
        tempP->setID(i);
        string tempS;
        if(tempP->type()==1)
        {
            fi>>tempS;
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
             if(qP[0]->type()==1){
            qP[0]->setUsername(tempS);
            }
        }
        else
        {
            Phien** temp=new Phien*[soLuong+1];
            for (int i=0; i<soLuong; i++)
            {
                temp[i]=qP[i];
            }
            temp[soLuong]=tempP;
            if(temp[soLuong]->type()==1){
            temp[soLuong]->setUsername(tempS);
            }
            qP=nullptr;
            delete[] qP;
            qP=temp;
            soLuong++;
        }
        tempP=nullptr;
        delete tempP;
    }
}

void qlPhien::setDSTV(qlThanhVien qt)
{
    qTV=qt;
}

qlThanhVien qlPhien::getDS()
{
    return qTV;
}

void qlPhien::themThanhVien()
{
    int n;
    cout<<"Nhap so thanh vien ban muon them vao: ";
    cin>>n;
    qlThanhVien tempDS=qTV;
    for (int i=0; i<2; i++)
    {
        cout<<"Nhap thanh vien thu "<<i+1<<": "<<endl;
        ThanhVien* temp =new ThanhVien();
        cout<<"Nhap username:";
        string tbd;
        cin>>tbd;
        temp->setUsername(tbd);
        cin.ignore();
        cout<<"Nhap pw:";
        cin>>tbd;
        temp->setPW(tbd);
        cin.ignore();
        cout<<"Nhap ten:";
        getline(cin,tbd);
        temp->setTen(tbd);
        cout<<"Nhap sdt:";
        cin>>tbd;
        temp->setSDT(tbd);
        cin.ignore();
        cout<<"Nhap so tien:";
        int tien;
        cin>>tien;
        temp->setTien(tien);
        cin.ignore();
        cout<<"Nhap thoi gian choi:";
        cin>>tien;
        temp->setThoiGianChoi(tien);
        tempDS.themTV(temp);
    }
    qTV=tempDS;
}

void qlPhien::xoaMay(){
    for (int i=0;i<)
}

void qlPhien::display()
{
    for (int i=0; i<soLuong; i++)
    {
        qP[i]->display();
        cout<<endl;
    }
}

