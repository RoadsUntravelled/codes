/*
ID:wangxuf1
LANG:C++
PROG:sort3
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXNUM=1010;
typedef int State[MAXNUM];
int cnt=0;
void swap(int list[],int i,int j){
    int temp=list[i];
    list[i]=list[j];
    list[j]=temp;
    ++cnt;
}
int main(){
   freopen("sort3.in","rd",stdin);
   freopen("sort3.out","wd",stdout);
    int n;
    while(cin>>n){
        State init;
        State last;
        State vis;
        for(int i=1;i<=n;i++){
            scanf("%d",&init[i]);
        }
        memcpy(last,init,sizeof(init));
        sort(last+1,last+n+1);
        for(int i=1;i<=n;i++){
            if(init[i]==last[i])continue;
            for(int j=i+1;j<=n;j++){
                if(init[i]==last[j]&&init[j]==last[i]){
                    swap(init,i,j);
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(last[i]==1&&init[i]!=1)
                cnt+=2;//这种情况下有三个数要三三交换,一共交换2次
        }
        //cout<<init+1;
        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}
