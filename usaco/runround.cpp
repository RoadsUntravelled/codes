/*
ID:wangxuf1
PROG:runround
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<sstream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    freopen("runround.out","w",stdout);
    freopen("runround.in","r",stdin);
    unsigned long long m;
    cin>>m;
    m++;
    while(m){
    stringstream ss;
    ss<<m;
    string conv=ss.str();
    string comp(conv);
    int len=comp.length();
    int cur=comp.find('0');
    if(cur!=-1){
        m+=pow(10,len-1-cur);
        continue;
    }
    sort(comp.begin(),comp.end());
    int after=unique(comp.begin(),comp.end())-comp.begin();
    if(len!=after){
        m++;
        continue;
    }
    else{
        bool*vis=new bool[len]();
        int start=0;
        do{
            start=((conv[start]-'0'+start)%len);
            if(vis[start])
                break;
            vis[start]=true;
        }while(start);
        int i=0;
        for(;i<len;i++)
            if(!vis[i])
                break;
        if(i==len){
            cout<<m<<endl;
            break;
        }
    }
        m++;
    }
    return 0;
}
