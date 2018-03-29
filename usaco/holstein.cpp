/*
ID:wangxuf1 
LANG:C++ 
PROG:holstein
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef int Vitamin[30];
int V,cnt=20,feed_nums,res[20];
Vitamin req,feed[20],tot;
bool cmp(const int fir[],const int sec[]){
    for(int i=1;i<=V;i++)
        if(sec[i]>fir[i])
            return false;
    return true;
}
void dfs(int i,int now,int temp[]){
    if(cmp(tot,req)){
        if(now<cnt){
            cnt=now;
            memcpy(res+1,temp+1,19*4);
        }
        return;
    }
    for(int j=i+1;j<=feed_nums;j++){
        for(int k=1;k<=V;k++)
            tot[k]+=feed[j][k];
        temp[j]=1;
        dfs(j,now+1,temp);
        for(int k=1;k<=V;k++)
            tot[k]-=feed[j][k];
        temp[j]=0;
    }       
}
int main(){
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    while(~scanf("%d",&V)){
        memset(req,0,sizeof(req));
        memset(feed,0,sizeof(feed));
        memset(tot,0,sizeof(tot));
        for(int i=1;i<=V;i++)
            scanf("%d",&req[i]);
        scanf("%d",&feed_nums);
        for(int i=1;i<=feed_nums;i++)
            for(int j=1;j<=V;j++)
                scanf("%d",&feed[i][j]);
        int temp[20];
        memset(temp,0,sizeof(temp));
        dfs(0,0,temp);
        cout<<cnt;
        for(int i=1;i<=feed_nums;i++)
            if(res[i])
                cout<<" "<<i;
        cout<<endl;
        memset(res,0,sizeof(res));
    }
    return 0;
}
