Single File Programming Question
Problem Statement



Liam is working on a network routing system for a new communication platform. He needs to calculate the shortest paths between nodes in a graph where the edges represent communication links. However, he needs to check for negative weight cycles, which could indicate routing issues. 



Can you help Liam implement the Bellman-Ford algorithm to find the shortest paths and detect negative weight cycles in the system?

Input format :
The first line of input contains two integers V and E, representing the number of vertices (nodes) and edges in the graph.

The next E lines each contain three integers u, v, and w, representing an edge from vertex u to vertex v with weight w. (1-based indexing)

The last line contains an integer s, the source vertex (1-based indexing).

Output format :
If no negative weight cycle is detected, the output should print the shortest distance from the source vertex to all other vertices, separated by spaces.

If a negative weight cycle is detected, print "Negative Cycle Detected".



Refer to the sample input and output for format specifications.

Code constraints :
1 ≤ V ≤ 100

1 ≤ E ≤ 1000

1 ≤ u, v ≤ V (1-based indexing)

-104 ≤ w ≤ 104 (Edge weights can be negative)

1 ≤ s ≤ V (Source vertex in 1-based indexing)

Sample test cases :
Input 1 :
5 8
1 2 5
1 3 2
2 3 2
2 4 1
3 4 3
4 5 1
3 5 5
5 2 -2
1
Output 1 :
0 4 2 5 6 
Input 2 :
4 5
1 2 1
2 3 -2
3 4 -3
4 2 -1
1 4 5
1
Output 2 :
Negative Cycle Detected




#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> u(E), v(E);
    vector<long long> w(E);

    for (int i = 0; i < E; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; 
        v[i]--;
    }

    int s;
    cin >> s;
    s--;

    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(V, INF);
    dist[s] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    for (int j = 0; j < E; j++) {
        if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            cout << "Negative Cycle Detected";
            return 0;
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}
