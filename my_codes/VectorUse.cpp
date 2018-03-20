/*************************************************************************
	> File Name: VectorUse.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月20日 星期二 21时52分13秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
/*template<typename type>
ostream& operator<<(ostream&out,const vector<type>v){
    for(int i=0;i<v.size();i++)
        out<<v[0]<<" ";
    return out;
}
int main(){
    int n;
    while(cin>>n){
        vector<int>a(n,8);
        vector<int>b(a.rend()-1,a.rbegin());
        cout<<a.size()<<endl;
        cout<<b<<endl;
    }
    return 0;
}*/
int main()
{
   // 创建一个向量存储 int
   vector<int> vec; 
   int i;
 
   // 显示 vec 的原始大小
   cout << "vector size = " << vec.size() << endl;
 
   // 推入 5 个值到向量中
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }
 
   // 显示 vec 扩展后的大小
   cout << "extended vector size = " << vec.size() << endl;
 
   // 访问向量中的 5 个值
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
 
   // 使用迭代器 iterator 访问值
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }
 
   return 0;
}
