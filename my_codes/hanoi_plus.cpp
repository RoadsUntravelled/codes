/*************************************************************************
	> File Name: hanoi_plus.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月07日 星期三 22时51分50秒
 ************************************************************************/

#include<iostream>
#include<memory.h>
using namespace std;
int main(){
    int n;
    int move[75];
    int base=1;
    int cnt=1;
    int deep=0;
    for(int i=1;i<=64;i++){
        move[i]=base;
        deep++;
        if(deep==cnt){
            cnt++;
            deep=0;
            base*=2;
        }
    }
    //for(int i=1;i<=64;i++)
    //    cout<<move[i]<<endl;
    while(cin>>n){
        int tot=0;
        for(int i=1;i<=n;i++){
            tot+=move[i];
        }
        cout<<tot<<endl;
    }

    return 0;
}
