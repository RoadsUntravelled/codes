/*************************************************************************
	> File Name: STL.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月08日 星期日 22时57分19秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
    const int N=5;
    vector<int>s(N);
    for(int i=0;i<N;i++)
        cin>>s[i];
    transform(s.begin(),s.end(),ostream_iterator<int>(cout,","),negate<int>());
    cout<<endl;
    return 0;
}
