/*************************************************************************
	> File Name: typedefpoint.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月30日 星期五 20时13分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
typedef int Demo[9];
int main(){
    Demo *p;
    p[0][0]=1;
    cout<<p[0][0];
    return 0;
}
