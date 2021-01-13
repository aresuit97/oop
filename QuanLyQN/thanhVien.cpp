#include "thanhVien.h"

ThanhVien::ThanhVien()
{
    thoiGianChoi=0;
    soTien=0;
    username=pw=ten=sdt="";
    uuDai=1;
}
ThanhVien::ThanhVien(string user,string password,string Ten,string SDT,int sotien,int thoigian,float uudai){
    username=user;
    pw=password;
    ten=Ten;
    sdt=SDT;
    soTien=sotien;
    thoiGianChoi=thoigian;
    uuDai=uudai;

}

string ThanhVien::getUsername()
{
    return username;
}


int thoiGianChoi,soTien;
    string username,pw,ten,sdt;
    float uuDai;

    void ThanhVien::taoTV()
{
    Tool t;
    cout<< "Nhap username:";
    getline(cin,this->username);
    cout<<"Nhap ten: ";
    getline(cin,this->ten);
    cout<<"Nhap sdt: ";
    cin>>sdt;
    while(t.isSDT(sdt)!=true){
        cout<<"So dien thoai chi bao gom co 10 chu so. Hay nhap lai:";
        cin>>sdt;
    }
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
    Tool t;
    cout<<setw(15)<<left<< username<<setw(23)<<left<<ten<<setw(13)<<left<<sdt<<setw(10)<<right<<t.lamtrontien(soTien)<<setw(7)<<right<<thoiGianChoi/3600<<":"<<setw(2)<<right<<thoiGianChoi%3600/60;
    if(uuDai==1)cout<<setw(10)<<right<<"Thuong"<<endl;
    if(uuDai!=1) cout<<setw(10)<<right<<"VIP"<<endl;
}

void ThanhVien::capNhatVip()
{
    if(thoiGianChoi>50*3600)uuDai=0.9;
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
    Tool t;
    cout<<"Sua thong tin tai khoan:"<<endl;
    cout<<"1. Ten"<<endl;
    cout<<"2. SDT"<<endl;
    cout<<"3. Nap tien."<<endl;
    int i;
    cin>>i;
    cin.ignore();
    if(i==1)
    {
        cout<<"Nhap ten moi: ";
        getline(cin,ten);
        ten=t.chuanHoa(ten);
    }
    if(i==2)
    {
        cout<<"Nhap SDT moi: ";
        getline(cin,sdt);
        while(!t.isSDT(sdt)){
            cout<<"Vui long nhap lai so dien thoai(gom 10 chu so):";
            getline(cin,sdt);
        }
    }
    if(i==3){
        cout<<"Nhap mat khau moi:";
        string tempPW;
        getline(cin,tempPW);
        while(!t.matkhau(tempPW)){
            cout<<"Mat khau khong hop le! Vui long nhap lai mat khau: "<<endl;
            cin>>tempPW;
        }
        cout<<"Nhap lai mat khau";
        string tempPW2;
        getline(cin,tempPW2);
        while(tempPW2!=tempPW)
        {
            cout<<"Mat khau ban nhap khong trung khop. Vui long nhap lai."<<endl;
            cout<<"Nhap mat khau moi: " ;
             getline(cin,tempPW);
            while(!t.matkhau(tempPW)){
            cout<<"Mat khau khong hop le! Vui long nhap lai mat khau: "<<endl;
             getline(cin,tempPW);
            }
            cout<<"Nhap lai mat khau: ";
             getline(cin,tempPW2);
        }
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
    username=temp;
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
