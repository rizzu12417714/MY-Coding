Single File Programming Question
Problem Statement



Monisha is working on a project where she needs to store an array of integers into a hash table. The hash table uses quadratic probing to handle collisions. She needs to insert each integer into the table, ensuring that if a collision occurs, quadratic probing is used to find the next available position. After inserting all integers, she needs to print the final state of the table.



Help her implement the task.



FORMULA

The formula used to calculate the hash table index is: index = (key + j * j) % TABLE_SIZE,

where key is the array element, j is the number of collisions that have occurred, and TABLE_SIZE is the size of the table.

Input format :
The first line of input consists of an integer N, the number of elements in the array.

The second line contains N integers, which represent the elements of the array to be inserted into the hash table.

Output format :
The first line of output prints the elements of the hash table, where each element is either the value stored at that index or -1 if the index is empty.

Code constraints :
The given test cases fall under the following constraints:

N (number of elements in the array) is an integer where 1 <= N <= 10.

Each array element is an integer.

The hash table size L is fixed at 7.

Sample test cases :
Input 1 :
4
11 13 17 19
Output 1 :
-1 -1 -1 17 11 19 13 
Input 2 :
3
9 16 25
Output 2 :
-1 -1 9 16 25 -1 -1 


#include <bits/stdc++.h>
using namespace std;

int main() {
    const int TABLE_SIZE = 7;
    vector<int> table(TABLE_SIZE, -1);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int key = arr[i];
        int j = 0;

        while (j < TABLE_SIZE) {
            int index = (key + j * j) % TABLE_SIZE;
            if (table[index] == -1) {
                table[index] = key;
                break;
            }
            j++;
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << table[i] << " ";
    }

    return 0;
}
