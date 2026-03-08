Single File Programming Question
Problem Statement



You are given a bi-directional network with n vertices, where each vertex is labeled from 0 to n - 1. The connections between the vertices are represented by a 2D integer array of edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Each vertex pair is connected by at most one edge, and no vertex has an edge to itself.



Your task is to find the length of the shortest cycle in the network using the Breadth-First Search (BFS) algorithm. A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.



Write a program that takes the number of vertices, n, and the list of edges as input and uses BFS to find the length of the shortest cycle in the network. If no cycle exists, the program should output -1.



Example 1:



Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]

Output: 3

Explanation:

The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 

Input format :
The first line contains an integer n representing the number of nodes in the graph.

The second line contains an integer m representing the number of edges in the graph.

The next m lines contain the edges of the graph. Each line contains two space-separated integers u and v, representing a directed edge from node u to node v.

Output format :
The output prints "The length of the shortest cycle is: ", followed by a single integer representing the length of the shortest cycle in the network.

If no cycle exists, print "The length of the shortest cycle is: -1".



Refer to the sample output for format specifications.

Code constraints :
2 ≤ n ≤ 1000

1 ≤ edges.length ≤ 1000

edges[i].length == 2

0 <= ui, vi < n

ui != vi

There are no repeated edges.

Sample test cases :
Input 1 :
7
7
0 1
1 2
2 0
3 4
4 5
5 6
6 3
Output 1 :
The length of the shortest cycle is: 3
Input 2 :
4
2
0 1 
0 2
0 3
Output 2 :
The length of the shortest cycle is: -1




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = INT_MAX;

    for (int start = 0; start < n; start++) {
        vector<int> dist(n, -1);
        vector<int> parent(n, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (parent[u] != v) {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
    }

    if (ans == INT_MAX)
        cout << "The length of the shortest cycle is: -1";
    else
        cout << "The length of the shortest cycle is: " << ans;

    return 0;
}
