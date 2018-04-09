/*************************************************************************
	> File Name: void_pointer.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月03日 星期二 18时21分05秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    void *pv;
    int i=8;
    pv=&i;
    cout<<*(static_cast<int*>(pv))<<endl;
    return 0;
}
