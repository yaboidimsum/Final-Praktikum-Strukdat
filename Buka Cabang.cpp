#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    int V;
    list<pair<int, int> >* adj;

    public:
    Graph(int V);
    void addEdgeRev(int u, int vertex, int w);
    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdgeRev(int u, int vertex, int w)
{

    adj[vertex].push_back(make_pair(u, w));
}


void Graph::shortestPath(int dest)
{
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, dest));
    dist[dest] = 0;
    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();
        list<pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int vertex = (*i).first;
            int weight = (*i).second;
            if (dist[vertex] > dist[u] + weight) {
                dist[vertex] = dist[u] + weight;
                pq.push(make_pair(dist[vertex], vertex));
            }
        }
    }
    for (int i = 1; i < V; ++i)
        printf("%d %d\n", i, dist[i]);
}

int main()
{
    int vertex, edge;
    scanf("%d %d", &vertex,&edge);
    Graph branch(vertex);
    int vertex_1,vertex_2,dist;
    for (int i = 0; i < edge; i++)
    {
        scanf("%d %d %d",&vertex_1,&vertex_2,&dist);
        branch.addEdgeRev(vertex_2, vertex_1, dist);

    }
        branch.shortestPath(0);

    return 0;
}
