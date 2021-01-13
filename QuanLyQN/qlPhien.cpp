#include "qlPhien.h"
#include <ctime>
qlPhien::qlPhien()
{
    qP=nullptr;
    soLuong=0;
    qM.reset();
    qTV.reset();
}

void qlPhien::themPhien(Phien* p)
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

void  qlPhien::searchTvMay(int mayID)
{
    for (int i=0; i<soLuong; i++)
    {
        if(qP[i]->getId()==mayID&&qP[i]->getTrangThai()&&qP[i]->type()==1)
        {
            cout<<setw(28)<<right<<qP[i]->gettenTV();
        }
    }

}
void qlPhien::displayDSMay()
{
    qlMay ql=this->getDSMay();
    for (int i=0; i<ql.getSL(); i++)
    {
        ql.getDsMay()[i]->display();
        this->searchTvMay(ql.getDsMay()[i]->getID());
        cout<<endl;
    }
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
            May** tempMay=qM.getDsMay();
            if(!qM.check(qP[i]->getId()))
            {
                qP[i]->doiTrangThai();
                qP[i]->setID(0);
                continue;
            }
            for(int j=0; j<qM.getSL(); j++)
            {
                if(qP[i]->getId()==tempMay[j]->getID())
                {
                    qP[i]->setMay(tempMay[j]);
                    tempMay[j]->doiTrangThai();
                    break;
                }
            }
            if(qP[i]->type()==1)
            {
                string t=qP[i]->gettenTV();
                qP[i]->setTV(this->getDS().searcH(t));
                if(qP[i]->getTV()==nullptr)
                {
                    qP[i]->doiTrangThai();
                }
            }

        }
        int tempSec=difftime(time(0),qP[i]->getTime());
        time_t temp= time(0);
        qP[i]->tinhTien();
        qP[i]->setTime(temp);
    }
}
void qlPhien::hienPhienOnl()
{
    cout<<"Cac phien dang hoat dong: "<<endl;
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"| May    | So tien       | Thoi gian         |        Trang thai|             Thanh vien|"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    for (int i=0; i<soLuong; i++)
    {
        if(this->getDSPhien()[i]->getTrangThai())
        {
            this->getDSPhien()[i]->display();
            cout<<endl;
        }
    }
};
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
        qTV.themTV(tempTV);
        tempTV=nullptr;
    }
    qTV.capNhatVip();
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
        tempP->setTime(time(0));
        if(soLuong==0)
        {
            soLuong=1;
            qP=new Phien*[1];
            qP[0]=tempP;
            if(qP[0]->type()==1)
            {
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
            if(temp[soLuong]->type()==1)
            {
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
    Tool t;
    cout<<"Nhap username: ";
    string username;
    getline(cin,username);
    while(this->getDS().check(username)||!t.checkKhoangTrang(username))
    {
        cout<<"Username khong hop le. Vui long nhap lai:";
        getline(cin,username);
    }
    cout<<"Nhap ten: ";
    string ten;
    getline(cin,ten);
    ten=t.chuanHoa(ten);
    cout<<"Nhap mat khau: " ;
    string newPW;
    getline(cin,newPW);
    while(!t.matkhau(newPW))
    {
        cout<<"Nhap lai mat khau  (Mat khau gom it nhat 4 ki tu va la chuoi lien ke): ";
        getline(cin,newPW);
    }
    cout<<"Xac nhan mat khau: ";
    string tempPW;
    getline(cin,tempPW);
    while (newPW!=tempPW)
    {
        cout<<"Mat khau khong khop! Nhap lai mat khau moi(Mat khau gom it nhat 4 ki tu va la chuoi lien ke): ";
        getline(cin,newPW);
        while(!t.matkhau(newPW))
        {
            cout<<"Nhap lai mat khau moi(Mat khau gom it nhat 4 ki tu va la chuoi lien ke): ";
            getline(cin,newPW);
        }
        cout<<"Xac nhan mat khau: ";
        getline(cin,tempPW);
    }
    string SDT;
    cout<<"Nhap sdt: ";
    cin>>SDT;
    while(t.isSDT(SDT)==false)
    {
        cout<<"So dien thoai chi bao gom co 10 chu so. Hay nhap lai: ";
        cin>>SDT;
    }

    int soTien;
    cout<<"Nhap so tien nap lan dau: ";
    cin>>soTien;
    ThanhVien* temp= new ThanhVien(username,newPW,ten,SDT,soTien,0,1);
    qlThanhVien tv=this->getDS();
    tv.themTV(temp);
    this->setDSTV(tv);

}

void qlPhien::taoMay()
{
    Tool t;
    cout<<"Ban muon tao them loai may: "<<endl;
    cout<<"1. May thuong."<<endl;
    cout<<"2. May vip."<<endl;
    string in;
    getline(cin,in);
    while(in!="1"&&in!="2"&&in!="0")
    {
        cout<<"In khong hop le. Vui long nhap lai:";
        getline(cin,in);
    }
    if(in=="0")return;
    if(in=="1")
    {
        string idM;
        cout<<"Nhap id may(ID phai <100):";

        int flag=0,n;
        while(!flag)
        {
            getline(cin,idM);
            while(!(t.laSo(idM)&&idM.length()<=2))
            {
                cout<<"Vui long nhap lai( ID phai la so va < be hon 100 hoac ID khong hop le):";
                getline(cin,idM);
            }
            n=stoi(idM);
            if(this->getDSMay().check(n))
            {
                cout<<"Trung ID! Vui long nhap lai";
                continue;
            }
            flag=1;
        }
        qlMay ql=this->getDSMay();
        May* tempMay;
        tempMay=nullptr;
        delete tempMay;
        tempMay=new May(n);
        ql.them(tempMay);
        this->setDSMay(ql);
        cout<<"Da them may thanh cong."<<endl;
        cin.get();
        return;
    }
    if(in=="2")
    {
        string idM;
        cout<<"Nhap id may(ID phai <100):";
        cin>>idM;
        int flag=0,n;
        while(!flag)
        {
            while(!(t.laSo(idM)&&idM.length()<=2))
            {
                cout<<"Vui long nhap lai( ID phai la so va < be hon 100 hoac ID khong hop le):";
                cin>>idM;
            }
            n=stoi(idM);
            if(this->getDSMay().check(n))continue;
            flag=1;
        }
        qlMay ql=this->getDSMay();
        May* tempMay;
        tempMay=new mayVip(n);
        ql.them(tempMay);
        this->setDSMay(ql);
        cout<<"Da them may thanh cong."<<endl;
        cin.get();
        return;
    }
}
;
void qlPhien::timThanhVien()
{
    Tool z;
    string t;
    cout<<"Tim kiem theo username: ";
    getline(cin,t);
    int ans[100];
    int cnt=0;
    t=z.nomalize(t);
    qlThanhVien a=this->getDS();
    for (int i=0; i<a.getSL(); i++)
    {
        string userTemp=a.getds()[i]->getUsername();
        userTemp=z.nomalize(userTemp);
        if(z.subString(userTemp,t))
        {
            ans[cnt]=i;
            cnt++;
            cout<<cnt<<".";
            a.getds()[i]->thongTinTaiKhoan();
        }
    };
    if(cnt==0)
    {
        cout<<"Khong tim thay thanh vien nao.";
        cin.get();
        return;
    }
    else
    {
        cout<<"Chon thanh vien ban muon xu ly: ";
        int n;
        cin>>n;
        while(n<1||n>cnt)
        {
            cout<<"Vui long nhap dung lua chon! Lua chon cua ban:";
            cin>>n;
        }
        int pos=ans[n-1];
        cout<<"Thanh vien ban chon: ";
        cout<<a.getds()[pos]->getUsername()<<endl;
        cout<<"Chon thao tac ban muon xu ly voi thanh vien nay: "<<endl;
        cout<<"1. Xoa thanh vien."<<endl;
        cout<<"2. Sua thanh vien."<<endl;
        cout<<"Lua chon cua ban: ";
        cin>>n;
        while (n!=1&&n!=2)
        {
            cout<<"Vui long nhap lai thong tin chinh xac! Lua chon cua ban: ";
            cin>>n;
        }
        if(n==1)
        {
            string temp=a.getds()[pos]->getUsername();
            a.xoaThanhVien(pos);
            this->setDSTV(a);
        }
        if(n==2)
        {
            a.getds()[pos]->suaThongTin();
        }
    }
}

void qlPhien::timMay()
{
    Tool t;
    cout<<"Tim may theo ID: ";
    string id;
    getline(cin,id);
    int ans[100];
    while (!t.laSo(id)||id.length()>2)
    {
        cout<<"Hay nhap lai ID( la so va khong qua 100):";
        getline(cin,id);
    }
    int n=stoi(id);
    int cnt=0;
    qlMay s= this->getDSMay();
    for (int i=0; i<s.getSL(); i++)
    {
        int h=s.getDsMay()[i]->getID();
        if(h==n||(h/10)==n||(h%10)==n)
        {
            ans[cnt]=i;
            cnt++;
            cout<<cnt<<".";
            s.getDsMay()[i]->display();
            cout<<endl;
        }
    };
    if(cnt==0)
    {
        cout<<"Khong tim duoc may nao";
        return;
    }
    cout<<"Chon may ban muon xu ly: ";
    cin>>n;
    while(n<0||n>cnt)
    {
        if(n==0)return;
        cout<<"Vui long nhap dung lua chon! Lua chon cua ban: ";
        cin>>n;
    }
    int pos=ans[n-1];
    cout<<"May ban chon la "<< s.getDsMay()[pos]->info()<<s.getDsMay()[pos]->getID()<<endl;
    cout<<"Chon thao tac ban muon xu ly voi may nay: "<<endl;
    cout<<"1. Xoa may."<<endl;
    cout<<"2. Sua may."<<endl;
    cout<<"Lua chon cua ban: ";
    cin>>n;
    while (n!=1&&n!=2)
    {
        cout<<"Vui long nhap lai thong tin chinh xac! Lua chon cua ban: ";
        cin>>n;
    }
    if(n==1)
    {
        s.xoaMay(pos);
        this->setDSMay(s);
    }
    if(n==2)
    {
        string ti;
        int tis;
        cout<<"Nhap ID may ban muon thay doi cho may (Nhap ID cu de giu nguyen): ";
        int flag=0;
        while(!flag)
        {
            getline(cin,ti);
            while(!(t.laSo(ti)&&ti.length()<=2))
            {
                cout<<"Vui long nhap lai( ID phai la so va < be hon 100 hoac ID khong hop le): ";
                getline(cin,ti);
            }
            tis=stoi(ti);
            if(this->getDSMay().check(n)||s.getDsMay()[pos]->getID()==n)
            {
                flag=1;
                break;
            }
            cout<<"Trung ID. Vui long nhap lai: ";
        }
        s.getDsMay()[pos]->setID(tis);
        cout<<"Da cap nhat may.";
        cin.get();
    }
}
void qlPhien::setDSMay(qlMay m)
{
    qM=m;
};

void qlPhien::display()
{
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"| May    | So tien       | Thoi gian         |        Trang thai|             Thanh vien|"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    for (int i=0; i<soLuong; i++)
    {
        qP[i]->display();
        cout<<endl;
    }
}

int qlPhien::getSL()
{
    return soLuong;
}
void qlPhien::setSL(int sl)
{
    soLuong=sl;
}
qlMay qlPhien::getDSMay()
{
    return qM;
};

Phien** qlPhien::getDSPhien()
{
    return qP;
}
void qlPhien::setDSPhien(Phien** qt)
{
    qP=qt;
}

