//NIKHIL KUMAR; Roll - S202000020289; Assign - 12;

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//taking vertices and edges:
int V, E;
int queue[25], visited[25], N = 10;
//initialising the given graph in question
int a[][2] = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {2, 3}, {3, 6}, {3, 7}, {4, 8}, {4, 5}, {4, 9}, {5, 9}, {6, 7}, {8, 9}, {9, 10}};

void Adj_Mat(int Adj[][V+1], int a[][2]){
    for(int i = 0; i<V+1; i++){
        for(int j = 0; j<V+1; j++){
            Adj[i][j] = 0;            // initialising all elements to zero
        }
    }

    for (int k = 0; k<E; k++){
        int x = a[k][0];
        int y = a[k][1];

        Adj[x][y] = 1;
        Adj[y][x] = 1;          
    }
}

void Display_AdjMat(int Adj[][V+1]){
    for(int i = 1; i<V+1; i++){
        for(int j = 1; j<V+1; j++){
            printf(" %d ", Adj[i][j]);        
        }
        printf("\n");
    }
}

void BFS_sort_(int node){
    int front = 0, rear = -1;
    for (int i = 1; i<N+1; i++){
        if(a[node][i] && !visited[i])
        queue[++rear] = i;
    }
    if (front<=rear){
        visited[queue[front]] = 1;
        BFS_sort_(queue[++front]);
    }

}

//-----------------------------------------------------------
struct node{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph{
    int numVertices;
    int* visited;
    struct node** adjLists; // int** -> since, 2d array
};

void DFS_conn(struct Graph* graph, int vertex) {
    struct node* ptr = graph->adjLists[vertex];
        
    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);
    
    while(ptr!=NULL){
        int adj_vertex = ptr->vertex;
    if(graph->visited[adj_vertex] == 0) {
        DFS_conn(graph, adj_vertex);
    }
    ptr = ptr->next;
    }       
}

 
struct node* createNode(int v){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    
    graph->visited = malloc(vertices * sizeof(int));
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(struct Graph* graph, int source, int destination){
    // Add edge from source to destination
    struct node* newNode = createNode(destination);
    newNode->next = graph->adjLists[source];
    graph->adjLists[source] = newNode;
 
    // Add edge from destination to source
    newNode = createNode(source);
    newNode->next = graph->adjLists[destination];
    graph->adjLists[destination] = newNode;
}
 
void printGraph(struct Graph* graph){
    int v;
    for (v = 0; v <= graph->numVertices; v++){
        struct node* ptr = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (ptr){
            printf("%d -> ", ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


int main()
{
    // que - 1
    printf("\n\t__________QUESTION = 1___________\n");
    printf("\tTime Comp. = O(|V|^2) & Space Comp. = O(|V|^2)\n\n");    // hers V = vertex
    V = 10;           
    int Adj[V+1][V+1];
    E = sizeof(a)/sizeof(a[0]);  

    Adj_Mat(Adj, a);
    Display_AdjMat(Adj);

//que - 2
    printf("\n\t__________QUESTION = 2___________\n");
    printf("\tTime Comp. = O(|V|^2) & Space Comp. = O(|V|^2)\n\n"); //V = vertices

    for (int i = 1; i<V+1; i++){
        queue[i] = 0;
        visited[i] = 0;
    }

    BFS_sort_(1);
    printf("Nodes reachable from NODE(1) are :\n");
    for (int j = 0; j<V; j++){
        if (visited[j])
        printf("%d ", j);
    }
    
//que - 3
    printf("\n\t__________QUESTION = 3___________\n");
    printf("\tTime Comp. = O(|V|^2) & Space Comp. = O(|V|^2)\n\n"); //V = vertices

    struct Graph* graph = createGraph(10);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 8);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 9);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 7);
    addEdge(graph, 8, 9);
    addEdge(graph, 9, 10);
    
    printGraph(graph);
    DFS_conn(graph, 2);

    printf("\n");
    return 0;

}