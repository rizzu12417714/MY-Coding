Single File Programming Question
Problem Statement



Sarah is working on a mapping project for a city, where intersections (vertices) are connected by one-way streets (edges). She needs to explore the city's streets using Depth First Search (DFS) to find all the intersections reachable from a given starting point.



Your task is to implement the DFS algorithm to traverse the city's street network, starting from a given intersection.

Input format :
The first line contains two integers n and e, where n represents the number of intersections (vertices), and e represents the number of streets (edges) in the city.

The next e lines contain two integers v and w, representing an edge between intersection v and intersection w.

The last line contains a single integer s, the starting intersection for the DFS traversal.

Output format :
The output should display the order in which the intersections are visited during the DFS traversal, starting from the given intersection s.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ vertices ≤ 10.

0 ≤ edges ≤ 100.

Define the maximum number of vertices is 100.

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
Input 3 :
4 6
0 1
0 2
1 2
2 0
2 3
3 3
1
Output 3 :
1 2 0 3 
Input 4 :
4 6
0 1
0 2
1 2
2 0
2 3
3 3
2
Output 4 :
2 0 1 3 


#include <iostream>
#include <vector>
using namespace std;
const int MAX_VERTICES = 100;
struct Graph {
    vector<int> visited;
    vector<vector<int>> adj;

    Graph(int n) {
        visited.assign(n, 0);
        adj.assign(n, vector<int>(n, 0));
    }

    void addEdge(int v, int w) {
        adj[v][w] = 1;
    }

    void DFS(int v) {
        visited[v] = 1;
        cout << v << " ";

        for (int i = 0; i < adj.size(); i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                DFS(i);
            }
        }
    }
};

int main() {
    int n, e;
    cin >> n >> e;

    Graph g(n);

    int v, w;
    for (int i = 0; i < e; i++) {
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int startVertex;
    cin >> startVertex;

    g.DFS(startVertex);

    return 0;
}
