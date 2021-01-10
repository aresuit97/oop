#include "may.h"


void May::moMay(){
    trangThai=true;
    timeIn=time(0);
}
void May::tatMay(){
    trangThai=false;
}


int May::getID(){return ID};

void May::doiTrangThai(){
    trangThai=(trangThai==true)?false:true;
}




