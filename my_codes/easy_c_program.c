/*************************************************************************
	> File Name: easy_c_program.c
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年09月13日 星期四 17时43分32秒
 ************************************************************************/

#include<stdio.h>
#include <conio.h>//getche函数
#include <stdlib.h>//包含清空cmd命令的
int MenuReturn;
int Help(void);//
int About(void);
int  Menu(void);
int Shezhi(void);
int Zhu(void);
void DealWithMenu(int MenuReturn); 
int main(void)
{
	system("title 小程序系统——莫言");
	system("color 70");
	while(1)
	{
		MenuReturn = Menu();
		DealWithMenu(MenuReturn);
	}
	return 0;
} 
int Menu(void)//主菜单
{
	int sel = 1;
	int tem = 0;
	char kb;
	system("cls");
	printf("  小程序系统——莫言情难忘\n\n\n");
	printf("->开始程序<-\n  玩法介绍  \n  关    于  \n  设    置  \n  退    出  \n");
	do{
		kb = getch();
		switch(kb)
		{
		case 'w' : tem--;sel += tem;break;
		case 's' : tem++;sel += tem; break;        
		default  : NULL ; break;
		}
		tem = 0;
		if (sel == 0)
		{
			sel = 4;
		}
		if (sel == 6)
		{
			sel = 1;
		}
		system("cls");
		printf("  小程序系统——莫言情难忘\n\n\n");
		switch (sel)
		{
		case 1 : printf("->开始程序<-\n  玩法介绍  \n  关    于  \n  设    置  \n  退    出  \n");break;
		case 2 : printf("  开始程序  \n->玩法介绍<-\n  关    于  \n  设    置  \n  退    出  \n");break;
		case 3 : printf("  开始程序  \n  玩法介绍  \n->关    于<-\n  设    置  \n  退    出  \n");break;
		case 4 : printf("  开始程序  \n  玩法介绍  \n  关    于  \n->设    置-<\n  退    出  \n");break;
		case 5 : printf("  开始程序  \n  玩法介绍  \n  关    于  \n  设    置  \n->退    出-<\n");break;
			
		default: return-1; break; 
		}
	}while(kb != '\r');
	
	return sel;
}
void DealWithMenu(int MenuReturn)
{
	int retu;
	switch(MenuReturn)
	{
	case 1 : Zhu();break;
	case 2 : retu = Help();break;
	case 3 : retu = About();break;
				case 4 : retu = Shezhi();break;
                case 5 : exit(0);break;
                case -1: printf("错误！\n");        
	}
	
}
int Zhu(void)
{
	int linshi = 0;
	system("cls");
	printf("暂无主程序");
	printf("返回菜单吗？\t   =====   y/n\n");
	do{
		int ch = getchar();
		if(ch == 'y')
		{
			return 1;
		}
		if(ch == 'n')
		{
			linshi = 1;
		}
	}while(linshi == 1);
} 
int Help(void)
{
	int linshi = 0;
	system("cls");
	printf("		暂无帮助\n");
	printf("返回菜单吗？\t   =====   y/n\n");
	do{
		int ch = getchar();
		if(ch == 'y')
		{
			return 1;
		}
		if(ch == 'n')
		{
			linshi = 1;
		}
	}while(linshi == 1);
} 
int About(void)
{
	int linshi = 0;
	system("cls"); 
	printf("		暂无关于\n");
	printf("返回菜单吗？\t   ======    y/n\n");
	do{
		int ch = getchar();
		if(ch == 'y')
		{
			return 1;
		}
		if(ch == 'n')
		{
			linshi = 1;
		}
	}while(linshi == 1);
}
 
int Shezhi(void)
{
	int linshi = 0;
	char i;//控制颜色的变量
	system("cls"); 
	printf("		颜色设置\n");
	printf("		0黑白\n		1蓝白\n		2绿白\n		3绿黄\n		4黑红\n");
	printf("		5黑紫\n		6白黑\n		其他键返回主菜单\n");
	printf("		请输入你想切换的颜色\n");
	scanf("%c",&i);
	switch(i)
	{
	case '0':system("color 07");break;
	case '1':system("color 17");break;
	case '2':system("color 27");break;
	case '3':system("color 2E");break;
	case '4':system("color 04");break;
	case '5':system("color 05");break;
	case '6':system("color 70");break;
	default:return 1;break; 
	}
}
