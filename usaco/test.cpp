/*************************************************************************
	> File Name: test.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月25日 星期三 15时53分21秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    char data[200][200];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>data[i][j];
            if(data[i][j]=='1')
                cout<<i<<" "<<j<<endl;
        }
    return 0;
}
