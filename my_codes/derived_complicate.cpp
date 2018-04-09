/*************************************************************************
	> File Name: derived_complicate.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月07日 星期六 20时43分23秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Base1{
    public:
        void display()const{cout<<"Base0::display()"<<endl;}
};
class Base2:public Base1{
    public:
        void display()const{cout<<"Base1::display()"<<endl;}
};
class Derived:public Base2{
    public:
        void display()const{cout<<"Base2::display()"<<endl;}
};
void func(Base1*ptr){
    ptr->display();
}
int main(){
    Base1 base1;
    Base2 base2;
    Derived der;
    func(&base1);
    func(&base2);
    func(&der);
    return 0;
}
