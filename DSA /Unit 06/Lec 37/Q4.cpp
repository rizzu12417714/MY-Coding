Single File Programming Question
Problem Statement



Implement a program to find the shortest path from a source city to a destination city in a city network represented by a weighted graph. The graph is defined by an adjacency matrix, where each entry graph[i][j] represents the cost of a flight from city i to city j.



Implement Dijkstra's algorithm to find the shortest path from a given source city to a destination city.

Input format :
The first line consists of an integer n, representing the number of cities in the network.

The next n lines contain n space-separated integers, representing the costs of flights between cities as an adjacency matrix.

The next two lines contain two integers s and d, representing the source and destination cities, respectively.

Output format :
The first line prints "Shortest path: " followed by the shortest distance between source and destination.

The second line prints "Path: " followed by the path from the source to the destination city in the format: "s -> intermediate1 -> intermediate2 -> ... -> d".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 100

0 ≤ graph[i][j] ≤ 100

0 ≤ s, d < n

Sample test cases :
Input 1 :
4
0 2 4 1
2 0 1 5
4 1 0 3
1 5 3 0
0
3
Output 1 :
Shortest path: 1
Path: 0 -> 3
Input 2 :
3
0 2 0
2 0 1
0 1 0
1
2
Output 2 :
Shortest path: 1
Path: 1 -> 2




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int s, d;
    cin >> s;
    cin >> d;

    const int INF = 1e9;
    vector<int> dist(n, INF), parent(n, -1);
    vector<bool> visited(n, false);

    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    cout << "Shortest path: " << dist[d] << endl;

    vector<int> path;
    for (int v = d; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i + 1 < path.size()) cout << " -> ";
    }

    return 0;
}
