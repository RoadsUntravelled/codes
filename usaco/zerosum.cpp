/*
ID:wangxuf1
PROG:zerosum
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
int N;
void dfs(int part1,char now,int part2,queue<char>op,int n){
    if(n==N+1){
        int sum=0;
       switch(now){
            case '+':sum=part1+part2;break;
            case '-':sum=part1-part2;break;
        }
        if(!sum){
            cout<<1;
            for(int i=2;i<=N;i++){
                cout<<op.front()<<i;
                op.pop();
            }
            cout<<endl;
        }
        return;
    }
    int cp=part1;
    switch(now){
            case '+':part1+=part2;break;
            case '-':part1-=part2;break;
        }
    queue<char> op1(op);
    queue<char>op2(op);
    queue<char> op3(op);
    op1.push('+');
    op2.push('-');
    op3.push(' ');
    dfs(cp,now,part2*10+n,op3,n+1);
    dfs(part1,'+',n,op1,n+1);
    dfs(part1,'-',n,op2,n+1);
}
int main(){
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    cin>>N;
    queue<char> op;
    dfs(0,'+',1,op,2);
    return 0;
}
