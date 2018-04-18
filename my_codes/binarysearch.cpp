/*************************************************************************
	> File Name: binarysearch.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月17日 星期二 13时28分09秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int binarysearch(int*arr,const int& x,const int& n){
    int left=0,right=n-1;
    int cnt=0;
    while(left<=right){
        cout<<cnt++<<endl; 
        int middle=(left+right)/2;
        if(x==arr[middle])return middle;
        else if(x<arr[middle])
            right=middle-1;
        else 
            left=middle+1;
    }
    return -1;
}
int main(){
    int arr[]={1,5,9,50};
    int res=binarysearch(arr,9,4);
    if(res!=-1)
        cout<<res<<endl;
    else
        cout<<"error"<<endl;
    return 0;
}
