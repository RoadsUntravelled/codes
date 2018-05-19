/*
ID:wangxuf1
PROG:money
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int V,N;
    long long dp[10010];
    memset(dp,0,sizeof(dp));
    int coins[30];
    memset(coins,0,sizeof(coins));
    cin>>V>>N;
    for(int i=1;i<=V;i++)
        cin>>coins[i];
    sort(coins+1,coins+V+1);
    dp[0]=1;
    for(int i=1;i<=V;i++)
        for(int j=coins[i];j<=N;j++)
                dp[j]+=dp[j-coins[i]];
    cout<<dp[N]<<endl;
    return 0;
}
