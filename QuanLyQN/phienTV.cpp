#include "phienTV.h"
int phienTV::type()
{
    return 1;
}
phienTV::PhienTV()
{
    timeTemp=time(0);
    cin>>mayID;
    cin>>thoiGian;
    cin>>tienChoi;
    cin>>tenTV;
    trangThaiPhien=false;
}


