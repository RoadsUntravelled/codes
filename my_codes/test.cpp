/*************************************************************************
	> File Name: test.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月20日 星期三 23时04分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
struct Station{
    int x,y,z;
    double dist;
    double shx,shy,shz;
};
int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        double v1,v2;//V1为三维速度，V2为二维速度
        cin>>v1>>v2;
        int p[4][4];
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                cin>>p[i][j];
        int a,b,c,d;
        a=(p[2][2]-p[1][2])*(p[3][3]-p[1][3])-(p[2][3]-p[1][3])*(p[3][2]-p[1][2]);
        b=(p[2][3]-p[1][3])*(p[3][1]-p[1][1])-(p[2][1]-p[1][1])*(p[3][3]-p[1][3]);
        c=(p[2][1]-p[1][1])*(p[3][2]-p[1][2])-(p[2][2]-p[1][1])*(p[3][1]-p[1][1]);
        d=-(a*p[1][1]+b*p[1][2]+c*p[1][3]);
        double square=a*a+b*b+c*c;
        double base=sqrt(square);
        int n;
        cin>>n;
        bool vis[16]={false};
        Station stat[16];
        for(int i=1;i<=n;i++){
            cin>>stat[i].x>>stat[i].y>>stat[i].z;
            stat[i].dist=(double)(abs(a*stat[i].x+b*stat[i].y+c*stat[i].z+d))/(base*v1);
            double t=(a*stat[i].x+b*stat[i].y+c*stat[i].z+d)/(double)(square);
            stat[i].shx=stat[i].x-a*t;
            stat[i].shy=stat[i].y-b*t;
            stat[i].shz=stat[i].z-c*t;
        }
        double tot=0;
        int i=1;
        int cnt=n;
        vis[1]=true;
        int low[16]={0};
        while(cnt){
            //cout<<"i="<<i<<endl;
            int index;
            double minum=999999999;
            for(int j=1;j<=n;j++)
                if(i!=j&&low[i]!=j){
                    double dist1=(double)(sqrt((stat[i].x-stat[j].x)*(stat[i].x-stat[j].x)+(stat[i].y-stat[j].y)*(stat[i].y-stat[j].y)+(stat[i].z-stat[j].z)*(stat[i].z-stat[j].z)))/v1;
                    double dist2=stat[i].dist+stat[j].dist+(double)(sqrt((stat[i].shx-stat[j].shx)*(stat[i].shx-stat[j].shx)+(stat[i].shy-stat[j].shy)*(stat[i].shy-stat[j].shy)+(stat[i].shz-stat[j].shz)*(stat[i].shz-stat[j].shz)))/v2;
                    double temp=dist1<dist2?dist1:dist2;
                    if(temp<minum){
                        index=j;
                        minum=temp;
                    }   
                }
            tot+=minum;
            low[index]=i;
            i=index;
            vis[i]=true;
            cnt--;
            } 

        /*for(int i=1;i<=n;i++)
            cout<<low[i]<<endl;*/

        /*for(int i=1;i<=n;i++)
            cout<<stat[i].shx<<" "<<stat[i].shy<<" "<<stat[i].shz<<" dist:"<<stat[i].dist<<endl;*/
        printf("%.6f\n",(int)(tot/0.000001+0.00005)*0.000001);
    }
    return 0;
}
