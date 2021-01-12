#pragma once
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <iomanip>
#include "qlPhien.h"
#include "tool.h"
class Menu{
public:
    qlPhien qlP;
    void adminMenu();
    void tvMenu();
    void phienMenu();
    void mayMenu();
    void thaydoiGia();
    void quanLiTaiKhoanThanhVien();
    void taoThanhVien();
    void timThanhVien();


};
#endif // MENU_H_INCLUDED
