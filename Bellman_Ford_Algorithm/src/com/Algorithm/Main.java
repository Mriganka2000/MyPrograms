package com.Algorithm;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int V, E;
        System.out.print("Enter the number of vertices :- ");
        V = s.nextInt();
        System.out.print("Enter the number of edges :- ");
        E = s.nextInt();
        Graph graph = new Graph(V, E);
        System.out.println("Enter the edge source , destination, weight :- ");
        for (int i = 0; i < E; i++) {
            System.out.print("Enter the source vertex :- ");
            graph.edge[i].src = s.nextInt();
            System.out.print("Enter the destination vertex :- ");
            graph.edge[i].dest = s.nextInt();
            System.out.print("Enter the weight of the edge :- ");
            graph.edge[i].weight = s.nextInt();
        }
        graph.BellmanFord(graph, 0);
    }
}
