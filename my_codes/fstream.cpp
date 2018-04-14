/*************************************************************************
	> File Name: fstream.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月10日 星期二 17时03分24秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<fstream>
using namespace std;
struct Date{
    int monday,dat,year;
};
int main(){
    Date dt{6,10,92};
    ofstream os("test.dat",ios_base::out|ios_base::binary);
    os.write(reinterpret_cast<char*>(&dt),sizeof(dt));
    return 0;
}
