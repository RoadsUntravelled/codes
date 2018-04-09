/*************************************************************************
	> File Name: extern.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月03日 星期二 15时38分27秒
 ************************************************************************/

#include<iostream>
#include"origin.cpp"
using namespace std;
int i=3;
void next();
int main(){
    i++;
    next();
    return 0;
}
void next(){
    i++;
    other();
}
