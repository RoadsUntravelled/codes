/*
ID:wangxuf1
PROG:cowtour
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<climits>
#include<iomanip>
#include<cmath>
using namespace std;
struct Farm_area{
    int x,y;
};
int set_num=-1,set1=0,set2=0,split_farm[200][200];
float val[200][200];
bool vis[200];
char adjx[200][200];
int cnt[200];
int N;
float maxn=INT_MAX;
void dfs(int index){
    for(int i=1;i<=N;i++)
        if(i!=index&&adjx[index][i]=='1'&&!vis[i]){
            vis[i]=true;
            split_farm[set_num][cnt[set_num]++]=i;
            dfs(i);
        }           
}
Farm_area section[200];
float res(int i,int j){
    int front=(section[i].x-section[j].x)*(section[i].x-section[j].x);
    int sec=(section[i].y-section[j].y)*(section[i].y-section[j].y);
    return sqrt(front+sec);
}
int main(){
    //freopen("cowtour.in","r",stdin);
    //freopen("cowtour.out","w",stdout);
    cin>>N;
    float *sav_val=new float[200]();
    memset(split_farm,0,sizeof(split_farm));
    memset(vis,0,sizeof(vis));
    memset(val,0,sizeof(val));
    memset(section,0,sizeof(section));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=N;i++)
        cin>>section[i].x>>section[i].y;
    memset(adjx,0,sizeof(adjx));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            cin>>adjx[i][j];
            if(i==j)
                val[i][j]=0;
            else if(adjx[i][j]=='1')
                val[i][j]=res(i,j);
            else val[i][j]=INT_MAX;
        }
    for(int i=1;i<=N;i++)
       if(!vis[i]){
            set_num++;
            vis[i]=true;
            split_farm[set_num][cnt[set_num]++]=i;
            dfs(i);
       }
    for(int i=0;i<set_num;i++)
        for(int j=i+1;j<=set_num;j++)
            for(int k=0;split_farm[i][k];k++)
                for(int l=0;split_farm[j][l];l++){
                    int temp1=split_farm[i][k],temp2=split_farm[j][l];
                    val[temp1][temp2]=val[temp2][temp1]=res(temp1,temp2);
                }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            for(int k=1;k<=N;k++)
                if(j!=k)
                    if(val[j][i]+val[i][k]<val[j][k])
                        val[j][k]=val[j][i]+val[i][k];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cout<<val[i][j]<<" ";
        cout<<endl;
    }
    /*for(int i=0;i<=set_num;i++)
        for(int j=0;split_farm[i][j];j++)
            for(int k=0;split_farm[i][k];k++)
                for(int l=0;split_farm[i][l];l++)
                    if(k!=l){
                        int f=split_farm[i][j],s=split_farm[i][k],t=split_farm[i][l];
                        if(val[s][f]+val[f][t]<val[s][t])
                            val[s][t]=val[s][f]+val[f][t];
                    }
    for(int i=0;i<=set_num;i++)
        for(int j=0;split_farm[i][j];j++)
            for(int k=0;split_farm[i][k];k++)
                if(j!=k){
                    int lef=split_farm[i][k],rig=split_farm[i][j];
                    if(val[lef][rig]>sav_val[rig])
                        sav_val[rig]=val[lef][rig];
                    }*/
    
   return 0;
}
