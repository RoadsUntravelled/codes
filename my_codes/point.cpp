/*************************************************************************
	> File Name: point.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月30日 星期五 18时44分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,6};
    int*p=a;
    int j=5;
    cout<<p<<" "<<a<<endl;
    while(p){
    cout<<p++<<" "<<a<<endl;
    if(j==0)
        break;
    j--;
    }
    return 0;
}
