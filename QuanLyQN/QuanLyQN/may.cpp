#include "may.h"

string May::info(){
        return "NOR";
    };
int May::thanhtien(){
        return giaTienMayThuong;
    };
int May::getID() {return ID;}

void May::doiTrangThai(){
    trangThai=(trangThai)?false:true;
};

void May::setID(int n){
    ID=n;
};

May::May(int n){
    trangThai=false;
    ID=n;
}
May::May()
    {
        trangThai=false;
        ID=0;
    };

void May::display(){
        cout<<"NOR"<<ID<<"  "<<trangThai<<endl;
    }


bool May::getTrangThai(){
    return trangThai;
}

