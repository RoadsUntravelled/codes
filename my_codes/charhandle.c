/*************************************************************************
	> File Name: charhandle.c
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月05日 星期四 21时18分09秒
 ************************************************************************/

#include<stdio.h>
int main(){
    char cChar;
    cChar=getchar();
    getchar();
    putchar(cChar);
    putchar('\n');
    putchar(getchar());
    putchar('\n');
    return 0;

}
