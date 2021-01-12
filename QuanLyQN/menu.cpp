#include "menu.h"
#include <vector>
void Menu::timThanhVien()
{
    Tool z;
    string t;
    cout<<"Tim kiem theo username:";
    getline(cin,t);
    int ans[100];
    int cnt=0;
    t=z.nomalize(t);
    qlThanhVien a=qlP.getDS();
    for (int i=0; i<a.getSL(); i++)
    {
        string userTemp=a.getds()[i]->getUsername();
        userTemp=z.nomalize(userTemp);
        if(z.subString(userTemp,t))
        {
            cout<<i<<endl;
            ans[cnt]=i;
            cnt++;
            cout<<cnt<<".";
            a.getds()[i]->thongTinTaiKhoan();
        }
    };
    if(cnt==0)
    {
        int t;
        cout<<"Khong tim thay thanh vien nao.";
        cin>>t;
        return;
    }
    else
    {
        cout<<"Chon thanh vien ban muon xu ly:";
        int n;
        cin>>n;
        while(n<1||n>cnt)
        {
            cout<<"Vui long nhap dung lua chon! Lua chon cua ban:";
            cin>>n;
        }
        int pos=ans[n-1];
        cout<<"Thanh vien ban chon: ";
        a.getds()[pos]->thongTinTaiKhoan();
        cout<<"Chon thao tac ban muon xu ly voi thanh vien nay: "<<endl;
        cout<<"1. Xoa thanh vien."<<endl;
        cout<<"2. Sua thanh vien."<<endl;
        cout<<"Lua chon cua ban:";
        cin>>n;
        while (n!=1&&n!=2)
        {
            cout<<"Vui long nhap lai thong tin chinh xac! Lua chon cua ban:";
            cin>>n;
        }
        if(n==1)
        {
            string temp=a.getds()[pos]->getUsername();
            a.xoaThanhVien(pos);
            qlP.setDSTV(a);
        }
        if(n==2)
        {
            a.getds()[pos]->suaThongTin();
        }
    }
}
void Menu::taoThanhVien()
{
    Tool t;
    cout<<setw(50)<<'-'<<endl;
    cout<<"Nhap username: ";
    string username;
    getline(cin,username);
    while(qlP.getDS().check(username)||!t.checkKhoangTrang(username))
    {
        cout<<"Username khong hop le. Vui long nhap lai:";
        getline(cin,username);
    }
    cout<<"Nhap ten:";
    string ten;
    getline(cin,ten);
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
    string SDT;
    cout<<"Nhap sdt: ";
    cin>>SDT;
    while(t.isSDT(SDT)==false)
    {
        cout<<"So dien thoai chi bao gom co 10 chu so. Hay nhap lai:";
        cin>>SDT;
    }

    int soTien;
    cout<<"Nhap so tien nap lan dau: ";
    cin>>soTien;
    ThanhVien* temp= new ThanhVien(username,newPW,ten,SDT,soTien,0,1);
    qlThanhVien tv=qlP.getDS();
    temp->thongTinTaiKhoan();
    system("pause");
    tv.themTV(temp);
    qlP.setDSTV(tv);
    cout<<"Da tao thanh vien moi.";
}
void Menu::quanLiTaiKhoanThanhVien()
{
    while(1)
    {
        cout<<"a. Xem ds thanh vien."<<endl;
        cout<<"b. Tao thanh vien."<<endl;
        cout<<"c. Tim kiem thanh vien."<<endl;
        cout<<"d. Nhap danh sach thanh vien."<<endl;
        cout<<"e. Xuat danh sach thanh vien."<<endl;
        cout<<"Nhap lua chon cua ban:";
        string s;
        getline(cin,s);
        while(s!="a"&&s!="b"&&s!="c"&&s!="d"&&s!="0")
        {
            cout<<"Vui long nhap dung yeu cau! Lua chon cua ban:";
            getline(cin,s);
        }
        if(s=="0")return;
        if(s=="a")
        {
            qlP.getDS().display();
            system("pause");
        }
        if(s=="b")taoThanhVien();
        if(s=="c")timThanhVien();
        if(s=="d")qlP.nhapDSTV();
        if(s=="e")qlP.xuatDSTV();
    }
}

void Menu::adminMenu()
{

    string x="";
    while(1)
    {
        system("CLS");
        cout<<setw(2)<<right<<"1"<<".Quan li tai khoan thanh vien"<<endl;
        cout<<setw(2)<<right<<"2"<<".Thay doi gia gio choi."<<endl;
        cout<<setw(2)<<right<<"3"<<".Quan li may"<<endl;
        cout<<setw(2)<<right<<"4"<<".Xem danh sach thanh vien dang hoat dong."<<endl;
        cout<<setw(2)<<right<<"5"<<".Quan ly cac phien hoat dong."<<endl;
        cout<<setw(2)<<right<<"6"<<".Xem doanh thu."<<endl;
        cout<<setfill('-');
        cout<<setw(50)<<"-";
        cout<<endl;
        cout<<setfill(' ');
        cout<<"Chon chuc nang ban muon su dung (Nhap 0 de thoat chuong trinh):";
        string x;
        getline(cin,x);
        while (x!="1"&&x!="2"&&x!="3"&&x!="4"&&x!="5"&&x!="6"&&x!="0")
        {
            cout<<"Vui long nhap lua chon chinh xac! Lua chon cua ban:";
            getline(cin,x);
        }
        if(x=="0")return;
        if(x=="1")quanLiTaiKhoanThanhVien();
//        if(x=="3")quanLiTaiKhoanThanhVien();

    }
}
void moMay()
{

}
void tatMay()
{
}

void thaydoiGia()
{
    cout<<"Ban muon thay doi gia cua: "<<endl;
    cout<<"   1.May thuong."<<endl;
    cout<<"   2.May vip."<<endl;
    cout<<"Chon option cua ban(Nhap 0 de quay lai):";
    int n;
    cin>>n;
    while (n!=2&&n!=1&&n!=0)
    {
        cout<<"Hay nhap chinh xac!. Lua chon cua ban:";
        cin>>n;
    }
    if(n==0)return;
    if(n==1)
    {
        cout<<"Gia cua may thuong hien tai dang la "<<giaTienMayThuong<<" d/h."<<endl;
        cout<<"Ban hay nhap gia moi:";
        cin>>giaTienMayThuong;
        return;
    }
    if(n==2)
    {
        cout<<"Gia cua may thuong VIP dang la "<<giaTienMayVip<<" d/h."<<endl;
        cout<<"Ban hay nhap gia moi:";
        cin>>giaTienMayVip;
        return;
    }
}


