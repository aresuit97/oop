#include "thanhVien.h"

ThanhVien::ThanhVien()
{
    thoiGianChoi=0;
    soTien=0;
    username=pw=ten=sdt="";
    uuDai=1;
}
ThanhVien::ThanhVien(string username,string pw,string ten,string sdt,int soTien,int thoiGianChoi,float uuDai){
    username=username;
    pw=pw;
    ten=ten;
    sdt=sdt;
    soTien=soTien;
    thoiGianChoi=thoiGianChoi;
    uuDai=uuDai;
}

string ThanhVien::getUsername()
{
    return username;
}

void ThanhVien::taoTV()
{

    cout<<"Nhap ten moi: ";
    getline(cin,this->ten);
    cout<<"Nhap sdt moi: ";
    cin>>sdt;
    cout<<"Nhap mat khau: " ;
    string newPW;
    cin >>newPW;
    cout<<"Nhap lai mat khau: ";
    string tempPW;
    cin >>tempPW;
    while (newPW!=tempPW)
    {
        cout<<"Mat khau ban nhap khong trung khop. Vui long nhap lai."<<endl;
        cout<<"Nhap mat khau moi: " ;
        cin >>newPW;
        cout<<"Nhap lai mat khau: ";
        cin >>tempPW;
    }
    pw=newPW;
    cout<<"Nhap so tien nap lan dau: ";
    cin>>soTien;
    cout<<"Da tao thanh vien moi.";
}

void ThanhVien::thongTinTaiKhoan()
{
    cout<<setw(10)<<left<<"Username "<<":"<<setw(40)<<right<< username<<endl;
    cout<<setw(10)<<left<<"Ten "<<":"<<setw(40)<<right<< ten<<endl;
    cout<<setw(10)<<left<<"SDT "<<":"<<setw(40)<<right<< sdt<<endl;
    cout<<setw(10)<<left<<"Loai TK"<<":";
    if(uuDai==1)cout<<setw(40)<<right<<"Thuong"<<endl;
    else cout<<setw(40)<<right<<"VIP"<<endl;
}

void ThanhVien::capNhapVip()
{
    if(thoiGianChoi>1000)uuDai=0.9;
    if(thoiGianChoi>2000)uuDai=0.8;
}

void ThanhVien::napTien()
{
    cout<<"Nhap so tien can nap:";
    int i;
    cin>>i;
    soTien+=i;
}

void ThanhVien::suaThongTin()
{
    cout<<"Sua thong tin tai khoan:"<<endl;
    cout<<"1. Ten"<<endl;
    cout<<"2. SDT"<<endl;
    int i;
    cin>>i;
    if(i==1)
    {
        cout<<"Nhap ten moi: ";
        getline(cin,ten);
    }
    if(i==2)
    {
        cout<<"Nhap SDT moi: ";
        getline(cin,sdt);
    }
}

float ThanhVien::getUudai()
{
    return uuDai;
}
int ThanhVien::getTien()
{
    return soTien;
};
void ThanhVien::setTien (int i)
{
    soTien=i;
};
void ThanhVien::congThoiGian(int n)
{
    thoiGianChoi+=n;
}
string ThanhVien::getTen()
{
    return ten;
}
string ThanhVien::getPW()
{
    return pw;
}
string ThanhVien::getSDT()
{
    return sdt;
}
int ThanhVien::getThoiGianChoi()
{
    return thoiGianChoi;
}
void ThanhVien::setUsername(string temp)
{
    this->username=temp;
};

void ThanhVien::setPW(string temp)
{
    pw=temp;
};

void  ThanhVien::setTen(string temp)
{
    ten=temp;
};
void ThanhVien::setSDT(string temp)
{
    sdt=temp;
};

void ThanhVien::setThoiGianChoi(int  thoiGian)
{
    thoiGianChoi=thoiGian;
};
void ThanhVien::setUuDai(float uuDai)
{
    uuDai=uuDai;
};
