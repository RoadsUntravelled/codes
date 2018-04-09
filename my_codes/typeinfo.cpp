/*************************************************************************
	> File Name: typeinfo.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月08日 星期日 20时10分57秒
 ************************************************************************/

#include<iostream>
#include<typeinfo>
using namespace std;
class Base{
    public:
        virtual ~Base(){}
};
class Derived:public Base{};
void fun(Base*b){
    const type_info&info1=typeid(int);
    const type_info&info2=typeid(*b);
    cout<<"typeid(b):"<<info1.name()<<endl;
    cout<<"typeid(*b):"<<info2.name()<<endl;
    if(info2==typeid(Base))
        cout<<"A base class!"<<endl;
}
int main(){
    Base b;
    fun(&b);
    Derived d;
    fun(&d);
    return 0;
}
