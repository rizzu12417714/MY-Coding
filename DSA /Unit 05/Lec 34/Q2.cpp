Single File Programming Question
Problem Statement



Arjun is managing a student record system where each student ID must be placed into a hash table. To avoid collisions, he uses double hashing, which applies two hash functions to find the correct position for the key. After inserting the given student ID, Arjun needs to display the index at which it gets stored.



Help him to implement the task.



FORMULA:

Primary hash function: h1(key) = key % TABLE_SIZE

Secondary hash function: h2(key) = 1 + (key % (TABLE_SIZE - 1))

Double hashing position formula: position = (h1(key) + i * h2(key)) % TABLE_SIZE

where i increments for each collision.

Input format :
The first line of input consists of an integer key representing the student ID to be inserted into the hash table.

Output format :
The first line of output prints: <position>

where <position> is the index where the key gets inserted in the hash table.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

TABLE_SIZE = 9

key is an integer

Key insertion uses double hashing for collision resolution

Sample test cases :
Input 1 :
18
Output 1 :
0
Input 2 :
26
Output 2 :
8




#include <bits/stdc++.h>
using namespace std;

int main() {
    const int TABLE_SIZE = 9;

    int key;
    cin >> key;

    int h1 = ((key % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
    int h2 = 1 + ((key % (TABLE_SIZE - 1)) + (TABLE_SIZE - 1)) % (TABLE_SIZE - 1);

    int i = 0;
    int position = (h1 + i * h2) % TABLE_SIZE;

    cout << position;
    return 0;
}
