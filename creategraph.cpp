#include <stdio.h>
#include<stdlib.h>
#include<vector>
#define MAX 20
using namespace std;
typedef enum{FALSE,TRUE}Boolean;
Boolean visited[MAX];
typedef struct Mgraph
{
    char vexs[MAX];
    int edges[MAX][MAX];
    int n,e;

}Mgraph,*MG;

typedef struct VertexNode
{
    struct VertexNode * next;
    int vex;
} VNode;

typedef struct EdgeNode
{
    char edge;
    VNode* first=NULL;
}ENode;

typedef struct
{
    ENode adjlist[MAX];
    int n,e;

}ALGraph;
void DFS_mode(ALGraph* G,int i);
void BFS_mode(ALGraph*G,int i);

void createMgraph(Mgraph *G)
{
    int t,p;
    int x,y=0;// coordiante of the metrix
    printf("please input the number of vexs\n");
    scanf("%d",&G->n);
    printf("please input the number of edges\n");
    scanf("%d",&G->e);
    fflush(stdin);
    printf("please input all the nodes\n");
    for(t=0;t<G->n;t++)
    {
        scanf("%c",&G->vexs[t]);
        fflush(stdin);
            }
    for(t=0;t<G->n;t++)
        for(p=0;p<G->n;p++)
            G->edges[t][p]=0;


    printf("please input the edge,for example,for instance,the input of \"1,3\",which means the first vex is connected with the third vex\n");



    for(t=0;t<G->e;t++)
    {
        scanf(" %d,%d",&x,&y);
        G->edges[x-1][y-1]=1;
        G->edges[y-1][x-1]=1;
        fflush(stdin);

    }

}

void PrintMgraph(Mgraph G)
{
    int i,j;
    int demen=G.n;
    printf("the matrix is set below:\n");
    for(i=0;i<demen;i++)
    {

        for(j=0;j<demen;j++)
        {
            printf("%d ",G.edges[i][j]);
        }
        printf("\n");
    }
}

void createAG(ALGraph* G)
{
    int i,j,p,q;
    VNode* s;
    printf("please input the number of nodes and edges in the graph\n");
    scanf(" %d,%d",&G->n,&G->e);
    fflush(stdin);
    printf("please input the vertex in the graph\n");

    for(i=0;i<G->n;i++)
    {
        scanf("%c",&G->adjlist[i].edge);
        G->adjlist[i].first=NULL;
        fflush(stdin);
    }
    printf("please put out the connected nodes, or you can call it an edge,note:in this case,the first node is 0 but not 1\n");

    for(j=0;j<G->e;j++)
    {
        scanf(" %d,%d",&p,&q);
        fflush(stdin);
        s=(VNode*)malloc(sizeof(VNode));
        s->vex=p;
        s->next=G->adjlist[q].first;
        G->adjlist[q].first=s;

        s=(VNode*)malloc(sizeof(VNode));
        s->vex=q;
        s->next=G->adjlist[p].first;
        G->adjlist[p].first=s;

    }
}

void prinfALgraph(ALGraph *G)
{
    int i,j;
    printf("the table is shows below:\n");
    for(i=0;i<G->n;i++)
    {
        VNode* p=G->adjlist[i].first;
        printf("%c",G->adjlist[i].edge);
        while(p)
        {
            printf("->%c",G->adjlist[p->vex].edge);
            p=p->next;
        }
        printf("\n");
    }
}

void DFS(ALGraph *G)
{
    int i,j;
    for(i=0;i<G->n;i++)
    visited[i]=FALSE;
    for(i=0;i<G->n;i++)
    {
        if(!visited[i])
        {
            DFS_mode(G,i);
        }
    }
}

void DFS_mode(ALGraph *G,int i)
{


    VNode* v,p;
    printf(" %c->",G->adjlist[i].edge);
    visited[i]=TRUE;
    v=G->adjlist[i].first;

   while(v)
   {
       if(!visited[v->vex])
       {
           DFS_mode(G,v->vex);
       }
       v=v->next;

   }
}

void BFS(ALGraph *G)
{
    int i;
    for(i=0;i<G->n;i++)
    visited[i]=FALSE;
    for(i=0;i<G->n;i++)
    {
        if(!visited[i])
        {
            BFS_mode(G,i);
        }
    }

}
//
//void BFS_mode(ALGraph *G,int i)
//{
//    vector<int> vec;
//    vector<int>::iterator it;
//    VNode* v;
//    int j;
//    printf("%c->",G->adjlist[i].edge);
//    visited[i]=FALSE;
//    v=G->adjlist[i].first;
//    while(v)
//    {
//        if(!visited[v->vex])
//        {
//            printf("%c->",G->adjlist[v->vex].edge);
//            visited[v->vex]=FALSE;
//            vec.push_back(v->vex);
//        }
//        v=v->next;
//
//    }
//    for(it=vec.begin();it!=vec.end();it++)
//    {
//        BFS_mode(G,*it);
//    }
//
//}

void BFS_mode(ALGraph *G,int i)
{
    int Q[MAX],front,rear;
    VNode* v;
    front=rear=-1;

    front++;
    Q[front]=i;
    visited[front]=TRUE;
     printf("%c->",G->adjlist[i].edge);
    while(front!=rear)
    {
        rear++;
        v=G->adjlist[Q[rear]].first;

        while(v)
        {
            if(!visited[v->vex])
            {
                front++;
                Q[front]=v->vex;
                visited[v->vex]=TRUE;
                printf("%c->",G->adjlist[v->vex].edge);



            }
            v=v->next;
        }





    }
}
int main()
{
    printf("the adjacency matrix is set as follows\n");
    Mgraph G;
    createMgraph(&G);
    PrintMgraph(G);
    printf("--------------------------------------------------------");
    printf("the adjacency table is set as follows\n");
    ALGraph AG;
    createAG(&AG);
    prinfALgraph(&AG);
    printf("----------------------------------------------------------\n");
    printf("DPS:\n");
    DFS(&AG);
    printf("\n----------------------------------------------------------\n");
    printf("BFS:\n");
    BFS(&AG);
}

