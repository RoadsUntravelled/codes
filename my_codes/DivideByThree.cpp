/*************************************************************************
	> File Name: DivideByThree.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月18日 星期三 19时01分22秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    int l,r;
    while(cin>>l>>r){
    int cnt=0;
    for(int i=l;i<=r;i++)
        if(i%3!=1)
            cnt++;
    cout<<cnt<<endl;
    }
    return 0;
}
