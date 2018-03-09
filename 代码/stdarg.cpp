/*************************************************************************
	> File Name: stdarg.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月13日 星期六 14时25分30秒
 ************************************************************************/

#include<iostream>
#include<cstdarg>
using namespace std;
int max(int n,...){//定参n表示后面参数变量,定界用,输入时切勿搞错
    va_list ap;//定义一个va_list指针来访问参数表
    va_start(ap,n);//初始化ap,让它指向第一变参
    int maximum=-0x7FFFFFFF;//这是一个最小的整数
    cout<<maximum<<endl;
    int temp;
    for(int i=0;i<n;i++){
        temp=va_arg(ap,int);//获取一个int型参数,并且ap指向下一个参数.这里取的是是整数所以是这样,但是如果比较字符串则使用char*,这里需要注意的是short char,他们使用时需要转换成int型,这里也可以直接写成int
    if(maximum<temp)maximum=temp;
    
    }
    va_end(ap);// 善后工作,关闭ap;
    return maximum;
}
int main(){
    cout<<max(3,10,20,30)<<endl;
    cout<<max(6,20,40,10,50,30,40);
    return 0;
}
