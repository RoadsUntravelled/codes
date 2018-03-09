/*************************************************************************
	> File Name: square_sum.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月07日 星期三 20时24分29秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int divide(int n,int m){//n1不大于m
    if(m>400)
        m=400;
    if(n==0||m==0)
        return 0;
    if(n<=1||m<=1)
        return 1;
    if(n<m)return divide(n,n);
    if(n==m&&int(sqrt(m))==sqrt(m))
    return divide(n,m-1)+1;
    for(;m>=1;m--){
        if(int(sqrt(m))==sqrt(m)){
            return divide(n,m-1)+divide(n-m,m);
            break;
        }

    }
}
int main(){
    int num;
    while(cin>>num){
        cout<<divide(num,num)<<endl;
    }
    return 0;
}
