/*************************************************************************
	> File Name: 3整除.cpp
	> Author:
	> Mail:
	> Created Time: 2017年11月26日 星期日 13时47分14秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
int main(){
    char c;
    int a=0;
    int b=0;
    while((c=getchar())!='\n'){
        a=(c-'0'+b)%3;
        b=a*10;
    }
    if(a==0){
        cout<<1<<endl;
    }
    else cout<<0<<endl;
    return 0;
}
