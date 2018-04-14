/*************************************************************************
	> File Name: ttt.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月10日 星期二 16时10分47秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
    double values[]={1.23,35.36,653.7,4358.24};
    /*for(int i=0;i<4;i++){
        cout.width(10);
        cout.fill('*');
        cout<<values[i]<<endl;
    }*/
    copy(values,values+sizeof(values)/sizeof(double),ostream_iterator<double>(cout<<setw(10),"\r"));
    return 0;
}
