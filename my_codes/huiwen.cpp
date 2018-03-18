/*************************************************************************
	> File Name: huiwen.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月14日 星期三 14时32分21秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
string same(char *s,int begin,int end){
    if(begin+1==end||begin==end){
        if(s[begin]==s[end])
            return "yes";
        else return "no";
    }
    else{
        if(s[begin]!=s[end])
            return "no";
        else
            return same(s,begin+1,end-1);
    }
}
int main(){
    char s[1000];
    while(cin>>s){
        cout<<same(s,0,strlen(s)-1)<<endl;
    }
    return 0;
}
