Single File Programming Question
Problem Statement



You are developing a social network analysis tool that requires traversing a directed graph to identify connected components. Your task is to implement a Depth First Search (DFS) algorithm that performs a traversal of the graph starting from a given user's profile. The graph represents user connections, where each user is represented as a vertex and the connections between users are represented as directed edges.



Your program should take the number of users (vertices) and the number of connections (edges) as input. Then, it should read the connection details and construct the graph. Finally, it should perform a DFS traversal starting from a specified user's profile and output the order of visited user profiles during the traversal.



Example



Input 

6 6

0 1

0 2

1 2

2 0

2 3

3 3

2



Output 

2 0 1 3 



Explanation

The start vertex for the DFS traversal is 2.



Explanation of the DFS traversal:

Starting from vertex 2, it is visited and marked as visited.

Vertex 2 is printed (cout << v << " ";), so the output is "2 ".

Checking the adjacency list of vertex 2, the neighbors are 0 and 3.

Vertex 0 is not visited, so DFS is recursively called with vertex 0.

Vertex 0 is visited and marked as visited.

Vertex 0 is printed, so the output is "2 0 ".

Vertex 0 has a neighbor, 1. Vertex 1 is not visited, so DFS is recursively called with vertex 1.

Vertex 1 is visited and marked as visited.

Vertex 1 is printed, so the output is "2 0 1 ".

Vertex 1 has a neighbor, 2. Vertex 2 is already visited, so it is skipped.

Vertex 3 is visited and marked as visited.

Vertex 3 is printed, so the final output is "2 0 1 3 ".

Therefore, the DFS traversal starting from vertex 2 in the given graph produces the output "2 0 1 3 ".

Input format :
The first line of input contains two integers, n and m, separated by a space, representing the total number of users (vertices) and the number of connections (edges) in the network, respectively.

Each of the next m lines contains two space-separated integers, u and v, representing a directed connection from user u to user v.

The last line contains a single integer, s, representing the ID of the source user profile for the DFS traversal.

Output format :
The output displays a single line containing the user IDs in the order they were visited during the DFS traversal, separated by a space.



Refer to the sample output for formatting specifications.

Code constraints :
The number of users (vertices) in the network will be between 1 and 10.

The number of connections (edges) between users will be between 0 and 102.

Each user is represented by a unique integer ID ranging from 0 to (n-1), where n is the total number of users.

The input graph may contain self-loops and duplicate connections.

The graph is a directed graph, meaning that connections have a specific direction.

Define the maximum number of vertices as 100.

Sample test cases :
Input 1 :
6 6
0 1
0 2
1 2
2 0
2 3
3 3
2
Output 1 :
2 0 1 3 
Input 2 :
7 6
0 1
0 2
1 3
1 4
2 5
2 6
0
Output 2 :
0 1 3 4 2 5 6 



#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int s;
    cin >> s;

    vector<bool> visited(n, false);
    dfs(s, adj, visited);

    return 0;
}
