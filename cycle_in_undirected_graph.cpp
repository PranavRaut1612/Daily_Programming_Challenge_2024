#include <iostream>
#include <vector>
using namespace std;

bool isCyclicUtil(int v, vector<bool>& visited, int parent, const vector<vector<int>>& graph) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            if (isCyclicUtil(neighbor, visited, v, graph)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool isCyclic(int V, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(V);
    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, -1, graph)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    
    if (isCyclic(V, edges)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph doesn't contain a cycle" << endl;
    }

    return 0;
}
