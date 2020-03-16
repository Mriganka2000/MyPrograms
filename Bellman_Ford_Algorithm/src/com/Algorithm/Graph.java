package com.Algorithm;

public class Graph {
    public class Edge {
        public int src, dest, weight;

        Edge() {
            src = dest = weight = 0;
        }
    }
    int V, E;
    Edge edge[];

    Graph(int V, int E) {
        this.V = V;
        this.E = E;
        edge = new Edge[E];
        for (int i = 0; i < E; i++) {
            edge[i] = new Edge();
        }
    }

    void printdistances(int dist[], int n) {
        System.out.println("The distance the from the source vertex :- ");
        System.out.println("Vertex      distance");
        for (int i = 0; i < n; i++) {
            System.out.println(i + "        " + dist[i]);
        }
    }

    void BellmanFord(Graph graph, int src) {
        int V = graph.V;
        int E = graph.E;
        int[] dist = new int[V];

        for (int  i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        // Relax all edges |V| - 1 times. A simple shortest path from src to any other vertex can have at-most |V| - 1 edges
        for (int i = 1; i < V; i++) {
            for (int j = 0; j < E; j++) {
                int u = graph.edge[j].src;
                int v = graph.edge[j].dest;
                int weight = graph.edge[j].weight;
                if(dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        for (int i = 0; i < E; i++) {
            int u = graph.edge[i].src;
            int v = graph.edge[i].dest;
            int weight = graph.edge[i].weight;
            if(dist[u] + weight < dist[v]) {
                System.out.println("The graph contains negative cycle.");
            }
        }
        printdistances(dist, V);
    }
}
