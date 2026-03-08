Single File Programming Question
Problem Statement



Imagine you own a logistics company where you run N number of trucks. Each truck has a unique loading capacity. Now use quadratic probing to arrange the trucks in the truck shed.



Assume the hashtable size is 10. Write a code to find out in which index the truck that has the highest loading capacity stands.



Implement a hash function that calculates the hash index for each key using the modulo operation with the table size (10). The hash index should be calculated as follows: hashIndex = key % tableSize.

Input format :
The first line of input consists of an integer N, representing the number of trucks.

The second line consists of N integers, representing the loading capacity of each truck.

Output format :
The output prints "The lorry that has high load capacity is in index <index>." <index> represents the index of the truck that has the highest loading capacity after hashing.



Refer to the sample output for the exact text and format.

Code constraints :
The given test cases fall under the following specifications:

table size = 10

Sample test cases :
Input 1 :
5
5 10 15 20 25
Output 1 :
The lorry that has high load capacity is in index 9.
Input 2 :
8
14 24 25 37 45 57 67 51
Output 2 :
The lorry that has high load capacity is in index 1.





#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int table[10];
    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int maxVal = -1;
    int maxIndex = -1;

    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;

        int hashIndex = key % 10;
        int j = 0;

        while (table[(hashIndex + j * j) % 10] != -1) {
            j++;
        }

        int index = (hashIndex + j * j) % 10;
        table[index] = key;

        if (key > maxVal) {
            maxVal = key;
            maxIndex = index;
        }
    }

    cout << "The lorry that has high load capacity is in index " << maxIndex << ".";
    return 0;
}
