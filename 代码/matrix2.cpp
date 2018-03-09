/*************************************************************************
	> File Name: matrix2.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月11日 星期四 18时24分21秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int a[2][2]={0,1,2,3};
    int **p;
    *p=a[0];
    **p=a[0][0];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cout<<p[i][j]<<" ";
    return 0;
}
