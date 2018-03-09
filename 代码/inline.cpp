/*************************************************************************
	> File Name: inline.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月11日 星期四 18时32分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int a[2][2]={1,2,3,4};
    int  *p[2]={a[0],a[1]};
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cout<<p[i][j]<<" ";
    return 0;
}
