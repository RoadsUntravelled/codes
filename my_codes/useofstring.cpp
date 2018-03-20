/*************************************************************************
	> File Name: useofstring.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月20日 星期二 21时39分40秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string line;
    while(getline(cin,line)){
        int sum=0,x;
        string temp;
        stringstream ss(line);
        while(ss>>temp){
        cout<<temp<<endl;
        }
    }
    return 0;
}
