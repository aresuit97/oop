#include "tool.h"

bool Tool::subString(string s1, string s2){
    if(s1.find(s2)!=string::npos)return true;
    return false;
 }


 string Tool::nomalize(string s){
     string a=s;
    for (int i=0;i<a.length();i++){
        if(a[i]>'A'&&a[i]<'S'){
            a[i]+=32;
        }
    }
    return a;
 }

 bool Tool::laSo(string t){
     for (int i=0;i<t.length();i++){
        if(!(t[i]<='9'&&t[i]>='0'))
        return false;
     }
     return true;
 }


bool Tool::checkKhoangTrang(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==' ')return false;
    }
    return true;
}


bool Tool::isSDT(string a)
{
    if(a.length()!=10)return false;
    for (int i=0; i<a.length(); i++)
    {
        if(!(a[i]<='9'&&a[i]>='0'))return false;
    }
    return true;
}
string Tool::trim(string a){
	while(a[0]==' ')a=a.substr(1);
	while(a[a.length()-1]==' ')a=a.substr(0,a.length()-1);
	return a;
}
string Tool::chuanHoa(string a){
    a=trim(a);
    if(a[0]<='z'&&a[0]>='a')a[0]-=32;
    for (int i=0;i<a.length();i++){
        if(a[i]<='z'&&a[i]>='a'&&a[i-1]==' '){
            a[i]-=32;
        }
        if(a[i]<='Z'&&a[i]>='a'&&a[i-1]==' '){
            a[i]+=32;
        }
    }
    return a;
}
bool Tool::matkhau(string a){
    if(!checkKhoangTrang(a)||a.length()<5)return false;
    return true;
}
int Tool::lamtrontien(int t){
    return((t%1000)>500)?((t/1000+1)*1000):(t/1000*1000);
}

;

