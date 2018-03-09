/*************************************************************************
	> File Name: namespace.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月22日 星期五 11时14分41秒
 ************************************************************************/
#include<iostream>
using namespace std;
//int i;//在全局命名空间中的全局变量
namespace tool{
    int j=1;//在tool命名空间中的全局变量
}
int main(){
   int i=5;//为全局变量i赋值
    tool::j=6;//为全局变量j赋值
    {//子块1
        using namespace tool;//使得在当前块中可以直接引用tool命名空间的标识符
        //int i;//局部变量，局部作用域
        //i=7;
        cout<<"i="<<i<<endl;
        cout<<"j="<<j<<endl;
    }
    cout<<"j="<<j<<endl;
    return 0;
}
