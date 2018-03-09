/*************************************************************************
	> File Name: guess.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月31日 星期日 20时50分05秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int a[1000];
int N;
int cur=0;
int cnt=0;
void fib(int n,int sum){
    if(sum==N){
        cnt++;
        return ;}
    for(int i=n;i<=20&&a[i]+sum<=N;i++){
     fib(i,a[i]+sum);} 
}
int main(){
    for(int i=1;i<=20;i++)
        a[i]=i*i;
    while(cin>>N){
    cnt=0;
    cur=0;
    /*for(int i=1;i<=20;i++)
        if(a[i]>=sqrt(N)){
            cur=i;
            break;}*/
    fib(1,0);
    cout<<cnt<<endl;} 
    return 0;
}
