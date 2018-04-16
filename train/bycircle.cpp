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
    cin>>n;
    int dp[110][110];//i表示骑i圈，j表示i圈中骑行最大的圈数,dp表示骑n圈,最大圈数为n时的方式数
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i<=0||j<=0||(j+0)*(j+1)/2<i)
                break;
            else if(i==j)
                dp[i][j]=1+dp[i][j-1];
            else if(j>i)
                dp[i][j]=dp[i][i];
            else
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
    for(int i=1;i<=n;i++){
        copy(*(dp+i),*(dp+i)+n+1,ostream_iterator<int>(cout," "));
        cout<<endl;
            }
    cout<<dp[n][n]<<endl;
    return 0;
}
