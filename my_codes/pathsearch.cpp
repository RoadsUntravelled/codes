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
const int hashsize=1000003;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int head[hashsize],next[maxstate];
void init_lookup_table(){memset(head,0,sizeof(head));}
int hash(State &s){
    int v=0;
    for(int i=0;i<9;i++)v=v*10+s[i];//把9个数字组合成9位数
    return v%hashsize;
}
int try_to_insert(int s){
    int h=hash(st[s]);
    int u=head[h];
    while(u){
        if(memcmp(st[u],st[s],sizeof(st[s]))==0)return 0;
           u=next[u];
    }
    next[s]=head[h];
    head[h]=s;
    return 1;
}
