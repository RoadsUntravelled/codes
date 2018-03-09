/*************************************************************************
	> File Name: eat.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月31日 星期日 18时16分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int N;char c;
    while(cin>>N>>c){
        if(N%3!=0)
        cout<<c<<" "<<"win!"<<endl;
        else 
        {
            if(c=='A')
            cout<<"B win!"<<endl;
            else cout<<"A win!"<<endl;
        }
   }
    return 0;
}

