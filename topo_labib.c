#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define N 100
int n;
int time=0;
int graph[N+1][N+1];
char color[N+1];
int parent[N+1], d[N+1], f[N+1];
void dfs(int graph[N+1][N+1]);
void dfs_visit(int node);
int topo[N+1], ind=1;

void init() {
    for(int i=1;i<=n;i++) {
        color[i]='w';
        parent[i]=-1;
        d[i]=f[i]=INT_MAX;
    }
}


int main() {
    //freopen("inputDFS.txt","r",stdin);
    int m; scanf("%d %d", &n,&m);
    init();
    for(int i=1;i<=m;i++) {
        int a,b; scanf("%d %d", &a,&b);
        graph[a][b]=1;
    }
    dfs(graph);
    //for(int i=1;i<=n;i++) printf("%d %d %d\n", i,d[i],f[i]);
    for(int i=ind-1;i>=1;i--) printf("%d ", topo[i]);
}


void dfs(int graph[N+1][N+1]) {
    for(int i=1;i<=n;i++) {
        if(color[i]=='w') dfs_visit(i);
    }
}

void dfs_visit(int node) {
    color[node]='g';
    d[node]=++time;
    for(int j=1;j<=n;j++) {
        if(graph[node][j]==1 && color[j]=='w') {
            parent[j]=node;
            dfs_visit(j);
        }
    }
    color[node]='b';
    f[node]=++time;
    topo[ind++]=node;
}
