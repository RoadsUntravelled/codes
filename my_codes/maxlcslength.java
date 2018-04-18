/*************************************************************************
	> File Name: maxlcslength.java
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月17日 星期二 10时12分12秒
 ************************************************************************/
import java.util.*;
public class maxlcslength{
    public static int lcslength(char []x,char []y,int[][]b){
        int m=x.length-1;
        int n=y.length-1;
        int [][]c=new int[m+1][n+1];
        for(int i=1;i<=m;i++)c[i][0]=0;
        for(int i=1;i<=n;i++)c[0][i]=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(x[i]==y[j]){
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]=1;
                }
                else if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                    b[i][j]=2;
                }else{
                    c[i][j]=c[i][j-1];
                    b[i][j]=3;
                }
            }
        return c[m][n];
    }
    public static void lcs(int i,int j,char[]x,int[][]b){
        if(i==0||j==0)return ;
        if(b[i][j]==1){
            lcs(i-1,j-1,x,b);
            System.out.print(x[i]);
        }else if(b[i][j]==2)lcs(i-1,j,x,b);
        else lcs(i,j-1,x,b);
    }
    public static void main(String[]args){
        int m,n;
        Scanner scanner=new Scanner(System.in);
        m=scanner.nextInt();
        n=scanner.nextInt();
        char []x=new char[m+1];
        char []y=new char[n+1];
        String first=scanner.next();
        String second=scanner.next();
        for(int i=1;i<=m;i++)
            x[i]=first.charAt(i-1);
        for(int i=1;i<=n;i++)
            y[i]=second.charAt(i-1);
        int[][]b=new int[m+1][n+1];
        lcslength(x,y,b);
        lcs(m,n,x,b);
    }
}
