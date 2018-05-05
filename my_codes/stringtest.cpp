/*************************************************************************
	> File Name: stringtest.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月29日 星期日 19时00分10秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    string s;
    s.resize(10);
    for(int i=0;i<10;i++)
        s[i]='1';
    cout<<s<<endl;
    return 0;
}
