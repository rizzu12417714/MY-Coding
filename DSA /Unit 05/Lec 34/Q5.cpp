Single File Programming Question
Problem Statement



Labuschagne is implementing a hash table with double hashing for collision resolution. He needs to insert several keys into the hash table, search for a specific key, and display the contents of the table. If the key is found, its index should be displayed; otherwise, "value not found" should be printed. Empty positions should be marked as 0.



Help him implement the task.



FORMULA

Hash Function 1: hkey = key % TABLE_SIZE

Hash Function 2: hash2 = 7 - (key % 7)

Collision Resolution: index = (hkey + i * hash2) % TABLE_SIZE

Search: Check if the key exists and print its position or "value not found".

Input format :
The first line of input consists of integer n, the number of keys to be inserted.

The next n lines contain the keys to be inserted.

The next line contains the key to search for in the hash table.

Output format :
The first line prints: "value is found at index <index>" or "value is not found".

Then, display the hash table: "Element at position <index>: <value>", with empty positions marked as 0.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 10 (number of keys to insert)

The key values are integers.

TABLE_SIZE = 10

Sample test cases :
Input 1 :
5
10 20 30 40 50
25
Output 1 :
value is not found
Element at position 0: 10
Element at position 1: 20
Element at position 2: 40
Element at position 3: 0
Element at position 4: 0
Element at position 5: 30
Element at position 6: 50
Element at position 7: 0
Element at position 8: 0
Element at position 9: 0
Input 2 :
4
5 10 15 20
10
Output 2 :
value is found at index 0
Element at position 0: 10
Element at position 1: 15
Element at position 2: 20
Element at position 3: 0
Element at position 4: 0
Element at position 5: 5
Element at position 6: 0
Element at position 7: 0
Element at position 8: 0
Element at position 9: 0


#include <bits/stdc++.h>
using namespace std;

int main() {
    const int TABLE_SIZE = 10;
    vector<int> table(TABLE_SIZE, 0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;

        int hkey = ((key % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
        int hash2 = 7 - (key % 7);
        int j = 0;
        int index;

        while (true) {
            index = (hkey + j * hash2) % TABLE_SIZE;
            if (table[index] == 0) {
                table[index] = key;
                break;
            }
            j++;
        }
    }

    int searchKey;
    cin >> searchKey;

    bool found = false;
    int foundIndex = -1;

    int hkey = ((searchKey % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
    int hash2 = 7 - (searchKey % 7);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = (hkey + i * hash2) % TABLE_SIZE;
        if (table[index] == searchKey) {
            found = true;
            foundIndex = index;
            break;
        }
        if (table[index] == 0)
            break;
    }

    if (found)
        cout << "value is found at index " << foundIndex << "\n";
    else
        cout << "value is not found\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Element at position " << i << ": " << table[i] << "\n";
    }

    return 0;
}
