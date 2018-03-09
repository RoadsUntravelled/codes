/*************************************************************************
	> File Name: square_diynamic.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月09日 星期五 20时07分46秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int cnt[500][500];
bool jud(int cop){
    if(int(sqrt(cop))==sqrt(cop))
        return true;
    return false;
}
int main(){
    int n;
    while(cin>>n){
        memset(cnt,0,sizeof(int)*500*500);
        for(int j=1;j<500;j++)
            cnt[1][j]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(j>i)
                    cnt[i][j]=cnt[i][i];
                else if(i==j){//如果n与最大加数一样
                    if(jud(j)&&j<=400)
                    cnt[i][j]=1+cnt[i][j-1];//等于n=n,和n=n-1+...
                    else
                    cnt[i][j]=cnt[i][j-1];
                }
                else{
                    if(jud(j)&&j<=400)
                    cnt[i][j]=cnt[i][j-1]+cnt[i-j][j];
                    else
                    cnt[i][j]=cnt[i][j-1];
                }

            }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout<<cnt[i][j]<<" ";
            cout<<endl;
        }*/
            
        cout<<cnt[n][n]<<endl;
}
    return 0;
}

