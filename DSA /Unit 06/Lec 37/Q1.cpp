Single File Programming Question
Problem Statement



Anu is given a weighted, undirected, and connected graph with V vertices and E edges represented as an adjacency list. They are also given a source vertex S.  

The task is to find the shortest distance from the source vertex S to all other vertices in the graph using Dijkstra's algorithm.

Input format :
The first line contains an integer V representing the number of vertices in the graph.

The second line contains an integer E representing the number of edges in the graph.

The next E lines contain three integers each: from, to, and weight, denoting an edge between vertices from and to with the given weight.

The last line contains an integer S representing the source vertex.

Output format :
The output prints "Shortest distances from vertex S to all other vertices: " followed by the shortest distances from the source vertex S to all other vertices in the graph, separated by a space.



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases will fall under the following constraints:

1 ≤ V ≤ 100

0 ≤ E ≤ V * (V - 1) / 2

0 ≤ S < V

0 ≤ from, to < V

0 ≤ weight ≤ 100

Sample test cases :
Input 1 :
2
1
0 1 9
0
Output 1 :
Shortest distances from vertex 0 to all other vertices: 0 9 
Input 2 :
3 
3
0 1 1
0 2 6
1 2 3
2
Output 2 :
Shortest distances from vertex 2 to all other vertices: 4 3 0


#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int S;
    cin >> S;

    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from vertex " << S << " to all other vertices: ";
    for (int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}
