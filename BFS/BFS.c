//S-53
#include<stdio.h>
//const int N=1000;
#define inf 100000
char color[1000];
int prev[1000],d[1000];
int Q[1000];
int sp=0,ep=0;
void Enqueue(int val){
    Q[ep]=val;
    ep++;
}
int Dequeue(){
   int temp=Q[sp];
   sp++;
   return temp;
}
int is_empty(){
    return ep==sp;
}
void BFS(int m,int g[][m+1],int s){
    for(int i=1;i<=m;i++){
        color[i]='w';
        prev[i]=-1;
        d[i]=inf;
    }
    color[s]='g';
    d[s]=0;
    prev[s]=-1;
    Enqueue(s);
    while(!is_empty()){
        int u;
        u=Dequeue();
        for(int i=1;i<=m;i++){
            if(g[u][i]==1&&color[i]=='w'){
                int v=i;
                color[v]='G';
                d[v]=d[u]+1;
                prev[v]=u;
                Enqueue(v);
            }
        }
        color[u]='B';
    }
}
void print_path(int s,int v){
    if(v==s){
        printf("%d ",s);
    }
    else if(prev[v]==-1){
        printf("No path\n");
    }
    else{
        print_path(s,prev[v]);
        printf("%d ",v);
    }
}


int main(){
    printf("Enter the number of vertex and edges of the graph:\n");
    int m,n;
    scanf("%d%d",&m,&n);
    int g[m+1][m+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            g[i][j]=0;
        }
    }
    int max=m;
    printf("Enter the corresponding edges of the vertex: \n");
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=1;
        g[y][x]=1;
    }
    int s;
    printf("Enter the source node: ");
    scanf("%d",&s);
    //DFS(max,g,s);

    BFS(max,g,s);
    for(int i=1;i<=max;i++){
        printf("discovery time of %d vertex is %d\n",i,d[i]);
    }
    for(int i=1;i<=max;i++){
        printf("path of %d node is:\n",i);
        print_path(s,i);
        printf("\n");
    }


}

