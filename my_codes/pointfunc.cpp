/*************************************************************************
	> File Name: pointfunc.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月03日 星期二 18时33分43秒
 ************************************************************************/

#include<iostream>
using namespace std;
int*func(int*p,int i){
    return p+i;
}
int main(){
    int p[]={5,8,9,1,2};
    cout<<p[0];
    *func(p,0)=2;
    cout<<p[0];
    return 0;
}
