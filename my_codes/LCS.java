/*************************************************************************
	> File Name: LCS.java
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月10日 星期二 14时53分53秒
 ************************************************************************/

public class LCS{
    public static int lcslength(char[]x,char[]y,int[][]b){
        int m=x.length-1;
        int n=y.length-1;
        int[][]c=new int[m+1][n+1];
        for(int i=1;i<=m;i++)c[i][0]=0;
        for(int i=1;i<=n;i++)c[0][i]=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(x[i]==y[i]){
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]=1;
                }
                else if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                    b[i][j]=2;
                }
                else{
                    c[i][j]=c[i][j-1];
                    b[i][j]=3;
                }
            }
        return c[m][n];
    }
    public static void lcs(int i,int j,char[]x,int[][]b){
        if(i==0||j==0)return;
        if(b[i][j]==1){
            lcs(i-1,j-1,x,b);
            System.out.println(x[i]);
        }
        else if(b[i][j]==2)lcs(i-1,j,x,b);
        else lcs(i,j-1,x,b);
    }
}
