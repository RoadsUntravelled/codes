/*
ID:wangxuf1
LANG:C++
PROG:frac1
*/
#include<iostream>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
int PubNum(int a,int b){
    while(b){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
struct divi{
    int up,down;
    bool operator<(const struct divi&obj)const{
        return double(up)/double(down)<double(obj.up)/double(obj.down);
    }
};
int main(){
    freopen("frac1.in","rd",stdin);
    freopen("frac1.out","wd",stdout);
    int N;
    while(cin>>N){
        map<divi,double>Q;
        for(int i=2;i<=N;i++)
            for(int j=1;j<i;j++)
            {
             double temp=double(j)/double(i);
             int pub=PubNum(i,j);
             divi now={j/pub,i/pub};
                if(Q.count(now)==0){
                    Q.insert(make_pair(now,temp));
                }
            }

        cout<<0<<"/"<<1<<endl;
        for(map<divi,double>::iterator it=Q.begin();it!=Q.end();it++)
            cout<<it->first.up<<"/"<<it->first.down<<endl;
        cout<<1<<"/"<<1<<endl;
    }

    return 0;
}
