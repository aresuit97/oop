
#ifndef QLMAY_H_INCLUDED
#define QLMAY_H_INCLUDED
#include "mayVip.h"

class qlMay
{
    int soLuong;
    May** qMay;
public:
    qlMay();
    void them(May* m);
    May** getDsMay();
    int getSL(){
    return soLuong;}
    void setSL(int sl){soLuong=sl;}
    void setDsMay(May** pt);
    void reset();
    void display();

};
#endif // QLMAY_H_INCLUDED
