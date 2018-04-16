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
int tot=100000000;
bool vis[110]={0};
int n;
int main(){
    cin>>n;
    int desert[110];
    int calc[110][110];
    for(int i=1;i<=n;i++){
        cin>>desert[i];
    }
    int dp[110][110];//dp表示第i堆归并到第j堆的最小代价,dp[1][n]即是答案
    //dp[n][n]=desert[n];
    for(int i=1;i<n;i++){
       // dp[i][i]=desert[i];
        dp[i][i+1]=desert[i]+desert[i+1];
    }
   // memset(dp,0,sizeof(dp));
    memset(calc,0,sizeof(calc));
    for(int i=n;i>=1;i--)
        for(int j=i;j<=n;j++)
                calc[i][j]=calc[i][j-1]+desert[j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<calc[i][j]<<" ";
        cout<<endl;
    }
    for(int i=n;i>=1;i--)
        for(int j=i+1;j<=n;j++){
            int temp=dp[i][j]=dp[i][i]+calc[i][j];
            for(int k=i;k<j;k++)
            if(dp[i][k]+calc[i][j]<temp){
                    temp=dp[i][k]+calc[i][j];
                    dp[i][j]=temp;
                }
            cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<endl;
        }
    cout<<dp[1][n]<<endl;
    return 0;
}
