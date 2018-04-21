/*************************************************************************
	> File Name: heapsort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月20日 星期五 17时59分16秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
void heap_adjust(int*,int,int);
void heap_sort(int*list,int n){
    for(int i=n/2;i>0;i--)
        heap_adjust(list,i,n);
    for(int i=n;i>1;i--)
    {
        swap(list[1],list[i]);
        heap_adjust(list,1,i-1);
    }
}
void heap_adjust(int*list,int s,int m){
    int temp=list[s];
    for(int j=2*s;j<=m;j*=2){
        if(j<m&&list[j]<list[j+1])
            ++j;
        if(temp>=list[j])
            break;
        list[s]=list[j];
        s=j;
    }
    list[s]=temp;
}
int main(){
    int list[]={0,5,6,8,1,2,5,6,3};
    heap_sort(list,8);
    copy(list+1,list+9,ostream_iterator<int>(cout," "));
    cout<<endl;
    return 0;
}
