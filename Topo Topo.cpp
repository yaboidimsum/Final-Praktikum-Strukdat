#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    int vertex;
    struct node *next;
} node;

typedef struct Graph
{
    int numVx;
    node **adjLists;
} Graph;

// Create a node
node *createNode(int v)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVx = vertices;
    graph->adjLists = (node **)malloc(vertices * sizeof(node *));
    for (int i = 0; i < vertices; i++) graph->adjLists[i] = NULL;
    return graph;
}

// Add edge
void addEdge(Graph *graph, int s, int d)
{
    node *newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
}

int dfs_(Graph *graph, int V, int visited[], int ordering[], int order_index)
{
    if (V == -1)
    {
        return 0;
    }
    visited[V] = 1;
    node *neighbours = graph->adjLists[V];
    for (node *temp = neighbours; temp != NULL; temp = temp->next)
    {
        if (!visited[temp->vertex]) order_index = dfs_(graph, temp->vertex, visited, ordering, order_index);
    }
    if (order_index == -1)
    {
        return 0;
    }
    ordering[order_index] = V;
    return order_index - 1;
}

void Topsort(Graph *graph, int *ordering)
{
    int visited[graph->numVx];
    memset(visited, 0, sizeof(visited));
    int order_index = graph->numVx - 1;

    for (size_t index = 0; index < graph->numVx; index++)
    {
        if (!visited[index]) order_index = dfs_(graph, index, visited, ordering, order_index);
    }
}

bool isCycleUtil(Graph *graph, int v, bool visited[], bool *recStack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        for (node *nb = graph->adjLists[v]; nb != NULL; nb = nb->next)
        {
            if (!visited[nb->vertex] && isCycleUtil(graph, nb->vertex, visited, recStack)) return true;
            else if (recStack[nb->vertex]) return true;
        }
    }
    recStack[v] = false;
    return false;
}

int isCycle(Graph *graph){
    int V = graph->numVx;
    bool *visited = new bool[V];
    bool *recStack = new bool[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (!visited[i] && isCycleUtil(graph, i, visited, recStack)) return true;

    return false;
}

int main(void)
{
    int x, y;
    int u, v;
    cin >> x >> y;

    Graph *graph = createGraph(x);

    for (size_t i = 0; i < y; i++)
    {
        cin >> u >> v;
        addEdge(graph, u - 1, v - 1);
    }

    bool Cyc = isCycle(graph);
    if (Cyc){
        cout << -1;
        return 0;
    }

    int ordering[graph->numVx];
    Topsort(graph, ordering);

    for (size_t i = 0; i < graph->numVx; i++)
    {
        cout << ordering[i] + 1<<" ";
    }
}
