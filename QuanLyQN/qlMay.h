
#ifndef QLMAY_H_INCLUDED
#define QLMAY_H_INCLUDED
#include "mayThuong.h"
#include "mayVip.h"

class qlMay
{
    int soLuong;
    May** qMay;
public:
    qlMay();
    void them(mayThuong* m);
    void them(mayVip* m);
    May** getDsMay();
    int getSL(){
    return soLuong;}
    void setSL(int sl){soLuong=sl;}

};
#endif // QLMAY_H_INCLUDED
