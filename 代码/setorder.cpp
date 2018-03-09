/*************************************************************************
	> File Name: setorder.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月07日 星期三 16时29分13秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
void perm(int list[],int k,int m){
    if(k==m){
        for(int i=0;i<m;i++)
            cout<<list[i];
        cout<<endl;
    }
    else
        for(int i=k;i<=m;i++){
            swap(list[k],list[i]);
            perm(list,k+1,m);
            swap(list[k],list[i]);
    }
}
int main(){
    int a[]={1,2,3};
    perm(a,1,3);
    return 0;
}
