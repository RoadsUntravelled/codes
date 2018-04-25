/*************************************************************************
	> File Name: perm.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月07日 星期三 19时15分05秒
 ************************************************************************/

#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin>>n){
    int*array=new int[n]();
    for(int i=1;i<=n;i++)
        array[i-1]=i;
    do{
        copy(array,array+n,ostream_iterator<int>(cout));
        cout<<endl;
    }while(next_permutation(array,array+n));//前缀为a[0..0]后缀为a[0..3],排列a[0...m]
    }
    return 0;
}
