Single File Programming Question
Problem Statement



You are designing a navigation system for a city with multiple interconnected cities. The cities are represented as vertices, and the connections between cities are represented as edges in a graph.



Your task is to implement a program that performs a breadth-first search (BFS) traversal on the graph, starting from a given source city, and outputs the order in which the cities are visited.

Input format :
The first line contains two integers, numCities and numConnections, separated by a space, representing the total number of cities and the number of connections between cities.

The next numConnections lines consist of the two integers a and b each, separated by a space, representing a connection from city a to city b.

The last line contains a single integer source representing the source city for the BFS traversal.

Output format :
The output consists of a single line containing the order in which the cities are visited during the BFS traversal, separated by a space.



Refer to the sample output for the formatting specifications.

Code constraints :
The number of cities, numCities, will be an integer between 1 and 100.

The number of connections, numConnections, will be an integer between 0 and 10,000.

Each connection will be between valid city indices, ranging from 0 to numCities-1.

The source city, source, will be a valid city index in the range from 0 to numCities-1.

Sample test cases :
Input 1 :
6 7
0 1
0 2
1 3
1 4
2 4
3 5
4 5
0
Output 1 :
0 1 2 3 4 5 
Input 2 :
3 3
0 1
1 2
2 0
2 
Output 2 :
2 0 1 



#include <iostream>
#include <queue>
using namespace std;
void BFS(int graph[100][100], int numCities, int source) {
    bool visited[100] = {false};
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while (!q.empty()) {
        int currentCity = q.front();
        q.pop();
        cout << currentCity << " ";
        for (int i = 0; i < numCities; i++) {
            if (graph[currentCity][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int numCities, numConnections;
    cin >> numCities >> numConnections;
    int graph[100][100] = {0};
    for (int i = 0; i < numConnections; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    int source;
    cin >> source;
    BFS(graph, numCities, source);
    return 0;
}
