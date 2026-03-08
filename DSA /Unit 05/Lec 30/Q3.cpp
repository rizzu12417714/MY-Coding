Single File Programming Question
Problem Statement



Karthik is arranging a set of numbers using a Min Heap so that the smallest values always rise to the top. After inserting all the elements, he wants to view the complete heap and also print the first k smallest elements from it. 



Help him display the final heap structure and the first k elements.

Input format :
The first line contains two integers N and k, where N is the number of elements and k is the count of smallest elements to print.

The second line contains N space-separated integers, representing the values to be inserted into the Min Heap.

Output format :
The first line prints the final Min Heap after all insertions.

The second line prints the first k elements from the heap array.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ N ≤ 100

1 ≤ k ≤ N

Sample test cases :
Input 1 :
7 3
12 4 19 7 2 15 9
Output 1 :
2 4 9 12 7 19 15 
2 4 9 
Input 2 :
5 2
8 3 10 1 6
Output 2 :
1 3 10 8 6 
1 3 

#include <iostream>
using namespace std;

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

int main() {
    int N, k;
    cin >> N >> k;

    int heap[100];

    for (int i = 0; i < N; i++) {
        cin >> heap[i];
        heapifyUp(heap, i);
    }

    for (int i = 0; i < N; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < k; i++) {
        cout << heap[i] << " ";
    }

    return 0;
}
