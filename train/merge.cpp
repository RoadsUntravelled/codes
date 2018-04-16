/*************************************************************************
	> File Name: merge.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月15日 星期日 08时26分45秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main(){
    while(cin>>n){
    int desert[220];
    int calc[220][220];
    for(int i=1;i<=n;i++){
        cin>>desert[i];
    }
    memcpy(desert+n+1,desert+1,sizeof(int)*n);
    int dp[220][220][2];//dp表示第i堆归并到第j堆的最小代价,dp[1][n]即是答案
    memset(dp,0,sizeof(dp));
    for(int i=1;i<2*n;i++){
        dp[i][i+1][0]=dp[i][i+1][1]=desert[i]+desert[i+1];
    }
    memset(calc,0,sizeof(calc));
    for(int i=2*n;i>=1;i--)
        for(int j=i;(j-i)<=n-1&&j<=2*n;j++)
                calc[i][j]=calc[i][j-1]+desert[j];
    for(int i=2*n;i>=1;i--)
        for(int j=i+1;(j-i)<=n-1&&j<=2*n;j++){
            int maxn=dp[i][j][0]=dp[i][i][0]+calc[i][j]+dp[i+1][j][0];
            int minum=dp[i][j][1]=dp[i][i][1]+calc[i][j]+dp[i+1][j][1];
            for(int k=i;k<j;k++){
            int cmp1=dp[i][k][1]+dp[k+1][j][1]+calc[i][j];
            int cmp2=dp[i][k][0]+dp[k+1][j][0]+calc[i][j];
            if(cmp1<minum){
                    dp[i][j][1]=minum=cmp1;
                }
            if(cmp2>maxn){
                dp[i][j][0]=maxn=cmp2;
            }
            }
        }
    int maxn=-1,minum=0xffffff;
    for(int i=1;i<=n;i++){
        if(dp[i][i+n-1][1]<minum)
            minum=dp[i][i+n-1][1];
        if(dp[i][i+n-1][0]>maxn)
            maxn=dp[i][i+n-1][0];
    }
    cout<<maxn<<" "<<minum<<endl;
    }
    return 0;
}
