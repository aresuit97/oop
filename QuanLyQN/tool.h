#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED
#pragma once
#include <string>
using namespace std;

class Tool{
public:

 bool subString(string s1, string s2){
    if(s1.find(s2)!=string::npos)return true;
    return false;
 }
 string nomalize(string s){
     string a=s;
    for (int i=0;i<a.length();i++){
        if(a[i]>'A'&&a[i]<'S'){
            a[i]+=32;
        }
    }
    return a;
 }


bool checkKhoangTrang(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==' ')return false;
    }
    return true;
}

bool isSDT(string a)
{
    if(a.length()!=10)return false;
    for (int i=0; i<a.length(); i++)
    {
        if(!(a[i]<='9'&&a[i]>='0'))return false;
    }
    return true;
}
};



#endif // TOOL_H_INCLUDED
