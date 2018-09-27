/*
ID:wangxuf1
PROG:maze1
LANG:C++
*/
#include<cstdio>
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
char map[210][80];
int vmp[210][80];
const int dx[][4]={{-1,0,+1,0},{-2,0,+2,0}};
const int dy[][4]={{0,+1,0,-1},{0,+2,0,-2}};
int exi[2][2];
bool vis[210][80];
int W,H,maxn=1,cnt=0;
bool jud(int x,int y){
    return x>1&&x<2*H+1&&y>1&&y<2*W+1&&map[x][y]==' '&&!vis[x][y];
}
void walk(int x,int y,int stp){
    for(int j=0;j<4;j++){
        int newx=x+dx[1][j],newy=y+dy[1][j],wallx=x+dx[0][j],wally=y+dy[0][j];
        if(jud(newx,newy)&&jud(wallx,wally)){
            if(stp+1>=vmp[newx][newy])
                continue;
            vis[newx][newy]=true;
            vmp[newx][newy]=stp+1;
            walk(newx,newy,stp+1);
            vis[newx][newy]=false;
        }

    }
}
int main(){
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    cin>>W>>H;
    memset(vmp,0,sizeof(vmp));
    for(int i=1;i<=2*H+1;i++)
        for(int j=1;j<=2*W+1;j++)
            vmp[i][j]=INT_MAX;
    for(int i=1;i<=(2*H+1);i++){
        getchar();
        for(int j=1;j<=(2*W+1);j++){
            map[i][j]=getchar();
            if((i==1||i==2*H+1||j==1||j==2*W+1)&&map[i][j]==' '){
                exi[cnt][0]=i;
                exi[cnt++][1]=j;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            int newx=exi[i][0]+dx[0][j];
            int newy=exi[i][1]+dy[0][j];
            if(jud(newx,newy)){
                vis[newx][newy]=true;
                vmp[newx][newy]=1;
                walk(newx,newy,1);

            }
        }
        memset(vis,0,sizeof(vis));
    }
    for(int i=2;i<=2*H;i+=2)
        for(int j=2;j<=2*W;j+=2)
            if(vmp[i][j]>maxn)
                maxn=vmp[i][j];
    cout<<maxn<<endl;
    return 0;
}
