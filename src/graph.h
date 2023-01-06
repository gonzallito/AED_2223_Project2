// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <unordered_map>

using namespace std;

class Graph {
    struct Edge {
        string dest;   // Destination node
        int distance; // An integer weight
        string airline;
    };

    struct Node {
        string name;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    Graph();
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int n, bool dir = true);

    void setN(int n);

    void setHasDir(bool hasDir);

    // Add edge from source to destination with a certain weight
    void addEdge(string src, string dest, int distance, string airline);

    void printGraph();

    int get_shortest_path_code(string start, string end);
    void printPath(string start, string end, int option);




    // Depth-First Search: example implementation
    //void dfs(int v);

    /*
    // ----- Functions to implement in this class -----
    int outDegree(int v);
    int weightedOutDegree(int v);
    int connectedComponents();
    int giantComponent();
    list<int> topologicalSorting();
    bool hasCycle();

    int dfs1(int v);
    */
};

#endif
