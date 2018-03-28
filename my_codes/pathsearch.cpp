/*************************************************************************
    > File Name: pathsearch.cpp
    > Author: 魍魉楼主
    > Mail: wangxufeng1997@outlook.com
    > Created Time: 2018年03月24日 星期六 22时18分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
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
    for(int i=0;i<9;i++)fact[i]=fact[i-1]*i;
}
int try_to_insert(int s){
    int code=0;//把st[s]映射到整数code
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++)if(st[s][j]<st[s][i])cnt++;
        code+=fact[8-i]*cnt;
    }
    if(vis[code])return 0;
    
    return vis[code]=1;
}
int bfs(){
    init_lookup_table();//初始化查找表
    int front=1,rear=2;//不使用下标0,因为0被看做"不存在"
    while(front<rear){
        State&s=st[front];//用"引用"简化代码
        if(memcmp(goal,s,sizeof(s))==0)return front;//找到目标状态,成功返回
        int z;
        for(z=0;z<9;z++)if(!s[z])break;//找0的位置
        int x=z/3,y=z%3;//获取行列编号(0-2)
        for(int d=0;d<4;d++){
            int newx=x+dx[d];
            int newy=y+dy[d];
            int newz=newx*3+newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3){//如果移动合法
                State&t=st[rear];
                memcpy(&t,&s,sizeof(s));//扩展新结点
                t[newz]=s[z];
                t[z]=s[newz];
            }
        }
    }
}
