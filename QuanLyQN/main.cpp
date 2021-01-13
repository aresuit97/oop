#include <iostream>
#include <ctime>
#include "menu.h"
#include <windows.h>
using namespace std;
int main()
{

//   string a="ho ten";
//   phienTV s ;
//   s.setID(8);
//   s.setThoiGian(10000);
//   s.setThoiGian(4220);
//   s.setTrangThai(1);
//   s.setUsername("aila");
//    Sleep(2000);
//    s.tinhTien();
    Menu* mn=new Menu();
    mn->adminMenu();

    return 0;
}

