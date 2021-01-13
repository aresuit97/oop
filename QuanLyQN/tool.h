#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED
#pragma once
#include <string>
using namespace std;

class Tool
{
public:
    bool subString(string s1, string s2);
    string nomalize(string s);
    bool laSo(string t);
    bool checkKhoangTrang(string s);
    bool isSDT(string a);
    string trim(string a);
    string chuanHoa(string a);
    bool matkhau(string a);
    int lamtrontien(int t);
};
#endif // TOOL_H_INCLUDED
