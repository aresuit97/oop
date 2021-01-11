#include <iostream>
#include <ctime>
#include "qlThanhVien.h"
#include "qlPhien.h"
using namespace std;

int main()
{
    qlPhien qlP;
    qlMay tempdsMay;

//    for (int i=0;i<2;i++){
//        May* temp=new May(i+1);
//        tempdsMay.them(temp);
//        temp=nullptr;
//        delete temp;
//    }
//    for (int i=2;i<4;i++){
//        May* tempI=new mayVip(i+1);
//        tempdsMay.them(tempI);
//        tempI=nullptr;
//        delete tempI;
//    }
//     qlP.setDSMay(tempdsMay);
//      qlP.xuatDSMay();
    qlP.nhapDSPhien();
    qlP.display();
    return 0;
}

