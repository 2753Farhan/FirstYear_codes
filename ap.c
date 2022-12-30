#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define N 100
int n; //number of vertices
int time=0;
int graph[N+1][N+1];
char color[N+1];
int parent[N+1], d[N+1], f[N+1], low[N+1];
void dfs(int graph[N+1][N+1]);
void dfs_visit(int node);
int ap[N+1], ans=0;

int min(int a,int b) {
    if(a<b) return a;
    else return b;
}

void init() {
    for(int i=1;i<=n;i++) {
        color[i]='w';
        parent[i]=-1;
        d[i]=f[i]=0;
        low[i]=INT_MAX;
        ap[i]=0;
    }
}


int main() {
    //freopen("inputDFS.txt","r",stdin);
    int m; scanf("%d %d", &n,&m);
    init();
    for(int i=1;i<=m;i++) {
        int a,b; scanf("%d %d", &a,&b);
        graph[a][b]=graph[b][a]=1;
    }
    dfs(graph);
    for(int i=1;i<=n;i++) printf("%d %d %d\n", i,d[i],low[i]);
    //printf("%d\n", ap);
    for(int i=1;i<=n;i++)
        if(ap[i]) printf("%d ", i);
}


void dfs(int graph[N+1][N+1]) {
    for(int i=1;i<=n;i++) {
        if(color[i]=='w') dfs_visit(i);
    }
}

void dfs_visit(int node) {
    color[node]='g';
    low[node]=d[node]=++time;
    int child=0;
    for(int v=1;v<=n;v++) {
        if(graph[node][v]==1 && color[v]=='w') {
            child++;
            parent[v]=node;
            dfs_visit(v);
            if(d[node]<=low[v] && parent[node]!=-1) ap[node]=1; // for bridge detection d[node]<low[v]
            if(child>1 && parent[node]==-1) ap[node]=1;
            low[node]=min(low[node],low[v]); // tree edge
        }
        else if(v!=parent[node]) low[node]=min(low[node],d[v]); //back edge
    }
    color[node]='b';
    f[node]=++time;
}
