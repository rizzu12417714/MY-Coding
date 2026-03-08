Single File Programming Question
Problem Statement



You are working on a social networking platform that allows users to connect with each other through friendship connections. 



Your task is to build a feature that detects if there are any cycles in the friend network using the Depth-First Search (DFS) algorithm. A cycle in the friend network indicates that there is a group of users who are interconnected with each other, forming a closed loop.

Input format :
The first line of input contains two integers separated by a space: N (the number of users) and E (the number of friendship connections).

The next E lines contain two integers separated by a space, representing a friendship connection between two users.

Output format :
If the friend network contains at least one cycle, output "Graph contains cycle"

Otherwise, output "Graph doesn't contain cycle"



Refer to the sample output for formatting specifications.

Code constraints :
The social network consists of N users, numbered from 0 to N-1.

Each user can have multiple friendships with other users, but there are no duplicate friendships.

The number of users (N) is between 2 and 100, inclusive.

The number of friendship connections (E) is between 1 and N*(N-1)/2, inclusive.

Sample test cases :
Input 1 :
4 3
0 1
1 2
2 3
Output 1 :
Graph doesn't contain cycle
Input 2 :
4 4
0 1
0 2
1 2
2 3
 
Output 2 :
Graph contains cycle
Input 3 :
5 6
0 1
1 2
2 3
3 4
4 0
2 4
Output 3 :
Graph contains cycle




#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u, adj, visited))
                return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<int>> adj(N);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                cout << "Graph contains cycle";
                return 0;
            }
        }
    }

    cout << "Graph doesn't contain cycle";
    return 0;
}
