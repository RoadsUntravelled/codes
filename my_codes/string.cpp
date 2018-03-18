/*************************************************************************
	> File Name: string.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月14日 星期三 15时41分17秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    string s2(s.rbegin(),s.rend());
    cout<<s2<<endl;
    return 0;
}
