/*************************************************************************
	> File Name: matrixmultiply.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月19日 星期四 19时16分10秒
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
        bool judge=true;
        int (*p)[2]=new int[n+1][2]();
        cin>>p[1][0]>>p[1][1];
        for(int i=2;i<=n;i++){
            cin>>p[i][0]>>p[i][1];
            if(p[i][0]!=p[i-1][1])
                judge=false;
            }
        if(!judge)
            cout<<"invalid argument"<<endl;
        else{
            int **dp=new int*[n+1]();
            for(int i=0;i<=n;i++)
                dp[i]=new int[n+1]();
            for(int i=1;i<n;i++)
                dp[i][i+1]=p[i][0]*p[i][1]*p[i+1][1];
            for(int i=n-1;i>=1;i--)
                for(int j=i+1;j<=n;j++){
                    int temp=p[i][0]*p[j][1];
                    dp[i][j]=dp[i][i]+dp[i+1][j]+temp*p[i][1];
                    for(int k=i;k<j;k++)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+temp*p[k][1]);
            }
            cout<<dp[1][n]<<endl;
            for(int i=0;i<=n;i++)
                delete []dp[i];
            delete[]dp;
        }
        delete[]p;
    }
    return 0;
}
