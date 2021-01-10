#ifndef QLPHIEN_H_INCLUDED
#define QLPHIEN_H_INCLUDED
#include "phienTV.h"
#include "phienNonTV.h"
class qlPhien{
    Phien** qP;
    int soLuong;
    qlMay qM;
    qlThanhVien qTV;
public:
    qlPhien();
    void themPhien(phienTV p);
    void themPhien(phienNonTV p);
    void update();
    int getSL(){return soLuong;}
    void setSL(int sl){soLuong=sl;}

};


#endif // QLPHIEN_H_INCLUDED
