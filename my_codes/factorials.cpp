/*************************************************************************
	> File Name: factorials.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
z> Created Time: 2018年03月13日 星期二 11时26分56秒
 ************************************************************************/

#include<iostream>
#include<memory.h>
using namespace std;
int mut[14000];
int main(){
    int n;
        while(cin>>n){ 
        int length=1;
        int res=1;
        memset(mut,0,sizeof(int)*14000);
        mut[0]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<length;j++)
            {
                int temp=mut[j]*i+res;
                 mut[j]=temp%10;
                res=temp/10;
                if(res>0&&j==length-1){
                    //mut[length]=res;
                    length++;
                }

        }
        /*for(int i=0;i<length;i++)
            cout<<mut[i];
        cout<<endl;
        cout<<length<<endl;*/
        int i;
        for(i=length-1;i>=0;i--){
                cout<<mut[i];
        }
            cout<<endl;
        //cout<<length-i<<endl;
    }
    return 0;
}
