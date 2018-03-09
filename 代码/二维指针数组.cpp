/*************************************************************************
	> File Name: 二维指针数组.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月11日 星期四 19时35分04秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int **p=NULL;
    int a[2][2]={1,2,3,4};
    //int *n=a[0];
   // int *m=a[1];
    p=new int*[2];
    //p[0]=new int[2];
    //p[1]=new int[2];
    p[0]=a[0];
    p[1]=a[1];
    //p[0]=n;
    //p[1]=m;
    /*cout<<a[0]<<" "<<n<<endl;
    cout<<*(a[1]+1)<<" "<<&n<<endl;*/
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cout<<p[i][j]<<" ";
    return 0;
}
