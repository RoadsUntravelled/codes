/*
ID:wangxuf1
PROG:concom
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct Company{
    int *next=new int[110]();
    int *stock=new int[110]();
    int cnt=0;
}comp[110];
void work(int beg,int pre){
    for(int i=0;i<comp[pre].cnt;i++){
        int node=comp[pre].next[i];
        int temp=comp[beg].stock[node];
        if(temp>50)
            continue;
        comp[beg].stock[node]+=comp[pre].stock[node];
        if(comp[beg].stock[node]>50)
            work(beg,node);
    }
}
int main(){
   freopen("concom.in","r",stdin);
  freopen("concom.out","w",stdout);
    int n;
    cin>>n;
    int index1,index2,p;
    int index[110];
    memset(index,0,sizeof(index));
    int tot=0;
    bool vis[110];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        cin>>index1>>index2>>p;
        comp[index1].next[comp[index1].cnt++]=index2;
        comp[index1].stock[index2]=p;
        if(!vis[index1]){
            index[tot++]=index1;
            vis[index1]=true;
        }
        if(!vis[index2]){
            vis[index2]=true;
            index[tot++]=index2;
        }       
    }
    sort(index,index+tot);
    for(int i=0;i<tot;i++){
            int temp=index[i];
            for(int j=0;j<comp[temp].cnt;j++){
                int node=comp[temp].next[j];
                if(comp[temp].stock[node]>50)
                    work(temp,node);
            }
    }
    for(int i=0;i<tot;i++){
        int temp=index[i];
        for(int j=0;j<tot;j++){
            int ind2=index[j];
            if(ind2!=temp&&comp[temp].stock[ind2]>50)
                cout<<temp<<" "<<ind2<<endl;
        }   
    }
    return 0;
}
