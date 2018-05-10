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
#include<vector>
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
    cout<<temp<<endl
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
    string a("12341");
    string b("12340");
    bool n=a.compare(0,5,b,0,5);
    cout<<n<<endl;
    return 0;
}
