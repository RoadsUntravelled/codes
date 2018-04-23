/*
ID:wangxuf1
PROG:subset
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int sum;
int n;
int main(){
    //freopen("subset.in","r",stdin);
    //freopen("subset.out","w",stdout);
    while(cin>>n){
    sum=(n+1)*n/2;
    if(sum%2!=0)
        cout<<0<<endl;
    else{
        sum/=2;
        long long *dp=new long long[sum+1]();
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=sum;j>=i;j--){
                dp[j]+=dp[j-i];/*dp[i]表示最大加数为i拼成和为j的个数,
                如dp[14-7]表示前7个数能拼成和为j的方法数,这里可以略去第一维i的原因是for循环中已经有i了
                dp[j]取的是上一个状态的前j个状态,即前dp[j]个状态,
                而只会改变第dp[j]的状态,所以这里不需要再开二维数组
                */
            }
        }
        cout<<dp[sum]/2<<endl;
        delete[]dp;
    }
    }
    return 0;
}
