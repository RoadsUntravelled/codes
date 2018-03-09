/*************************************************************************
	> File Name: perm.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月07日 星期三 19时15分05秒
 ************************************************************************/

#include<iostream>
using namespace std;
void swap(int list[],int fir,int sec){
    int temp;
    temp=list[fir];
    list[fir]=list[sec];
    list[sec]=temp;
}
void perm(int list[],int k,int m){
    if(k==m){//前缀为list[0..m]后缀为list[m..m],排列list[m...m]
        for(int i=0;i<=m;i++)
            cout<<list[i];
        cout<<endl;
    }
    else
    for(int i=k;i<=m;i++){
        swap(list,k,i);//交换后计算list[k+1:m]的全排列
        perm(list,k+1,m);//排列list[k+1...m]
        swap(list,k,i);
    }
}
int main(){
    int array[]={1,2,3,4};
    perm(array,0,3);//前缀为a[0..0]后缀为a[0..3],排列a[0...m]
    return 0;
}
