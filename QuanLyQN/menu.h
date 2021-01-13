#pragma once
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <iomanip>
#include "qlPhien.h"
#include "tool.h"
class Menu{
public:
    Menu();
    qlPhien qlP;
    void adminMenu();
    void tvMenu();
    void phienMenu();
    void mayMenu();
    void thaydoiGia();
    void quanLiTaiKhoanThanhVien();
    void taoThanhVien();
    void timThanhVien();
    void quanLiMay();
    void taoMay();
    void timMay();
    void quanliPhien();
    void moMay();
    void tatMay();
    void xemDoanhThu();


};
#endif // MENU_H_INCLUDED
