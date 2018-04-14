/*************************************************************************
	> File Name: bind2nd.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月10日 星期二 15时30分36秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int intArr[]={30,90,10,40,70,50,20,80};
    const int N=sizeof(intArr)/sizeof(int);
    vector<int>a(intArr,intArr+N);
    vector<int>::iterator p=find_if(a.begin(),a.end(),bind2nd(greater<int>(),40));
    if(p==a.end())
        cout<<"error"<<endl;
    else
        cout<<"first element greater than 40 is: "<<*p<<endl;
    return 0;
}
