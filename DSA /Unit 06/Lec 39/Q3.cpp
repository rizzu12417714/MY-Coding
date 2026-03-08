Single File Programming Question
Problem Statement



A traveler wants to find the shortest routes from their home city to all other cities on a map. Some roads have tolls (positive weights), while some offer discounts (negative weights). Since the map may have such roads, the traveler uses the Bellman-Ford algorithm to find the shortest paths while ensuring no problematic loops exist.

Input format :
The first line contains an integer V, representing the number of cities (vertices) in the map.

The second line contains an integer E, representing the number of roads (edges) in the map.

The next E lines each contain three space-separated integers u, v, w, representing a road from city u to city v with travel cost w (where w can be negative).

The last line contains an integer src, the index of the traveler’s home city, which is always taken as 0.

Output format :
The first line of output prints "Vertex Distance from Source"

For each city i, print the index of the city and its shortest distance from the source city src, separated by a tab space using the mentioned format(format: "%d \t\t %d\n")

If there is a negative weight cycle in the graph, print "Graph contains negative weight cycle" and stop further output.



Refer to the sample input and output for format specifications.

Code constraints :
1 ≤ V ≤ 103

0 ≤ E ≤ 104

0 ≤ u, v < V

-103 ≤ w ≤ 103

0 ≤ src < V

Sample test cases :
Input 1 :
5 
8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0
Output 1 :
Vertex Distance from Source
0 		 0
1 		 -1
2 		 2
3 		 -2
4 		 1
Input 2 :
4
4
0 1 1
0 2 4
1 2 2
2 3 1
0
Output 2 :
Vertex Distance from Source
0 		 0
1 		 1
2 		 3
3 		 4




#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;

    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (auto &e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto &e : edges) {
        int u, v, w;
        tie(u, v, w) = e;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle";
            return 0;
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }

    return 0;
}
