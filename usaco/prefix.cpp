/*
ID:wangxuf1
PROG:prefix
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int cnt=0;
string S;
vector<string> prim;
int main(){
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    string temp;
    while(cin>>temp&&temp!=".")
        prim.push_back(temp);
    getchar();
    while(getline(cin,temp)&&temp!=""){
        S+=temp;
    }
    int *dp=new int[S.size()+1]();
    for(int i=1;i<=S.size();i++){
        bool change=false;
        for(int j=0;j<prim.size();j++){
            int sz=prim[j].size();
            if(i-sz>0&&!prim[j].compare(0,sz,S,dp[i-sz],sz)&&dp[i-sz]+sz>dp[i]){
                dp[i]=dp[i-sz]+sz;
                change=true;
            }
        }
        if(!change)
            dp[i]=dp[i-1];
    }
    /*for(int i=1;i<=S.size();i++)
    cout<<dp[i]<<" ";*/
    cout<<dp[S.size()]<<endl;
    return 0;
}
