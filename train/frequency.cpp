/*************************************************************************
	> File Name: frequency.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年09月27日 星期四 15时47分11秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int *arr=new int[n];
        stack<int>stor;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        stor.push(arr[0]);
        for(int i=1;i<n;i++){
            if(!stor.empty()&&arr[i]!=stor.top())
                stor.pop();
            else{
                stor.push(arr[i]);
            }
        }
        cout<<stor.top()<<endl;
        delete []arr;
    }
    return 0;
}
