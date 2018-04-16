/*************************************************************************
	> File Name: copy.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月15日 星期日 15时35分11秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    int matrix[][2]={0,1,2,3};//matirx+i是指向指针的指针
    cout<<matrix<<endl;
    for(int i=0;i<2;i++){
    copy(*(matrix+i),*(matrix+i)+2,ostream_iterator<int>(cout," "));//matrix[i]存放的是地址，指向matirx[i]数组，而*(matrix+i)是取存放的地址的值,matrix+i取指向matirx[i]的指针，值是指针
    cout<<endl;
    }
    return 0;
}
