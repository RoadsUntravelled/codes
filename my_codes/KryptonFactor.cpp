/*************************************************************************
	> File Name: KryptonFactor.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月23日 星期五 22时44分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int n,L;
int cnt;
int S[85];
int dfs(int cur){
    if(cnt++==n){
        for(int i=0;i<cur;i++)printf("%c",'A'+S[i]);
        cout<<endl;
        return 0;
    }
    for(int i=0;i<L;i++){
        S[cur]=i;
        int ok=1;
        for(int j=1;j*2<=cur+1;j++){
            int equal=1;
            for(int k=0;k<j;k++)
                if(S[cur-k]!=S[cur-k-j]){equal=0;break;}
            if(equal){ok=0;break;}
        }
        if(ok)if(!dfs(cur+1))return 0;
    }
}
int main(){
    while(cin>>n>>L){
        if(!dfs(0))
        continue;
    }
    return 0;
}
