/*************************************************************************
	> File Name: fastpower.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月28日 星期三 16时08分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
int pow4(int a,int b){
    int r=1,base=a;
    while(b){
        cout<<"r="<<r<<",base="<<base<<",b="<<b<<endl;
        if(b&1)r*=base;
        base*=base;
        b>>=1;
    }
    return r;
}
int main(){
    int a,n;
    while(cin>>a>>n){
        cout<<pow4(a,n)<<endl;
    }
    return 0;
}
