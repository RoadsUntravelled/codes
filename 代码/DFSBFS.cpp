/*************************************************************************
	> File Name: DFSBFS.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月27日 星期三 15时56分04秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
typedef string VertexType;//顶点类型
typedef int EdgeType;//边上的权值
const int MAXVEX=100;//最大顶点数
const int INFINITY=0;
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
            G->arc[i][j]=0;//邻接矩阵初始化
    for(k=0;k<G->numEdges;k++){
        cout<<"输入边(vi,vj)上的下标i，下标j:"<<endl;
        cin>>i>>j;
        G->arc[i][j]=1;
        G->arc[j][i]=G->arc[i][j];
    }
}
void DFS(MGraph G,int i){
    int j;
    vis[i]=true;
    cout<<G.vexs[i]<<" ";//打印顶点
    for(j=0;j<G.numVertexes;j++)
        if(G.arc[i][j]==1&&!vis[j])
            DFS(G,j);
}
void DFSTraverse(MGraph G){
    int i;
    for(i=0;i<G.numVertexes;i++){
        vis[i]=false;
    for(i=0;i<G.numVertexes;i++)
        if(!vis[i])
            DFS(G,i);
    }
}
void BFSTraverse(MGraph G){
    int i,j;
    queue<int>q;
    for(i=0;i<G.numVertexes;i++)
        vis[i]=false;
    for(i=0;i<G.numVertexes;i++)
    {
        if(!vis[i]){
            vis[i]=true;
            cout<<G.vexs[i]<<" ";
            q.push(i);
            while(!q.empty()){
                i=q.front();
                q.pop();
                for(j=0;j<G.numVertexes;j++){
                    if(G.arc[i][j]==1&&!vis[j]){
                        vis[j]=true;
                        cout<<G.vexs[j]<<" ";
                        q.push(j);
                    }
                }
            }
        }
    }
}
int main(){
    MGraph G;
    CreateMGraph(&G);
    cout<<"DFS为:"<<endl;
    DFSTraverse(G);
    cout<<endl;
    cout<<"BFS为:"<<endl;
    BFSTraverse(G);
    return 0;
}
