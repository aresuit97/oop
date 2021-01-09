
#ifndef QLMAY_H_INCLUDED
#define QLMAY_H_INCLUDED
#include "may.h"

class qlMay
{
    int soLuong;
    May** qMay;
public:
    void them(May* m);
    May** getDsMay();


};
#endif // QLMAY_H_INCLUDED
