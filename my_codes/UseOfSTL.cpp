/*************************************************************************
	> File Name: UseOfSTL.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月20日 星期二 22时36分26秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#define All(x) x.begin(),x.end()//所有的内容
#define INS(x) inserter(x,x.begin())//插入迭代器
using namespace std;
typedef set<int> Set;
map<Set,int>IDcache;//把集合映射成ID
vector<Set>Setcache;//根据ID取集合
//查找给定集合x的ID.如果找不到,分配一个新ID
int ID(Set x){
    if(IDcache.count(x))return IDcache[x];
    Setcache.push_back(x);//添加新集合
    return IDcache[x]=Setcache.size()-1;
}
int main(){
    stack<int>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string op;
        cin>>op;
        if(op[0]=='P')s.push(ID(Set()));
        else if(op[0]=='D')s.push(s.top());
        else{
            Set x1=Setcache[s.top()];s.pop();
            Set x2=Setcache[s.top()];s.pop();
            Set x;
            if(op[0]=='U')set_union(All(x1),All(x2),INS(x));
            if(op[0]=='I')set_intersection(All(x1),All(x2),INS(x));
            if(op[0]=='A'){x=x2;x.insert(ID(x1));}
            s.push(ID(x));
        }
        cout<<Setcache[s.top()].size()<<endl;
    }
    return 0;
}
