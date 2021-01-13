#include "may.h"
#include <iomanip>
string May::info()
{
    return "NOR";
};
float May::thanhtien()
{
    return (float)giaTienMayThuong/3600;
};
int May::getID()
{
    return ID;
}

void May::doiTrangThai()
{
    trangThai=(trangThai)?false:true;
};

void May::setID(int n)
{
    ID=n;
};

May::May(int n)
{
    trangThai=false;
    ID=n;
}
May::May()
{
    trangThai=false;
    ID=0;
};

void May::display()
{
    cout<<" NOR"<<ID<<"  ";
    if(ID<10)cout<<" ";
    if(trangThai)cout<<setw(30)<<right<<"Dang dung";
    else cout<<setw(30)<<right<<"Dang tat";
}


bool May::getTrangThai()
{
    return trangThai;
}

