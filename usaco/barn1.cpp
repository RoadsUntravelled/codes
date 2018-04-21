/*
ID:wangxuf1
PROG:barn1
LANG:C++
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int M,S,C;
    cin>>M>>S>>C;
    if(M>=C)
    M=C;
    int*barn=new int[C+1];
    barn[0]=0;
    int*lc=new int[C+1];
    for(int i=1;i<=C;i++){
        cin>>barn[i];
    }
    sort(barn+1,barn+1+C);
    for(int i=2;i<=C;i++)
        lc[i-1]=barn[i]-barn[i-1]-1;
    sort(lc+1,lc+C,greater<int>());
    //copy(lc+1,lc+C,ostream_iterator<int>(cout," "));
    //cout<<endl;
    int res=S-(S-barn[C])-(barn[1]-1);
    //cout<<res<<endl;
    for(int i=1;i<=M-1;i++)
        res-=lc[i];
    cout<<res<<endl;
    return 0;
}
