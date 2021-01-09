#ifndef PHIENNONTV_H_INCLUDED
#define PHIENNONTV_H_INCLUDED
#include "phien.h"

class phienNonTV:public Phien{


    public:
        int type(){return 0;};
        PhienNonTV(){
        timeTemp=time(0);
        cin>>mayID;
        cin>>thoiGian;
        cin>>tienChoi;
    }


};

#endif // PHIENNONTV_H_INCLUDED
