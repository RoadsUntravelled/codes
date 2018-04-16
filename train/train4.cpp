/*************************************************************************
	> File Name: train4.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月15日 星期日 15时08分51秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    int que[100010];
    for(int i=1;i<=n;i++)
        cin>>que[i];
    int dp[100010];
    for(int i=1;i<=n;i++)
        dp[i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(que[i]>que[j]&&dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
    int temp=dp[1];
    for(int i=1;i<=n;i++)
        if(dp[i]>temp)
            temp=dp[i];
    cout<<temp<<endl;
    return 0;
}
