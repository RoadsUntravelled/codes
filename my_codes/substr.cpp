/*************************************************************************
	> File Name: substr.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月21日 星期三 13时17分24秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1("Heterological paradoxes are persistent.");
    cout<<"The original string str1 is:"<<endl;
    cout<<str1<<endl;
    basic_string<char>str2=str1.substr(6,0);
    cout<<"The substring str1 copied is:"<<str2<<endl;
    basic_string<char>str3=str1.substr();
    cout<<"The default substring str3 is:"<<endl;
    cout<<str3<<endl;
    cout<<"which is the entire original string."<<endl;
    return 0;
}
