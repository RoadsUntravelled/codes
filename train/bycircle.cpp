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
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=new int[n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            //if(i<=0||j<=0||((j+0)*(j+1))/2<i)
             //   continue;
             if(i==j)
                dp[i][j]=1+dp[i][j-1];
            else if(j>i)
                dp[i][j]=dp[i][i];
            else
                dp[i][j]=dp[i][j-1]+dp[i-j][j-1];
    /*for(int i=1;i<=n;i++){
        copy(*(dp+i)+1,*(dp+i)+n+1,ostream_iterator<int>(cout," "));
        cout<<endl;
            }*/
    cout<<dp[n][n]%100001<<endl;
    for(int i=0;i<=n;i++)
        delete []dp[i];
    delete []dp;
    }
    return 0;
}
