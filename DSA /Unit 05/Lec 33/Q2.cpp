Single File Programming Question
Problem Statement



Shafir is working on implementing a hash table with linear probing. He is tasked with inserting several keys into the hash table and then printing the final state of the table. The table should display the inserted keys and the empty slots after all insertions.



Help him implement the task.

Input format :
The first line of input consists of an integer n, representing the number of keys to insert into the hash table.

The second line of input consists of n integers, representing the keys to be inserted into the hash table

Output format :
For each index of the hash table, if a key is present, the output prints: "Index <i>: <key>"

If an index is empty, the output prints: "Index <i>: Empty"



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

hash table size = 7

1 ≤ n ≤ 100

-106 ≤ key ≤ 106

Sample test cases :
Input 1 :
5
10 20 30 40 50
Output 1 :
Index 0: Empty
Index 1: 50
Index 2: 30
Index 3: 10
Index 4: Empty
Index 5: 40
Index 6: 20
Input 2 :
6
10 20 30 40 50 60
Output 2 :
Index 0: Empty
Index 1: 50
Index 2: 30
Index 3: 10
Index 4: 60
Index 5: 40
Index 6: 20




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int TABLE_SIZE = 7;
    vector<long long> table(TABLE_SIZE, LLONG_MIN);

    for (int i = 0; i < n; i++) {
        long long key;
        cin >> key;

        int index = ((key % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;

        while (table[index] != LLONG_MIN) {
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = key;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == LLONG_MIN)
            cout << "Index " << i << ": Empty\n";
        else
            cout << "Index " << i << ": " << table[i] << "\n";
    }

    return 0;
}
