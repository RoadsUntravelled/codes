/*
ID:wangxuf1
PROG:ttwo
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<climits>
#include<cstdio>
using namespace std;
char map[15][15];
int farm[2],cows[2];
long long cnt=1000;
bool equal(int cx,int cy,int fx,int fy){
    return (cx==cows[0]&&cy==cows[1]&&fx==farm[0]&&fy==farm[1])||(cx==farm[0]&&cy==farm[1]&&fx==cows[0]&&fy==cows[1]);
}
void new_step(int&x,int&y,char&dir){
    switch(dir){
        case 'N':
            if(x-1<1||map[x-1][y]=='*')
                dir='E';
            else
                x--;
            return;
        case 'E':
            if(y+1>10||map[x][y+1]=='*')
                dir='S';
            else
                y++;
            return;
        case 'S':
            if(x+1>10||map[x+1][y]=='*')
                dir='W';
            else
                x++;
            return;
        case 'W':
            if(y-1<1||map[x][y-1]=='*')
                dir='N';
            else
                y--;
            return;
    }
}
void walk(int,int,char,int,int,char,int);
void change(int cx,int cy,char dc,int fx,int fy,char df,int stp){
    new_step(cx,cy,dc);
    new_step(fx,fy,df);
    walk(cx,cy,dc,fx,fy,df,stp);
}
void walk(int cx,int cy,char dc,int fx,int fy,char df,int stp){
    if(stp>cnt||stp>1000)
        return;
    if(stp!=0&&dc=='N'&&df=='N'&&equal(cx,cy,fx,fy))
        return ;
    if(cx==fx&&cy==fy){
        if(stp<cnt){
            cnt=stp;
        }
        return;
    }
    change(cx,cy,dc,fx,fy,df,stp+1);
}
int main(){
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++){
            cin>>map[i][j];
            if(map[i][j]=='F')
                farm[0]=i,farm[1]=j;
            else if(map[i][j]=='C')
                cows[0]=i,cows[1]=j;
        }
    walk(cows[0],cows[1],'N',farm[0],farm[1],'N',0);
    if(cnt!=1000)
        cout<<cnt<<endl;
    else
        cout<<0<<endl;
    return 0;
}
