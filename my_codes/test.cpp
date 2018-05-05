/*************************************************************************
	> File Name: test.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月20日 星期三 23时04分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
#include<typeinfo>
#include<bitset>
using namespace std;
/*bool operator<(const bitset<8>&a,const bitset<8>&b){
    return a.to_string()<b.to_string();
}*/
class cmp{
    public:
    bool operator ()(const bitset<8>ori,const bitset<8>&obj)const{
        return ori.to_string()<obj.to_string();
    }
};
int main(){
    /*int arr[]{1,2,3};
    //string s("asdfg");
    set<int> se{5,2,3,4,5};
    for(auto i:arr)
        cout<<i<<endl;
    cout<<sizeof arr[0]<<endl;
    auto c{0.0};
    cout<<typeid(arr).name()<<endl;
    cout<<sizeof arr<<endl;
    bitset<100> s(0xffffffffffffff);
    bitset<100> a(0xffffffffffffff);
    string s1=s.to_string();
    string s2=a.to_string();
    bool check=s1>s2;
    cout<<check<<endl;
    string temp;
    getline(cin,temp);
    cout<<temp<<endl;
    int *p=new int(5);
    int *ano=p;
    cout<<*p<<endl;
    delete p;
    cout<<*p<<endl;
    set<bitset<8>,cmp> test{5,4,2,8,1};
    for(auto i:test)
        cout<<i<<" ";
    cout<<endl;
    bitset<100> tt(0);
    cout<<~tt<<endl;
    cout<<tt.count()<<endl;*/
    char link[25] = {112, 97, 110, 46, 98, 97, 105, 100, 117, 46, 99, 111, 109, 47, 115, 47, 49, 111, 57, 52, 107, 83, 106, 103, 10}; 

    char code[5] = {118, 98, 108, 120, 10}; 


    cout << link << endl; cout << code << endl; 

    return 0;
}
