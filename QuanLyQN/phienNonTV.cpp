#include "phienNonTV.h"

phienNonTV::PhienNonTV()
{
    timeTemp=time(0);
    cin>>mayID;
    cin>>thoiGian;
    cin>>tienChoi;
}
int phienNonTV::type()
{
    return 0;
};

void phienNonTV::tatMay(){
    if(trangThaiPhien){
        trangThaiPhien=false;
        m=nullptr;

    }

}
