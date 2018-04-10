/*************************************************************************
	> File Name: oddevensort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月09日 星期一 21时43分49秒
 ************************************************************************/

#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main(){
    istream_iterator<int>i1(cin),i2;//建立一对输入流迭代器
    vector<int>s1(i1,i2);//通过输入流迭代器从标准输入流中输入数据
    sort(s1.begin(),s1.end());//将输入的整数排序
    deque<int>s2;
    for(vector<int>::iterator iter=s1.begin();iter!=s1.end();++iter){
        if(*iter%2==0)
            s2.push_back(*iter);
        else
            s2.push_front(*iter);
    }
    int a[5]={2,5,6,8,9};
    copy(s2.begin(),s2.end(),ostream_iterator<int>(cout,","));
    cout<<endl;
    return 0;
}
