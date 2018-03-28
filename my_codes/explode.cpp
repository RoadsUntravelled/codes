/*************************************************************************
	> File Name: explode.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月27日 星期二 21时21分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
int cnt=1;
void f(){
    cout<<cnt++<<endl;
    f();
}
int main(){
    f();
    return 0;
}

