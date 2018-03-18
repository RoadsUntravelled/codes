/*************************************************************************
	> File Name: distribute.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月14日 星期三 13时59分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
int cnt=0;
void dist(int n,int m){
    if(n==m)
    {
        cnt++;
        return;
    }
    else{
        int temp=m-n;
        if(temp<n){
        dist(temp,n);
        cnt++;
        }
        else{
            dist(n,temp);
            cnt++;
        }
    }
}
int main(){
    int n,m;
    while(cin>>n>>m){
        cnt=0;
        if(n<m){
        dist(n,m);
        }
        else{
            dist(m,n);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
