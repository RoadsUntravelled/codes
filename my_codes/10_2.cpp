/*************************************************************************
	> File Name: 10_2.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月09日 星期一 19时59分42秒
 ************************************************************************/

#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
double square(double x){
    return x*x;
}
int main(){
    transform(istream_iterator<double>(cin),istream_iterator<double>(),ostream_iterator<double>(cout,"\t"),square);
    cout<<endl;
    return 0;
}
