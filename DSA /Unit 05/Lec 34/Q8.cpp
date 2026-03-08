Single File Programming Question
Problem Statement



Smith is implementing a hash table using quadratic probing. He needs to insert a number into a hash table of size 7 and handle collisions
using quadratic probing. Help him implement the task.





FORMULA

The insertion of an element into the hash table is based on the following formula:

index = (hash(key) + i * i) % TABLE_SIZE where i starts from 1 and increments until an empty slot is found.

Input format :
The first line of input consists of an integer n representing the value to be inserted into the hash table.

Output format :
The first line of output prints: the hash table with each slot separated by a space, showing -1 for empty slots and the inserted number in its respective position.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 1000 (value to be inserted)

The hash table has a fixed size of 7.

Sample test cases :
Input 1 :
10
Output 1 :
-1 -1 -1 10 -1 -1 -1 
Input 2 :
7
Output 2 :
7 -1 -1 -1 -1 -1 -1




#include <bits/stdc++.h>
using namespace std;

int main() {
    const int TABLE_SIZE = 7;
    vector<int> table(TABLE_SIZE, -1);

    int n;
    cin >> n;

    int hashValue = n % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE) {
        int index = (hashValue + i * i) % TABLE_SIZE;
        if (table[index] == -1) {
            table[index] = n;
            break;
        }
        i++;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << table[i] << " ";
    }

    return 0;
}
