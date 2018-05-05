/*************************************************************************
	> File Name: bitset.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月27日 星期五 22时41分14秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<bitset>
using namespace std;
int main(){
    bitset<20>a{0xfffff};
    bitset<20>b{0xffff};
    bool cmp=a<b;
    cout<<cmp<<endl;
    return 0;
}
