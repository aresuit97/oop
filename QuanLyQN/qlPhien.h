#ifndef QLPHIEN_H_INCLUDED
#define QLPHIEN_H_INCLUDED
#include "phienTV.h"
#include "phienNonTV.h"
#include <fstream>
#include <istream>
class qlPhien
{
    Phien** qP;
    int soLuong;
    qlMay qM;
    qlThanhVien qTV;
public:
    qlPhien();
    void themPhien(phienTV* p);
    void themPhien(phienNonTV* p);
    void displayDSMay();
    void searchTvMay(int n);
    void taoMay();
    void timThanhVien();
    void update();
    void hienPhienOnl();
    int getSL();
    void setSL(int sl);
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
    qlMay getDSMay();
    void setDSMay(qlMay m);
    void display();
    Phien** getDSPhien();
    void setDSPhien(Phien** s);
    void timMay();
    void themPhien(Phien* p);

};


#endif // QLPHIEN_H_INCLUDED
