#include<iostream>
#include<climits>

class Edge
{
public:
    int src, dist, weight;
};

class Graph
{
public:
    int V, E;
    Edge *edge;
};

Graph* createGraph(int V, int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printDistance(int dist[], int n)
{
    std::cout << "All vertices distance table from source :- " << std::endl;
    std::cout << "Vertex   Distance from Source" << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cout << i << "    " << dist[i] << std::endl;
    }
}

void Bellman_Ford(Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Set all the distances form the source to other vertices as 0 initially.
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax all edges |V| - 1 times. A simple shortest path from source to any other vertex can have at-most |V| - 1 edges.
    for(int i = 1; i <= V-1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dist;
            int weight = graph->edge[j].weight;

            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Ditecting the presence of the Negative cycle inthe graph.
    for(int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dist;
        int weight = graph->edge[i].weight;

        if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            std::cout << "Negative cycle present in the graph." << std::endl;
        }
    }

    printDistance(dist, V);
}

int main()
{
    int V, E;

    std::cout << "Enter the number of vertices :- ";
    std::cin >> V;
    std::cout << "Enter the number of edges :- ";
    std::cin >> E;

    Graph *graph = createGraph(V, E);

    std::cout << "Enter the source destination and weight of edges :- " << std::endl;
    for(int i = 0; i < E; i++)
    {
        std::cout << "Enter the source vertex index :- ";
        std::cin >> graph->edge[i].src;
        std::cout << "Enter the destination vertex index :- ";
        std::cin >> graph->edge[i].dist;
        std::cout << "Enter the weight of the edge :- ";
        std::cin >> graph->edge[i].weight;
    }

    Bellman_Ford(graph, 0);
}
