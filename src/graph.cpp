// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int n, bool dir) : n(n), hasDir(dir) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(string src, string dest, int distance, string airline) {
    bool exists = false;

    for (auto & no : nodes) {
        if (no.name == src) {
            no.adj.push_back({dest, distance, airline});
            exists = true;
        }
    }

    if (!exists) {
        Node node;
        node.name = src;
        node.adj = list<Edge> {};
        node.visited = false;
        nodes.push_back(node);

        for (auto & n : nodes) {
            if (n.name == src) {
                n.adj.push_back({dest, distance, airline});
            }
        }
    }
}

void Graph::printGraph() {
    for (auto i : nodes) {
        //if (i.name == "GKA") {
            cout << "nome: " << i.name << endl;
            for (auto e: i.adj) {
                cout << "-------" << endl;
                cout << "destino: " << e.dest << endl;
                cout << "distance: " << e.distance << endl;
                cout << "airline: " << e.airline << endl;
            }
            cout << "-----------------------------------------------------------" << endl;
        //}
    }
}


vector<string> Graph::get_shortest_path(string start, string end)  {
    queue<Node> q;
    unordered_map<string, string> previous;
    unordered_map<string, int> distance;

    for (auto & node : nodes) {
        if (node.name == start) {
            q.push(node);
        }
    }

    distance[start] = 0;

    while (!q.empty()) {


        Node node = q.front();
        q.pop();


        if (node.name == end) {
            break;
        }

        for (auto & e : node.adj) {
            if (distance.count(e.dest) == 0) {
                distance[e.dest] = distance[node.name] + 1;
                previous[e.dest] = node.name;
                for (auto & n : nodes) {
                    if (n.name == e.dest) {
                        q.push(n);
                    }
                }
            }
        }
    }

    vector<string> path;
    string current = end;
    while (current != start) {
        path.insert(path.begin(), current);
        current = previous[current];
    }
    path.insert(path.begin(), start);
    for (int i = 0; i < path.size(); ++i) {
        if (i != path.size()-1) {
            cout << path[i] << " --- ";
        }
        else
            cout << path[i];
    }

    return path;
}











/*

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}



int Graph::dfs1(int v) {
    // show node order
    // cout << v << " ";
    int n = 1;
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            n += dfs1(w);
    }
    return n;
}


// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
// TODO
int Graph::outDegree(int v) {
    if (v < 1 || v > n) return -1;
    return nodes[v].adj.size();
}

// ..............................
// b) Devolvendo o grau... pesado
// TODO
int Graph::weightedOutDegree(int v) {
    if (v < 1 || v > n) return -1;
    int result = 0;
    for (auto i : nodes[v].adj) {
        result += i.weight;
    }
    return result;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    int counter = 0;
    for (int v=1; v<=n; v++)
        nodes[v].visited = false;
    for (int v=1; v<=n; v++)
        if (!nodes[v].visited ) {
            counter++;
            dfs(v);
        }
    return counter;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int max_result = 0;
    for (int v=1; v<=n; v++)
        nodes[v].visited = false;
    for (int v=1; v<=n; v++)
        if (!nodes[v].visited ) {
            int x = dfs1(v);
            if (x > max_result) {
                max_result = x;
            }
        }
    return max_result;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
list<int> Graph::topologicalSorting() {
    list<int> order;
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    return false;
}
*/
