/*************************************************************************
	> File Name: ostringstream.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月10日 星期二 17时55分50秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
int main(){
    ostringstream os;
    os<<123456;
    string obj=os.str();
    cout<<obj[2]<<endl;
    return 0;
}
