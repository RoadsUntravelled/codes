/*************************************************************************
	> File Name: limit.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月26日 星期四 18时27分22秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<climits>
int main(){
    using namespace std;
    cout<<"max values:"<<endl;
    cout<<"int:"<<hex<<UINT_MAX<<endl;
    cout<<"long:"<<LONG_MAX<<endl;
    cout<<"short:"<<SHRT_MAX<<endl;
    cout<<"long long:"<<LLONG_MAX<<endl;
    cout<<"bits per byte="<<CHAR_BIT<<endl;
    return 0;

}
