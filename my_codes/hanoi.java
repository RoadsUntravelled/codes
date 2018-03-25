/*************************************************************************
	> File Name: hanoi.java
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月25日 星期日 19时05分31秒
 ************************************************************************/
import java.util.Scanner;
public class hanoi{
    static int count=0;//统计移动次数(可不需要,因为最少次数已经与n的值对应的记录在数组B中,即B[n])
    public static void main(String[]args){
        int n;//盘子数
        int flag_j;//记录找到的j的值
        int []A=new int[65];//数组A:用来记录未加第四个柱子时候的移动次数情况
        int []B=new int[65];//数组B:用来记录加了第四个柱子的情况
        /*根据三个柱子移动策略给数组A赋值(下面描述是按照将a柱上盘子移动到C柱上的问题来叙述的),即
         * 假设移动n个盘子需要移动f(n)次,所以把n-1个盘子移动到c柱子上,需要移动f(n-1)次,
         * 然后把第n个盘子移动到c柱子上,需要移动1次,
         * 最后把n-1个盘子移动到c柱子上,需要移动f(n-1)次,综上所述,一共移动了f(n)=2f(n-1)+1次
         */
        A[1]=1;//即三个柱子时,当i=1的时候,表示移动一个盘子,只需要移动一次
        for(int i=2;i<65;i++){//从i=2开始
            A[i]=2*A[i-1]+1;//f(n)=2f(n-1)+1
        }
        /*
         * 将n个盘子分为两部分,即前j个后n-jZ[\\]]]^__glloppp{|}~s^YXWVUUTTTSSSR
         * 且把前j个用四个柱子的方法,后i-j个用三个柱子的方法
         * 下面主要是找到使移动次数最少的j值
         */
        int count4;//记录四根柱子时,移动的总次数
        int min;//移动的最少次数,以用来和四个柱子时的其他情况进行比较
        int[]C=new int[65];//数组C:用来记录当前i下找到的j值
        C[1]=0;//设置i=1时,初始值为0,即只有一个盘子时,令j=0
        C[2]=0;//设置i=2时,初始值为0,即只有两个盘子时,令j=0;此时的i相当于盘子数n
        for(int i=3;i<=64;i++){
            min=A[i];//假设没加第四个柱子的结果次数为min的初值
            B[1]=1;//可知i=1时,即一个盘子从柱子a->d,移动次数为1次
            B[2]=3;//i=2时,即两个盘子从a->d,移动次数为3次
            flag_j=0;
            for(int j=1;j<i;j++){
                count4=2*B[j]+A[i-j];//j个移动到第四个柱子,然后把剩下的i-j个在第四个柱子不能用的情况下,移到第三个柱子
                /*
                 * 
                 * 如果三根柱子时的次数min大于四根柱子时的次数flag,则用flag更新min
                 * 并记录下此时j的值,即得到了怎么分割盘子,才能使最终的移动次数最少
                 */
                if(min>count4){
                    min=count4;
                    flag_j=j;
                }
                B[i]=min;//将min赋给B[i],即4跟柱子时,i个盘子从a->d的次数
                C[i]=flag_j;//找到了当前i下的j值
            }
        }
        Scanner scanner=new Scanner(System.in);
        while(true){
            System.out.print("请输入一个n值(应为1-64之间的整数,输入0结束程序)");
            n=scanner.nextInt();
            if(n==0){
                System.out.println("ByeBye");
                break;
            }
            if(n>64||n<1){
                System.out.println("输入的n有误,请重新输入");
                continue;
            }
        char a='a',b='b',c='c',d='d';
        Hanoi(n,a,b,c,d,C);//把n个盘子从a柱移动到b柱
        System.out.println("共移动了:"+B[n]+"次");
        System.out.println("共移动了:"+count+"次");//与B[n]的值是一样的
        count=0;
        }
    }

public static void Hanoi(int n,char a,char b,char c,char d,int C[]){
    int j=C[n];//j个盘子使用四个柱子的移动方式
    if(n>0){
        Hanoi(j,a,d,b,c,C);//把j个盘子移动到d柱子上
        hanoi_basic_3(n-j,a,b,c);//把n-j个盘子移动到b柱子上(使用三个柱子的移动方式)
        Hanoi(j,d,b,a,c,C);//把j个盘子移动到b柱子上
    }
}
public static void hanoi_basic_3(int n,char a,char c,char b){
    if(n>0){
        hanoi_basic_3(n-1,a,b,c);//把n-1个盘子移动到c柱子上
        move(n,a,c);//把a移动到c
        hanoi_basic_3(n-1,b,c,a);//把第n个盘子移动到c柱子上
    }
}
public static void move(int n,char a,char c){
    System.out.println(a+"->"+c);
    count++;
}
}
