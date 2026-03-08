Single File Programming Question
Problem statement﻿



Sarah has been tasked with developing a program to determine the shortest paths among nodes in a directed network represented as a graph containing nodes and weighted edges.



Her goal is to implement the Floyd-Warshall algorithm to compute the shortest path matrix for this directed network.

Input format :
The first line of input consists of an integer n, representing the number of nodes in the network.

The next n lines contain a space-separated integer, representing the adjacency matrix 'graph' of the network. Each integer is the weight of the edge from node i to node j.

Output format :
The output prints the shortest path matrix as 'n x n' integers, where each element graph[i][j] represents the shortest distance from node 'i' to node 'j'.

Print each row of the matrix on a new line, with elements separated by a space, and if no path exists, 999 will be displayed.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ n ≤ 100

0 ≤ weight of edge ≤ 999

graph[i][i] = 0

Sample test cases :
Input 1 :
4
0 3 999 4
8 0 2 999
5 999 0 1
2 999 999 0
Output 1 :
0 3 5 4 
5 0 2 3 
3 6 0 1 
2 5 7 0 
Input 2 :
3
0 1 2
3 0 4
5 6 0
Output 2 :
0 1 2 
3 0 4 
5 6 0 
Input 3 :
4
0 5 999 10
999 0 3 999
999 999 0 1 
999 999 999 0
Output 3 :
0 5 8 9 
999 0 3 4 
999 999 0 1 
999 999 999 0 



#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != 999 && graph[k][j] != 999 &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
