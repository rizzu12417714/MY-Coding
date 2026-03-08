Single File Programming Question
Problem Statement



Arjun works as a systems engineer designing routing modules for a distributed communication network. Each connection between nodes represents a one-way communication channel with an associated transmission time. Using the Floyd–Warshall algorithm, Arjun must determine the shortest possible time to send a message from a given source node to a target node.



Help him compute this minimum communication time.

Input format :
The first line consists of two integers, an integer n, and an integer m, representing the number of nodes in the network and the number of directed edges.

The next m lines each contain three integers u, v, w, representing a directed edge from node u to node v with weight (time) w.

The final line contains two integers, source and sink, representing the starting and destination nodes.

Output format :
The output prints "Nodes are unreachable." if no valid path exists between the source and sink.

Otherwise, print a single integer, representing the shortest communication time between the given nodes.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 100

0 ≤ m ≤ n × (n − 1)

0 ≤ u, v < n

1 ≤ w ≤ 109

Sample test cases :
Input 1 :
3 3
0 1 1
1 2 2
0 2 5
2 1
Output 1 :
Nodes are unreachable.
Input 2 :
4 5
0 1 2
1 2 3
2 3 4
0 2 5
1 3 6
0 3
Output 2 :
8
Input 3 :
3 2
0 1 2
1 2 3
0 1
Output 3 :
2




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    const long long INF = 1e18;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    int source, sink;
    cin >> source >> sink;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    if (dist[source][sink] == INF)
        cout << "Nodes are unreachable.";
    else
        cout << dist[source][sink];

    return 0;
}
