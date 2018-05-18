/*
ID:wangxuf1
PROG:nocows
LANG:C++11
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cstdio>
typedef unsigned long long ll;
using namespace std;
int main(){
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    int N,K;
    cin>>N>>K;
    ll dp[220][110];
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(int i=1;i<=N-2;i+=2)
        for(int j=log10(i)/log10(2)+1;j<=(i+1)/2;j++)
            for(int k=1;k<=i&&(i+k+1)<=N;k+=2)
                for(int h=log10(k)/log10(2)+1;h<=(k+1)/2;h++){
                    int height=j>h?j:h;
                    if(i==k)
                        dp[i+k+1][height+1]+=(dp[i][j]*dp[k][h])%9901;
                    else
                        dp[i+k+1][height+1]+=(dp[i][j]*dp[k][h]*2)%9901;
                    
                }
    //cout<<ULONG_LONG_MAX<<endl;
    /*for(int i=1;i<=N;i++)
        for(int j=log10(i)/log10(2)+1;j<=(i+1)/2;j++){
            if(dp[i][j]>=ULONG_LONG_MAX)
            cout<<"n:"<<i<<" h:"<<j<<":"<<dp[i][j]<<endl;
    //cout<<endl;
}*/
    cout<<dp[N][K]%9901<<endl;
    return 0;
}
