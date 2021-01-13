#include "menu.h"
#include <vector>
#include <windows.h>
void Menu::timThanhVien()
{
    qlP.timThanhVien();
}
void Menu::quanliPhien(){
    while(1){
    system("CLS");
    cout<<"Cac chuc nang quan li phien."<<endl;
    cout<<"1.Hien thi cac phien hien tai."<<endl;
    cout<<"2.Xuat phien ra file."<<endl;
    cout<<"3.Nhap phien tu file."<<endl;
    cout<<"Nhap lua chon cua ban: ";
    string cn;
    getline(cin,cn);
    if(cn!="1"&&cn!="2"&&cn!="3"&&cn!="0")return;
    if(cn=="1"){
        qlP.display();
        cin.get();
    }
    if(cn=="2"){
        qlP.xuatDSPhien();

        cin.get();
    }
    if(cn=="3"){
        qlP.nhapDSPhien();
        cout<<"Da cap nhat danh sach phien."<<endl;
        qlP.display();
        cin.get();
    }
    if(cn=="0")
        return;
    }
}
void Menu::taoThanhVien()
{
    system("CLS");
    cout<<"Tao thanh vien moi"<<endl;
    qlP.themThanhVien();
    cin.get();
    return;
}
void Menu::taoMay()
{
    Tool t;
    qlP.taoMay();
}
void Menu::quanLiTaiKhoanThanhVien()
{
    while(1)
    {
        system("CLS");
        cout<<"Cac chuc nang quan li thanh vien:"<<endl;
        cout<<"a. Xem ds thanh vien."<<endl;
        cout<<"b. Tao thanh vien."<<endl;
        cout<<"c. Tim kiem thanh vien."<<endl;
        cout<<"d. Nhap danh sach thanh vien."<<endl;
        cout<<"e. Xuat danh sach thanh vien."<<endl;
        cout<<"Nhap lua chon cua ban: ";
        string s;
        getline(cin,s);
        while(s!="a"&&s!="b"&&s!="c"&&s!="d"&&s!="e"&&s!="0"&&s!="f")
        {
            cout<<"Vui long nhap dung yeu cau! Lua chon cua ban: ";
            getline(cin,s);
        }
        if(s=="0")return;
        if(s=="a")
        {

            qlP.getDS().display();
            cin.get();
        }
        if(s=="b")taoThanhVien();
        if(s=="c")timThanhVien();
        if(s=="d"){
                qlP.nhapDSTV();
                cout<<"Da nhap danh sach thanh vien.";
                cin.get();
        }
        if(s=="e"){qlP.xuatDSTV();
        cout<<"Da xuat danh sach thanh vien.";
                cin.get();
        }
    }
}

void Menu::timMay()
{
    qlP.timMay();
}
void Menu::quanLiMay()
{
    while(1)
    {
        system("CLS");
        cout<<"Cac chuc nang quan li may: "<<endl;
        cout<<"a. Xem ds may."<<endl;
        cout<<"b. Tao may."<<endl;
        cout<<"c. Tim kiem may."<<endl;
        cout<<"d. Bat may."<<endl;
        cout<<"e. Tat may."<<endl;
        cout<<"f. Nhap danh sach may."<<endl;
        cout<<"g. Xuat danh sach may."<<endl;
        cout<<"Nhap lua chon cua ban(Nhap 0 de quay ve menu chinh): ";
        string s;
        getline(cin,s);
        while(s!="a"&&s!="b"&&s!="c"&&s!="d"&&s!="e"&&s!="f"&&s!="0")
        {
            cout<<"Vui long nhap dung yeu cau! Lua chon cua ban: ";
            getline(cin,s);
        }
        if(s=="0")return;
        if(s=="a")
        {
            qlP.getDSMay().display();
            cin.get();
        }
        if(s=="b")taoMay();
        if(s=="c")timMay();
        if(s=="d")moMay();
        if(s=="e")tatMay();
        if(s=="f")qlP.nhapDSMay();
        if(s=="g")qlP.xuatDSMay();
    }
}
void Menu::moMay()
{
    Tool t;
    string s;
    cout<<"Nhap id may can mo: (Nhap 0 de quay ve menu chinh): ";
    qlMay tempM=qlP.getDSMay();
    int n;
    int pos;
    int flag=0;
    while(!flag)
    {
        getline(cin,s);
        if(s=="0")return;
        if(!(s.length()<2&&t.laSo(s))){
           cout<<"ID khong hop le! Vui long nhap lai: ";
           continue;
           }
        n=stoi(s);
        if(!tempM.check(n)){
            cout<<"Khong co may ban chon! Vui long nhap lai: ";
            continue;
        }
        for(int i=0;i<tempM.getSL();i++){
            if(tempM.getDsMay()[i]->getID()==n){
                if(tempM.getDsMay()[i]->getTrangThai()){
                    cout<<"May da co nguoi! Vui long chon may khac:";
                    break;
                }
                else {
                    phienNonTV* tempP;
                    tempP=new phienNonTV(n);
                    flag=1;
                    qlP.themPhien(tempP);
                    break;
                }
            }
        }

    }
}
void Menu::thaydoiGia()
{
    cout<<"Ban muon thay doi gia cua: "<<endl;
    cout<<"   1.May thuong."<<endl;
    cout<<"   2.May vip."<<endl;
    cout<<"Chon option cua ban(Nhap 0 de quay lai): ";
    int n;
    cin>>n;
    while (n!=2&&n!=1&&n!=0)
    {
        cout<<"Hay nhap chinh xac!. Lua chon cua ban: ";
        cin>>n;
    }
    if(n==0)return;
    if(n==1)
    {
        cout<<"Gia cua may thuong hien tai dang la "<<giaTienMayThuong<<" d/h."<<endl;
        cout<<"Ban hay nhap gia moi: ";
        cin>>giaTienMayThuong;
        return;
    }
    if(n==2)
    {
        cout<<"Gia cua may thuong VIP dang la "<<giaTienMayVip<<" d/h."<<endl;
        cout<<"Ban hay nhap gia moi:  ";
        cin>>giaTienMayVip;
        return;
    }
}
void Menu::xemDoanhThu(){
    Tool t;
    int ans=0;
    for (int i=0;i<qlP.getSL();i++){
        ans+=t.lamtrontien(qlP.getDSPhien()[i]->getTienChoi());
    }
    cout<<"Tong thu nhap cua quan la "<<ans;
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
        cout<<setw(2)<<right<<"4"<<".Quan ly cac phien hoat dong."<<endl;
        cout<<setw(2)<<right<<"5"<<".Xem doanh thu."<<endl;
        cout<<setfill('-');
        cout<<setw(50)<<"-";
        cout<<endl;
        cout<<setfill(' ');
        cout<<"Chon chuc nang ban muon su dung (Nhap 0 de thoat chuong trinh): ";
        string x;
        getline(cin,x);
        while (x!="1"&&x!="2"&&x!="3"&&x!="4"&&x!="5"&&x!="6"&&x!="0")
        {
            cout<<"Vui long nhap lua chon chinh xac! Lua chon cua ban: ";
            getline(cin,x);
        }
        if(x=="0")return;
        if(x=="1")quanLiTaiKhoanThanhVien();
        if(x=="2")thaydoiGia();
        if(x=="3")quanLiMay();
        if(x=="4")quanliPhien();
        if(x=="5")xemDoanhThu();
    }
}


void Menu::tatMay()
{
    cout<<"Danh sach cac may dang mo: "<<endl;
    int pos[100];
    int cnt=0;
    for (int i=0;i<qlP.getSL();i++){
        if(qlP.getDSPhien()[i]->getTrangThai()){
                pos[cnt]=i;
                cnt++;
            cout<<cnt<<". "<<qlP.getDSPhien()[i]->getMay()->info()<<qlP.getDSPhien()[i]->getMay()->getID()<<endl;
        }
    }
    cout<<"Chon may ban muon tat: ";
    int n;
    cin>>n;
    while(n<0||n>cnt)
    {
        cout<<"Vui long nhap dung lua chon! Lua chon cua ban: ";
        cin>>n;
        if(n==0)return ;
    }
    int posM=pos[n-1];
    qlP.getDSPhien()[posM]->doiTrangThai();
    cout<<"Da tat may "<<qlP.getDSPhien()[posM]->getMay()->info()<<qlP.getDSPhien()[posM]->getMay()->getID()<<endl;
    cout<<"So tien phai tra: "<<qlP.getDSPhien()[posM]->getTienChoi();
    qlP.getDSPhien()[posM]->setMay(nullptr);

}

Menu::Menu(){
    qlP.nhapDSMay();
    qlP.nhapDSPhien();
    qlP.nhapDSTV();
    qlP.update();
}

