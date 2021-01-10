#include <iostream>
#include <ctime>
#include "qlThanhVien.h"
using namespace std;

int main()
{

    //  adminMenu();
    qlThanhVien ql;
    ThanhVien tv;
    tv.taoTV();
    ThanhVien *temp=&tv;
    ql.themTV(temp);
    ql.themTV(temp);
    ql.display();


    return 0;
}

