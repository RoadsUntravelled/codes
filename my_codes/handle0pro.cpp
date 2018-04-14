/*************************************************************************
	> File Name: handle0pro.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月11日 星期三 18时57分49秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<numeric>
using namespace std;
int divide(int x,int y){
    if(y==0)
        throw x;
    return x/y;
}
int main(){
    try{
        cout<<"5/2="<<divides<int>(5,2)<<endl;
        cout<<"8/0="<<divides<int>(8,0)<<endl;
        cout<<"7/1="<<divides<int>(7,1)<<endl;
    }catch(int e){
        cout<<e<<" is divied by zero!"<<endl;
    }
    cout<<"that is ok"<<endl;
    return 0;
}
