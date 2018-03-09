/*************************************************************************
	> File Name: prim.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月27日 星期三 18时31分17秒
 ************************************************************************/
#include<iostream>
using namespace std;
typedef string VertexType;//顶点类型
typedef int EdgeType;//边上的权值
const int MAXVEX=100;//最大顶点数
const int INFINITY=65535;
bool vis[MAXVEX];
typedef struct{
    VertexType vexs[MAXVEX];//顶点表
    EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵，可看作边表
    int numVertexes,numEdges;//图中当前的顶点数和边数
}MGraph;
void CreateMGraph(MGraph*G){
    int i,j,k,w;
    cout<<"输入顶点数和边数:"<<endl;
    cin>>G->numVertexes>>G->numEdges;
    for(i=0;i<G->numVertexes;i++){
        //输入顶点信息，建立顶点表
        cout<<"输入下一个顶点:";
        cin>>G->vexs[i];}
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
            G->arc[i][j]=INFINITY;//邻接矩阵初始化
    for(k=0;k<G->numEdges;k++){
        cout<<"输入边(vi,vj)上的下标i,下标j,权值w:"<<endl;
        cin>>i>>j>>w;
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }
}
void Prim(MGraph G){
    int min,i,j,k;
    int adjvex[MAXVEX];//保存相关顶点下标
    int lowcost[MAXVEX];//保存相关顶点间边的权值
    lowcost[0]=0;//初始化第一个权值为0,即V0加入生成树
    adjvex[0]=0;
    for(i=1;i<G.numVertexes;i++){
        lowcost[i]=G.arc[0][i];//将V0顶点与之有边的权值存入数组
        adjvex[i]=0;
    }
    for(i=1;i<G.numVertexes;i++){
        min=INFINITY;
        j=1;k=0;
        while(j<G.numVertexes){
            if(lowcost[j]!=0&&lowcost[j]<min){
                min=lowcost[j];//则让当前权值成为最小值
                k=j;
            }
            j++;
        }
        cout<<"("<<adjvex[k]<<","<<k<<")"<<" ";//打印当前顶点边中权值最小边
        lowcost[k]=0;//将当前顶点的权值设置为0,表示此顶点已经完成任务
        for(j=1;j<G.numVertexes;j++){
            if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j]){
                lowcost[j]=G.arc[k][j];//将较小权值存入lowcost
                adjvex[j]=k;//将下标为k的顶点存入adjvex
            }
        }
    }
}
int main(){
    MGraph G;
    CreateMGraph(&G);
    Prim(G);
    return 0;
}
