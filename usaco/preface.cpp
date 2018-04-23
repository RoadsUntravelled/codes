/*
 ID:wangxuf1
 PROG:preface
 LANG:C++
 */
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    int N,*res=new int[8];
    cin>>N;
    int (*distr)[8]=new int[N+1][8]();
    for(int i=1;i<=N;i++){
        int n=0,der;
        int cur1=0,cur2=0;
        while(true){
            int comp=pow(10,n);
            if(i<4*comp){
                der=i-comp;
                cur1=2*n+1;
                break;
            }else if(i<5*comp){
                der=i-4*comp;
                cur1=2*n+1;
                cur2=2*n+2;
                break;
            }else if(i<9*comp){
                der=i-5*comp;
                cur1=2*n+2;
                break;
            }else if(i<10*comp){
                der=i-9*comp;
                cur1=2*n+1;
                cur2=2*n+3;
                break;
            }
            n++;
        }
        distr[i][cur1]++;
        distr[i][cur2]++;
        for(int j=1;j<=7;j++){
            distr[i][j]+=distr[der][j];
            res[j]+=distr[i][j];
        }
    }
    const char a[]={'0','I','V','X','L','C','D','M'};
    for(int i=1;i<=7;i++)
        if(res[i]!=0)
            cout<<a[i]<<" "<<res[i]<<endl;
    return 0;
}
