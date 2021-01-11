#ifndef QLPHIEN_H_INCLUDED
#define QLPHIEN_H_INCLUDED
#include "phienTV.h"
#include "phienNonTV.h"
#include <fstream>
#include <istream>
class qlPhien{
    Phien** qP;
    int soLuong;
    qlMay qM;
    qlThanhVien qTV;
public:
    qlPhien();
    void themPhien(phienTV* p);
    void themPhien(phienNonTV* p);
    void update();
    int getSL(){return soLuong;}
    void setSL(int sl){soLuong=sl;}
    long long tongDoanhthu();
    void nhapDSMay();
    void xuatDSMay();
    void nhapDSTV();
    void xuatDSTV();
    void xuatDSPhien();
    void nhapDSPhien();
    void setDSTV(qlThanhVien qt);
    qlThanhVien getDS();
    void themThanhVien();
    qlMay getDSMay(){return qM;};
    void setDSMay(qlMay m){qM=m;};
    void display();
};


#endif // QLPHIEN_H_INCLUDED
