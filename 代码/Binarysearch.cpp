/*************************************************************************
	> File Name: Binarysearch.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月02日 星期二 22时33分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
int Binary_Search(int*a,int n,int key){
    int low=1,high=n,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(key<a[mid])
            high=mid-1;
        else if(key>a[mid])
            low=mid+1;
        else
            return mid;
    }
    return 0;
}
int main(){
    int a[]={0,5,13,19,21,37,56,64,75,80,88,92};
    cout<<"关键值64的位置为:"<<endl<<Binary_Search(a,11,64)<<endl;
    return 0;
}
