/*************************************************************************
	> File Name: largeloop.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月18日 星期三 10时07分20秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    int *dp=new int[100010];
    for(int i=1;i<=10000;i++)
        lower_bound(dp,dp+10000,-1);
    return 0;
}
