/*************************************************************************
	> File Name: OilDeposits.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年05月05日 星期六 16时43分44秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];
void dfs(int r,int c,int id){
    if(r<0||r>=m||c<0||c>=n)return;
    if(idx[r][c]>0||pic[r][c]!='@')return;
    idx[r][c]=id;
    for(int dr=-1;dr<=1;dr++)
        for(int dc=-1;dc<=1;dc++)
            if(dr!=0||dc!=0)dfs(r+dr,c+dc,id);
}
int main(){
    while(~scanf("%d%d",&m,&n)&&m&&n){
        for(int i=0;i<m;i++)scanf("%s",pic[i]);
        memset(idx,0,sizeof(idx));
        int cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(idx[i][j]==0&&pic[i][j]=='@')dfs(i,j,++cnt);
        printf("%d\n",cnt);
    }
    return 0;
}
