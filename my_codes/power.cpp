/*************************************************************************
	> File Name: power.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月30日 星期五 21时22分49秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long Valley[35];
int cnt=40,N,M;
long long model;
Valley v;
void dfs(int node,long long sum,int now){
    //cout<<"node="<<node<<"now="<<now<<"sum="<<sum<<endl;
    if(node>N+1||now>=cnt)
        return ;
    if(!(sum^model)){
        if(now<cnt)
            cnt=now;
        return;
    }
    for(int i=node;i<=N;i++){
        long long temp=sum|v[i];
        dfs(i+1,temp,now+1);
        //cout<<"enter"<<endl;
    }
    dfs(node+1,sum,now);
}
int main(){
    while(cin>>N>>M&&(N||M)){
        memset(v,0,sizeof(v));
        model=pow(2,N+1)-2;
        for(int i=0;i<M;i++){
            int fir,sec;
            cin>>fir>>sec;
            v[fir]+=pow(2,sec);
            v[sec]+=pow(2,fir);
        }
        for(int i=1;i<=N;i++)
            v[i]+=pow(2,i);
        dfs(1,0,0);
        cout<<cnt<<endl;
        cnt=40;
    }
    return 0;
}
