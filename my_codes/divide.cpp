/*************************************************************************
	> File Name: divide.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月07日 星期三 19时57分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
int divide(int n,int m){
    if(n<1||m<1)return 0;
    if(n==1||m==1)return 1;
    if(n<m)return divide(n,n);
    if(n==m)return divide(n,m-1)+1;//划分成最大加数不大于m-1,且有一个划分,即n
    return divide(n,m-1)+divide(n-m,m);//正整数n的最大加数n1不大于m的划分由n1=m的划分(当n1=m时,计算剩下n-n1的数的排列数目)和n1<=m-1的划分组成
}
int main(){
    for(int i=5;i<=10;i++)
        cout<<divide(i,i)<<endl;
    return 0;
}
