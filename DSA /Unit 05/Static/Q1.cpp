Single File Programming Question
Problem Statement



Ravi is building a basic hash table to manage student roll numbers for quick lookup. He decides to use Linear Probing to handle collisions.



Implement a hash table using linear probing where:

The hash function is: index = roll_number % table_size
On collision, check subsequent indexes (i+1, i+2, ...) until an empty slot is found.


You need to:

Insert a list of n student roll numbers into the hash table.
Print the final state of the hash table. If a slot is empty, print -1.
Input format :
The first line of the input contains two integers n and table_size, where n is the number of roll numbers to be inserted, and table_size is the size of the hash table.

The second line contains n space-separated integers representing the roll numbers to insert into the hash table.

Output format :
The output should print a single line with table_size space-separated integers representing the final state of the hash table after all insertions.

If any slot remains unoccupied, it should be represented as -1.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ table_size

1 ≤ table_size ≤ 100

1 ≤ roll_number ≤ 1000

Sample test cases :
Input 1 :
4 7
50 700 76 85
Output 1 :
700 50 85 -1 -1 -1 76 
Input 2 :
3 5
11 22 33
Output 2 :
-1 11 22 33 -1



  



#include <iostream>
using namespace std;
#define MAX 100

void initializeTable(int table[], int table_size) {
    for (int i = 0; i < table_size; i++) {
        table[i] = -1;
    }
}

void insertIntoHashTable(int table[], int table_size, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int index = key % table_size;

        while (table[index] != -1) {
            index = (index + 1) % table_size;
        }
        table[index] = key;
    }
}

void printTable(int table[], int table_size) {
    for (int i = 0; i < table_size; i++) {
        cout << table[i] << " ";
    }
}

int main() {
    int n, table_size;
    cin >> n >> table_size;

    int arr[MAX];
    int table[MAX];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    initializeTable(table, table_size);
    insertIntoHashTable(table, table_size, arr, n);
    printTable(table, table_size);

    return 0;
}
