/*************************************************************************
	> File Name: krypton.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年05月08日 星期二 19时29分08秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int cnt,S[30],n,L;
int dfs(int cur){
    if(cnt++==n){
        for(int i=0;i<cur;i++)cout<<'A'+S[i];
        cout<<endl;
        return 0;
    }
    for(int i=0;i<L;i++){
        S[cur]=i;
        int ok=1;
        for(int j=1;j*2<cur+1;j++){
            int equal=1;
            for(int k=0;k<j;k++)
                if(S[cur-k]!=S[cur-k-j]){equal=0;break;}
            if(equal){ok=0;break;}
        }
        if(ok)if(!dfs(cur+1))return 0;
    }
    return 1;
}
