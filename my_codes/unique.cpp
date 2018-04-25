/*************************************************************************
	> File Name: unique.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月25日 星期三 14时55分24秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    int a[]={1,1,1,1,1,2,2,2};
    cout<<unique(a,a+8)-a<<endl;
    return 0;
}
