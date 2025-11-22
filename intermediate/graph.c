#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX], n;

void createGraph(){
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;
}

void insertEdge(){
    int u,v;
    printf("Enter edge (u v): ");
    scanf("%d %d",&u,&v);
    if(u>=n || v>=n || u<0 || v<0) { printf("Invalid vertices\n"); return; }
    adj[u][v]=1;
    adj[v][u]=1;
}

void printAdjMatrix(){
    printf("Adjacency Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void listAdjacent(){
    int u;
    printf("Enter vertex: ");
    scanf("%d",&u);
    if(u>=n || u<0){ printf("Invalid vertex\n"); return; }
    printf("Vertices adjacent to %d: ", u);
    for(int i=0;i<n;i++)
        if(adj[u][i]) printf("%d ",i);
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("\n1.Create Graph 2.Insert Edge 3.Print Matrix 4.List Adjacent 5.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: createGraph(); break;
            case 2: insertEdge(); break;
            case 3: printAdjMatrix(); break;
            case 4: listAdjacent(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
