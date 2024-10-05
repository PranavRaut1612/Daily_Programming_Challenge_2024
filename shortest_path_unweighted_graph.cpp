#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& graph, int start, int end) {
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<int> distance(V, INT_MAX);
    vector<int> parent(V, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                distance[v] = distance[u] + 1;
                parent[v] = u;
            }
        }
    }

    vector<int> path;
    int curr = end;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int V = 5;
    vector<vector<int>> graph(V);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[3].push_back(4);

    int start = 0;
    int end = 4;

    vector<int> path = shortestPath(graph, start, end);

    cout << "Shortest path: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    cout << "Number of edges in the shortest path: " << path.size() - 1 << endl;

    return 0;
}