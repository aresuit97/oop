#include "menu.h"
#include "qlPhien.h"


void adminMenu()
{
    system("CLS");
    cout<<setw(2)<<right<<"1"<<".Mo may."<<endl;
    cout<<setw(2)<<right<<"2"<<".Tat may."<<endl;
    cout<<setw(2)<<right<<"3"<<".Nap tien."<<endl;
    cout<<setw(2)<<right<<"4"<<".Quan li tai khoan thanh vien"<<endl;
    cout<<setw(2)<<right<<"5"<<".Thay doi gia gio choi."<<endl;
    cout<<setw(2)<<right<<"6"<<".Quan li may"<<endl;
    cout<<setw(2)<<right<<"7"<<".Xem danh sach thanh vien dang hoat dong."<<endl;
    cout<<setw(2)<<right<<"8"<<".Quan ly cac phien hoat dong."<<endl;
    cout<<setw(2)<<right<<"9"<<".Cap nhat danh sach thanh vien."<<endl;
    cout<<setfill('-');
    cout<<setw(50)<<"-";
    cout<<endl;
    cout<<setfill(' ');
    cout<<"Chon chuc nang ban muon su dung:";
    int x ;
    cin>>x;
    while (0)
    {
        system("CLS");
    }
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
