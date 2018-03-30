/*************************************************************************
	> File Name: CircleArea.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月30日 星期五 15时54分35秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    double PI=atan(1.0)*4;
    int n;
    cin>>n;
    double area=double(n*n)*PI*10000000;
    printf("%.7lf\n",area/10000000);
    return 0;
}
