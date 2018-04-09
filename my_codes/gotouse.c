/*************************************************************************
	> File Name: gotouse.c
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月05日 星期四 21时31分12秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int a;
    a=getchar();
    switch(a){
        case 1:goto print1;break;
        case 2:goto print2;break;
        case 3:goto print3;break;
        default:goto dft;break;
    }
    print1:
        printf("it's print 1");
    print2:
        printf("it's print 2");
    print3:
        printf("it's print 3");
    dft:
        printf("it's print 4");
    return 0;
}
