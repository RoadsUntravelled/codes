/*************************************************************************
	> File Name: trymemcpy.c
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月24日 星期六 23时15分18秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
    char* s="GoldenGlobalView";
    char d[20];
   // clrscr();
    memcpy(d,s,(strlen(s)+1));
    printf("%s",d);
    printf("\\nds");
   // getchar();
    return 0;
}
