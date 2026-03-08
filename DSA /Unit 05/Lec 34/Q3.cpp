Single File Programming Question
Problem Statement



Arjun is a database administrator who needs to store a set of unique ID numbers into a fixed-size hash table for quick retrieval. When a collision occurs (two IDs hash to the same index), he must use quadratic probing to find the next available slot. Help him to implement the task.



FORMULA

Hash Value Calculation: hv = arr[i] % tsize
Quadratic Probing (on collision): new_index = (hv + j * j) % tsize where j = 1, 2, 3, ... until an empty slot is found.
Input format :
The first line of input consists of an integer n, representing the number of elements to be inserted.

The second line of input consists of n space-separated integers arr, representing the elements to be inserted into the hash table.

The third line of input consists of an integer tsize, representing the size of the hash table.

Output format :
The first line of output prints: "Hash table after quadratic probing: " followed by tsize space-separated integers representing the final state of the hash table (with -1 indicating empty slots).



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 100

0 ≤ arr[i] ≤ 10000

1 ≤ tsize ≤ 100

Sample test cases :
Input 1 :
5
12 15 20 25 30
7
Output 1 :
Hash table after quadratic probing: -1 15 30 -1 25 12 20 
Input 2 :
3
13 16 18
5
Output 2 :
Hash table after quadratic probing: -1 16 -1 13 18



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tsize;
    cin >> tsize;

    vector<int> table(tsize, -1);

    for (int i = 0; i < n; i++) {
        int hv = arr[i] % tsize;

        if (table[hv] == -1) {
            table[hv] = arr[i];
        } else {
            int j = 1;
            while (j < tsize) {
                int new_index = (hv + j * j) % tsize;
                if (table[new_index] == -1) {
                    table[new_index] = arr[i];
                    break;
                }
                j++;
            }
        }
    }

    cout << "Hash table after quadratic probing: ";
    for (int i = 0; i < tsize; i++) {
        cout << table[i] << " ";
    }

    return 0;
}
