#include<bits/stdc++.h>
using namespace std;

#define N 100
int n; //number of vertices
int t=0;
vector<int> adj[N+1];
char color[N+1];
int parent[N+1], d[N+1], f[N+1], low[N+1];
void dfs(vector<int> adj[N+1]);
void dfs_visit(int node);
int ap[N+1], ans=0;


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
    int m; scanf("%d %d", &n,&m);
    init();
    for(int i=1;i<=m;i++) {
        int a,b; scanf("%d %d", &a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj);
    //for(int i=1;i<=n;i++) printf("%d %d %d\n", i,d[i],low[i]);
    for(int i=1;i<=n;i++)
        if(ap[i]) printf("%d ", i);
}


void dfs(vector<int> adj[N+1]) {
    for(int i=1;i<=n;i++) {
        if(color[i]=='w') dfs_visit(i);
    }
}

void dfs_visit(int node) {
    color[node]='g';
    low[node]=d[node]=++t;
    int child=0;
    for(auto &v:adj[node]) {
        if(color[v]=='w') {
            child++;
            parent[v]=node;
            dfs_visit(v);
            if(d[node]<=low[v] && parent[node]!=-1) ap[node]=1; // for bridge detection d[node]<low[j]
            if(child>1 && parent[node]==-1) ap[node]=1;
            low[node]=min(low[node],low[v]); // tree edge
        }
        else if(v!=parent[node]) low[node]=min(low[node],d[v]); //back edge
    }
    color[node]='b';
    f[node]=++t;
}
