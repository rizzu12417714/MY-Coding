Single File Programming Question
Problem Statement



Raja is given a map of cities represented as vertices and roads connecting these cities represented as directed edges with associated weights. His task is to find the shortest path from a specified starting city to all other cities using Dijkstra's algorithm.



Note: The given graph is a directed graph.

Input format :
The first line contains two integers n and m, separated by a space, where n represents the number of cities, and m represents the number of roads.

The next m lines describe the roads. Each line contains three integers, u, v, and w, separated by spaces. u is the starting city, v is the ending city, and w is the length of the road.

The last line contains an integer S, which is the starting city.

Output format :
The output consists of n-1 lines.



Each line contains one of the following two types of output:

If there is a reachable path from the starting city to the corresponding city, print: "City x: y units", where x is the city number and y is the shortest distance from the source city to city x.

If there is no path from the starting city to the corresponding city, print: "City x: Not reachable", where x is the city number.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ n ≤ 100

0 ≤ m ≤ (n) * (n - 1)

0 ≤ u, v < n

0 ≤ w ≤ INT_MAX (Maximum value of integer)

Sample test cases :
Input 1 :
4 4
0 1 5
0 2 3
1 3 2
2 3 3
1
Output 1 :
City 0: Not reachable
City 2: Not reachable
City 3: 2 units
Input 2 :
5 7
0 1 2
0 2 4
1 3 5
2 3 1
2 4 7
3 4 3
4 0 2
0
Output 2 :
City 1: 2 units
City 2: 4 units
City 3: 5 units
City 4: 8 units



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,long long>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int S;
    cin >> S;

    const long long INF = LLONG_MAX;
    vector<long long> dist(n, INF);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == S) continue;
        if (dist[i] == INF) {
            cout << "City " << i << ": Not reachable" << endl;
        } else {
            cout << "City " << i << ": " << dist[i] << " units" << endl;
        }
    }

    return 0;
}
