/*************************************************************************
	> File Name: eight_digit.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年05月08日 星期二 21时55分23秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<cstring>
#include<algorithm>
using namespace std;
typedef int State[9];
const int maxstate=1000000;
State st[maxstate],goal;
int dist[maxstate];
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int vis[362880],fact[9];
void init_lookup_table(){
    fact[0]=1;
    for(int i=1;i<9;i++)fact[i]=fact[i-1]*i;
}
int insert(int s){
    for(int i=0;i<9;i++)
        cout<<st[s][i]<<" ";
    cout<<endl;
    int code=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++)if(st[s][j]<st[s][i])cnt++;
        code+=fact[8-i]*cnt;
    }
    cout<<"code:"<<code<<endl;
    if(vis[code])return 0;
    return vis[code]=1;
}
int bfs(){
    init_lookup_table();
    int front=1,rear=2;
    while(front<rear){
        State&s=st[front];
        if(memcmp(goal,s,sizeof(s))==0)return front;
        int z;
        for(z=0;z<9;z++)if(!s[z])break;
        int x=z/3,y=z%3;
        for(int d=0;d<4;d++){
            int newx=x+dx[d];
            int newy=y+dy[d];
            int newz=newx*3+newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3){
                State&t=st[rear];
                memcpy(&t,&s,sizeof(s));
                t[newz]=s[z];
                t[z]=s[newz];
                dist[rear]=dist[front]+1;
                if(insert(rear))rear++;
            }
        }

        front++;
    }
    return 0;
}
int main(){
    for(int i=0;i<9;i++)cin>>st[1][i];
    for(int i=0;i<9;i++)cin>>goal[i];
    int ans=bfs();
    for(auto I:fact)
        cout<<I<<" ";
    cout<<endl;
    if(ans>0)cout<<dist[ans]<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
