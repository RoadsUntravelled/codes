/*
ID:wangxuf1
LANG:C++
PROG:hamming
*/
#include<iostream>
#include<cstdio>
using namespace std;
typedef int Hammi[10];
int N,B,D,cnt=1,list[70];
void conver(int word,int bit,int obj[]){
    while(bit){
        obj[bit]=word%2;
        word/=2;
        bit--;
    }
}
bool cmp(const int fir[],const int sec[]){
    int cnt_one=0,cnt_tot=0;
    for(int i=1;i<=B;i++){
        if(sec[i]==1)
            cnt_one++;
        if(sec[i]!=fir[i])
            cnt_tot++;
    }
    if(cnt_one>=D&&cnt_tot>=D)
        return true;
    return false;
}
void dfs(int n){
    if(cnt==N){
        return ;
    }
    bool ishami=true;
    int *sec=new Hammi;
    conver(n,B,sec);
    for(int i=1;i<=cnt;i++){
        int *fir=new Hammi;
        conver(list[i],B,fir);
        if(!cmp(fir,sec)){
            ishami=false;
            break;
        }
        delete []fir;
    }
    delete []sec;
    if(ishami){
        list[++cnt]=n;
    }
    dfs(n+1);
}
int main(){
    //freopen("hamming.in","r",stdin);
    //freopen("hamming.out","w",stdout);
    while(cin>>N>>B>>D){
    Hammi begin;
    conver(0,B,begin);
    list[1]=0;
    dfs(1);
    for(int i=1;i<=N;i++){
        if(i%10==0||i==N)
            cout<<list[i]<<endl;
        else cout<<list[i]<<" ";
    }
    cnt=1;
    }
    return 0;
}
