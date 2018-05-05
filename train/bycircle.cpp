/*************************************************************************
	> File Name: bycircle.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月15日 星期日 14时20分59秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n;
    while(cin>>n){
    unsigned long long*dp=new unsigned long long[n+1]();
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--)
            dp[j]=dp[j]%100001+dp[j-i];
    }
    cout<<dp[n]%100001<<endl;
    delete[]dp;
    }
    return 0;
}
