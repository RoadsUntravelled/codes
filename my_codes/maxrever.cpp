/*************************************************************************
	> File Name: maxrever.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月17日 星期二 22时29分38秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    string data;
    while(cin>>data){
        int n=data.length();
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
            dp[i]=new int[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=0;
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=n-2;i>=0;i--)
            for(int j=i+1;j<n;j++)
                if(data[i]==data[j])
                    dp[i][j]+=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        cout<<dp[0][n-1]<<endl;
        for(int i=0;i<n;i++)
            delete []dp[i];
        delete []dp;
    }
    return 0;
}
