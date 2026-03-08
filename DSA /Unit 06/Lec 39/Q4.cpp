Single File Programming Question
Problem Statement



Harsha is planning a vacation and wants to optimize her flight schedule to minimize travel costs. She has a list of airports and the cost of flying between each pair of airports.



Additionally, she has a limited budget for the trip. Your task is to implement the Bellman-Ford algorithm to find the cheapest route from a starting airport to a destination airport that does not exceed the budget. If no route exists within the budget, your program should indicate that the trip is not feasible.

Input format :
The first line contains two integers N and M — the number of airports and flights.
The next M lines each contain three space-separated integers:
u v cost — a flight from airport u to airport v with the given cost.
The next line contains two integers: S and D — the starting and destination airports.
The last line contains an integer B — the available budget.
Output format :
If there exists a route from S to D with total cost ≤ B:

Shortest distance from S to D: X



If no such route exists within the budget:

No feasible path within budget



Here, X is the total cost of the cheapest route from S to D that does not exceed the budget.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N, M ≤ 10

0 ≤ u, v < N

1 ≤ cost ≤ 10

0 ≤ S, D < N

1 ≤ B ≤ 20



Sample test cases :
Input 1 :
4 5
0 1 5
0 2 3
1 2 2
2 3 7
1 3 10
0 3
11
Output 1 :
Shortest distance from 0 to 3: 10
Input 2 :
5 6
0 1 3
0 2 6
1 2 2
1 3 4
2 4 5
3 4 1
1 4
6
Output 2 :
Shortest distance from 1 to 4: 5





#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({u, v, cost});
    }

    int S, D;
    cin >> S >> D;

    int B;
    cin >> B;

    const int INF = 1e9;
    vector<int> dist(N, INF);
    dist[S] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (auto &e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    if (dist[D] != INF && dist[D] <= B) {
        cout << "Shortest distance from " << S << " to " << D << ": " << dist[D];
    } else {
        cout << "No feasible path within budget";
    }

    return 0;
}
