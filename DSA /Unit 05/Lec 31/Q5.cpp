Single File Programming Question
Problem Statement



Scott Boland , a software developer, is working on a hash table implementation to count the frequency of elements in an array. He needs to insert the elements into the hash table, and for each element, she needs to keep track of its frequency. After processing all elements, she wants to display the elements along with their frequencies.



Help him implement the task.



FORMULA

Hash Function: The hash function calculates the index for each element using:

	index = key % TABLE_SIZE
Collision Resolution: If a collision occurs (i.e., the index is already occupied), linear probing is used to find the next available index:

index = (index + 1) % TABLE_SIZE
Frequency Update: If the element already exists at the index, the frequency is incremented by 1:

freq[index]++
Insertion: If the element does not exist at the calculated index, the element is inserted and its frequency is set to 1.

Input format :
The first line of input consists of an integer n, the number of elements in the array.

The next n lines each contain an integer representing the elements of the array.

Output format :
The program prints each element followed by the number of times it appears in the array, in the format: "Element <element> appears <frequency> times"



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 1000
MAX_SIZE = 1000
The numbers in the array can range from -1000 to 1000
Sample test cases :
Input 1 :
7
1 3 2 1 2 3 3
Output 1 :
Element 1 appears 2 times
Element 2 appears 2 times
Element 3 appears 3 times
Input 2 :
5
2 2 1 1 3
Output 2 :
Element 1 appears 2 times
Element 2 appears 2 times
Element 3 appears 1 times



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int TABLE_SIZE = 2003;
    vector<int> table(TABLE_SIZE, INT_MIN);
    vector<int> freq(TABLE_SIZE, 0);

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;

        int index = ((key % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;

        while (table[index] != INT_MIN && table[index] != key) {
            index = (index + 1) % TABLE_SIZE;
        }

        if (table[index] == INT_MIN) {
            table[index] = key;
            freq[index] = 1;
        } else {
            freq[index]++;
        }
    }

    vector<pair<int, int>> result;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != INT_MIN) {
            result.push_back({table[i], freq[i]});
        }
    }

    sort(result.begin(), result.end());

    for (auto &p : result) {
        cout << "Element " << p.first << " appears " << p.second << " times\n";
    }

    return 0;
}
