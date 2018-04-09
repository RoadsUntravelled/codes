/*************************************************************************
	> File Name: stringcon.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月03日 星期二 19时15分58秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    string a("123456");
    string b(a,0,5);
    cout<<a.find("5")<<endl;
    cout<<b.find("6")<<endl;
    return 0;
}
