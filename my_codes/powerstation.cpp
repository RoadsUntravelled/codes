/*************************************************************************
	> File Name: powerstation.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月31日 星期六 17时52分50秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int N,M;
int diff(int adj[40][40],int lowcost[40],int i){
    int cnt=0;
    for(int j=1;j<=N;j++)
        if(adj[i][j]==1&&lowcost[j]==0)
            cnt++;
    return cnt;
}
int main(){
    while(cin>>N>>M&&(M||N)){
        int adjtab[40][40];
        memset(adjtab,0,sizeof(adjtab));
        for(int i=1;i<=N;i++)
            adjtab[i][i]=1;
        for(int i=0;i<M;i++){
            int fir,sec;
            cin>>fir>>sec;
            adjtab[fir][sec]=1;
            adjtab[sec][fir]=1;
        }
        /*for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)
                cout<<adjtab[i][j]<<" ";
            cout<<endl;
        }*/
        int res=9999;
        for(int l=1;l<=N;l++){
        //cout<<"l="<<l<<endl;
        int lowcost[40];
        int vis[40];
        memset(lowcost,0,sizeof(lowcost));
        memset(vis,0,sizeof(vis));
        int tot=0;
        int step=0;
        lowcost[l]=1;
        vis[l]=1;
        tot++;
        for(int j=1;j<=N;j++){
                if(lowcost[j]==0&&adjtab[l][j]==1){
                    lowcost[j]=1;
                    tot++;
                }
            }
        step++;
        for(int i=1;i<=N;i++){
            int MAX=0;
            int k=-1;
            for(int j=1;j<=N;j++){
                int temp=diff(adjtab,lowcost,j);
                if(!vis[j]&&temp>MAX){
                    k=j;
                    MAX=temp;
                }
            }
           // cout<<"k="<<k<<endl;
            if(k!=-1){
            for(int j=1;j<=N;j++){
                if(lowcost[j]==0&&adjtab[k][j]==1){
                    lowcost[j]=1;
                    tot++;
                }
            }
            vis[k]=1;
            step++;
            }
            if(tot==N)
                break;   
        }
        if(step<res)
            res=step;
        }
        cout<<res<<endl;
    }
    return 0;
}
