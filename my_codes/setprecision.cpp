/*************************************************************************
	> File Name: setprecision.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年05月06日 星期日 09时10分13秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
double x;
cin >> x;
cout <<fixed;
cout << setprecision(2) << x << endl;
return 0;
}
