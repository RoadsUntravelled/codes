/*************************************************************************
	> File Name: math_soulution_of_frac1.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月23日 星期五 17时12分46秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct fraction{
    int up,down;
    fraction(int _up,int _down):up(_up),down(_down){}
};
void genfrac(vector<fraction> &dst,int &N,int n1,int d1, int n2,int d2)
{
    cout<<"n1:"<<n1<<" d1:"<<d1<<" n2:"<<n2<<" d2:"<<d2<<endl;
	if(d1+d2>N)
		return;
	genfrac(dst,N,n1,d1,n1+n2,d1+d2);
	dst.push_back(fraction(n1+n2,d1+d2));
	genfrac(dst,N,n1+n2,d1+d2,n2,d2);
}
int main(){
    int N;
    while(cin>>N){
        vector<fraction>frac;
        genfrac(frac,N,0,1,1,1);
    }
    return 0;
}
