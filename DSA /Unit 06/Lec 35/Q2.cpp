Single File Programming Question
Problem Statement



You are developing a social networking platform where users can connect with each other. 
To enhance the user experience, you want to implement a feature that suggests connections to
users based on a lexicographical order traversal of the user network.



You are given a directed graph, represented as a set of edges. Each edge connects two vertices in the graph.
 Your task is to implement a program that performs a lexicographic
Breadth-First Search (BFS) traversal on the graph, starting from a specified source vertex.
The program should print the visited vertices in lexicographic order..



Your task is to traverse the user network starting from the source 
user S using BFS and print the visited users in lexicographical order.
Lexicographical order refers to the order in which the users would appear when sorted alphabetically.



Example



 Input:

10

10

a y

a z

a p

p c

p b

y m

y l

z h

z g

z i

a



Output

a p y z b c l m g h i 



Explanation



In this test case, the graph has the following structure:



a -> y, z, p

p -> c, b

y -> m, l

z -> h, g, i





Input format :
The first line contains an integer N, representing the number of users in the network.

The second line contains an integer M, representing the number of connections between users.

The next M lines contain two characters, u and v, each representing a connection between user u and user v.

The last line contains a character S, representing the source user for the traversal.

Output format :
The output displays a single line containing the vertices visited during the lexicographic BFS traversal, separated by a space.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ N ≤ 26 (number of users, represented by lowercase English letters from 'a' to 'z')

1 ≤ M ≤ N * (N-1) / 2 (maximum possible connections)

'a' ≤ S ≤ 'z' (source user)

Each user (node) is represented by a distinct lowercase English letter.

The graph is undirected, and there are no self-loops or multiple edges between users.

The connections are unique and valid, i.e., there are no duplicate connections, and all users in a connection exist in the network.

Sample test cases :
Input 1 :
10
10
a y
a z
a p
p c
p b
y m
y l
z h
z g
z i
a
Output 1 :
a p y z b c l




#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    map<char, vector<char>> adj;
    for (int i = 0; i < M; i++) {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (auto &p : adj) {
        sort(p.second.begin(), p.second.end());
    }

    char S;
    cin >> S;

    set<char> visited;
    queue<char> q;

    visited.insert(S);
    q.push(S);

    while (!q.empty()) {
        char u = q.front();
        q.pop();
        cout << u << " ";

        for (char v : adj[u]) {
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                q.push(v);
            }
        }
    }

    return 0;
}
