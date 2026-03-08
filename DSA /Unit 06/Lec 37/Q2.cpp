Single File Programming Question
Problem Statement



John, a logistics manager, is tasked with finding the shortest delivery route between two warehouses in a city using Dijkstra's algorithm. The city's road network is represented as a graph, where intersections are nodes and roads are weighted edges. 



Help John determine the quickest route between the two warehouses based on the provided road network.

Input format :
The first line of input consists of an integer n, representing the number of intersections in the city.

The second line of input consists of an integer m, representing the number of roads connecting intersections.

The next m lines each contain three integers u, v, and w, where u and v are two intersections connected by a road of weight w.

The last two lines consist of integers source and destination, which represent the starting and destination intersections, respectively.

Output format :
If a path exists, the first line of output prints "Shortest path: " followed by the shortest path from the source to the destination, with each intersection separated by " -> ".

The second line prints "Shortest distance: " followed by the total distance of the shortest path.

If no path exists, output "No path found".



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following specifications:

1 ≤ n ≤ 100

1 ≤ m ≤ 100

0 ≤ u, v < n

0 ≤ w ≤ 100

0 ≤ s, d < n

Sample test cases :
Input 1 :
4
5
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
0
3
Output 1 :
Shortest path: 0 -> 1 -> 2 -> 3
Shortest distance: 6
Input 2 :
5
7
0 1 2
0 2 6
0 3 1
1 2 3
1 4 5
2 3 2
3 4 1
0
4
Output 2 :
Shortest path: 0 -> 3 -> 4
Shortest distance: 2
Input 3 :
3
2
0 1 5
1 2 3
0
2
Output 3 :
Shortest path: 0 -> 1 -> 2
Shortest distance: 8
Input 4 :
5
4
0 1 2
0 3 3
1 3 4
0 2 5
0
4
Output 4 :
No path found 



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source, destination;
    cin >> source;
    cin >> destination;

    const int INF = 1e9;
    vector<int> dist(n, INF), parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

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
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[destination] == INF) {
        cout << "No path found";
    } else {
        vector<int> path;
        for (int v = destination; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "Shortest path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i + 1 < path.size()) cout << " -> ";
        }
        cout << endl;
        cout << "Shortest distance: " << dist[destination];
    }

    return 0;
}
