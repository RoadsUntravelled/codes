/*************************************************************************
	> File Name: BubbleSort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月11日 星期日 15时08分43秒
 ************************************************************************/

#include<iostream>
using namespace std;
int cnt=0;
const int length=10;
void swap(int *list,int i,int j){
    int temp=list[i];
    list[i]=list[j];
    list[j]=temp;
    cnt++;
}
int main(){
    int list[length]={3,2,1,5,6,4,7,8,9,10};
    bool flag=true;
    for(int i=length-1;i>0&&flag;i--){
        flag=false;
        for(int j=0;j<i;j++)
        if(list[j]>list[j+1]){
            swap(list,j,j+1);
            flag=true;
        }
    }
    for(int i=0;i<10;i++)
        cout<<list[i]<<" ";
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
