/*************************************************************************
	> File Name: 二维指针数组.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月11日 星期四 19时03分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
int *array(int a,int b){
    int c[2]={a,b};
    int*p=c;
    for(int i=0;i<2;i++)
    cout<<p[i]<<endl;
    return p;
}
int main(){
    int *arr;
    arr=array(1,2);
    for(int i=0;i<2;i++)
        cout<<arr[i]<<endl;
    return 0;
}
