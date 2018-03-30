/*************************************************************************
	> File Name: pinut.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月30日 星期五 16时29分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
int min(int a,int b,int c){
    int start=a>b?(a>c?a:c):(b>c?b:c);
    while(start%a||start%b||start%c){
        start++;
    }
    return start;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(a,b,c)<<endl;
    return 0;
}
