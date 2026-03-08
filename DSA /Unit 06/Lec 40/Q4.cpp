Single File Programming Question
Problem Statement



You are working as a software engineer in a city administration that aims to optimize the transportation network of a city with multiple landmarks. The landmarks include parks, museums, shopping malls, and educational institutions. Your task is to develop a program that calculates the shortest distances between all pairs of landmarks using the Floyd-Warshall Algorithm. 



This information will be used by the city administration to plan transportation infrastructure improvements, including road expansions and public transportation routes, with the goal of providing efficient routes for residents and tourists.



Example:

Input: 

The input represents the size N = 4

graph[][] = { {0,  5, 999, 10},

                {999, 0, 3, 999},

                {999, 999, 0, 1},

                {999, 999, 999, 0} }

which represents the following graph.

       10

   (0)——->(3)

    |       /|\

   5 |        | 1

    |        |  

    \|/       |

   (1)——->(2)

       3 

Output:

Shortest distance matrix:

  0    5   8    9

 INF   0   3    4

 INF   INF  0    1 

 INF   INF  INF  0



Explanation: For the given input, the program displays the shortest distance matrix.

Input format :
The first line contains an integer representing the total number of landmarks (V) in the city.

The subsequent V lines contain V space-separated integers, representing the distances (in some suitable unit) between the landmarks.

If there is no direct connection between two landmarks, the value "INF" (represented as 999) is used to indicate an infinite distance.

Output format :
The output consists of the following:



V lines, each containing V space-separated integers representing the shortest distances between every pair of landmarks. If there is no direct path between two landmarks, the value "INF" is printed.



Refer to the sample input and output formatting specifications.

Code constraints :
The number of landmarks in the city will not exceed 10.

The distances between landmarks will be represented as non-negative integers, with a maximum value of 999.

Sample test cases :
Input 1 :
4
0 5 999 10
999 0 3 999
999 999 0 1
999 999 999 0
Output 1 :
0 5 8 9 
INF 0 3 4 
INF INF 0 1 
INF INF INF 0 




#include <bits/stdc++.h>
using namespace std;

int main() {
    int V;
    cin >> V;

    const int INF = 999;
    vector<vector<int>> dist(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
