Single File Programming Question
Problem Statement



You are working on a project that involves analyzing the connectivity of a network. To do this, you need to implement a Breadth-First Search (BFS) algorithm for traversing a graph and printing the order in which vertices are visited.



You are given a network with V vertices and E edges. Each vertex is represented by a unique integer from 0 to V-1. The edges between vertices are represented in the form of an adjacency matrix adjList, where adjList[u][v] is 1 if there is an edge between vertex u and vertex v, and 0 otherwise.



You need to implement the BFS algorithm to traverse the network starting from vertex 0 and print the order in which vertices are visited.



Example



Input:

5 4

0 1

0 2 

0 3

2 4



Output: 

0 1 2 3 4



Explanation: 

The input represents a network with 5 vertices (0–4) and 4 edges connecting these vertices. 



The edges are as follows:

Edge between vertex 0 and vertex 1 (0 1)

Edge between vertex 0 and vertex 2 (0 2)

Edge between vertex 0 and vertex 3 (0 3)

Edge between vertex 2 and vertex 4 (2 4)

The BFS traversal starts from vertex 0. The algorithm explores all the neighbours of vertex 0 before moving on to their neighbours and so on. 



The order in which vertices are visited during the BFS traversal is:

Start from vertex 0 (0).

Explore its neighbours: vertex 1 and vertex 2 (0 1 2).

Explore the neighbour of vertex 2, which is vertex 4 (0 1 2 4).

Explore the neighbour of vertex 1, which is vertex 3 (0 1 2 4 3).

So, the BFS traversal starting from vertex 0 results in the sequence: 0 1 2 3 4 

This is the order in which the vertices are visited during the BFS traversal of the given network.

Input format :
The first line of input consists of two space-separated integers V and E, representing the number of vertices and edges in the network, respectively.

The following E lines contain two space-separated integers, u and v, representing an edge between vertex u and vertex v.

Output format :
The output prints the order in which vertices are visited during the BFS traversal, separated by spaces.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ V ≤ 1000 (number of vertices in the network)

0 ≤ E ≤ V*(V-1)/2 (number of edges in the network)

0 ≤ u, v < V (vertex numbers are between 0 and V-1)

The graph is a directed graph, and there can be multiple edges between the same pair of vertices.

The graph may contain self-loops (edges from a vertex to itself).

The graph may contain cycles.

The input graph is represented as an adjacency list.

Sample test cases :
Input 1 :
5 4
0 1
0 2 
0 3
2 4
Output 1 :
0 1 2 3 4 
Input 2 :
3 2
0 1
0 2
Output 2 :
0 1 2 





#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(V, false);
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return 0;
}
