Single File Programming Question
Problem Statement



Sanjay is designing a system to manage priority tasks using a Max Heap data structure. Users can input a series of task priorities (represented as integers), which the program organizes into a heap.



Sanjay wants the program to identify and remove the first even-numbered priority from the heap. If an even number exists, the heap should be displayed both before and after the deletion. If no even number is found, the program should output a message stating this.

Input format :
The first line contains an integer n, representing the number of task priorities to be inserted into the Max Heap.

The second line contains n space-separated integers, representing the task priorities to be inserted into the heap.

Output format :
Print the elements of the Max Heap in level order after all insertions.

If an even number exists, print the Max Heap after deleting the first even number. If no even number is found, print: "No even number found".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ task priorities ≤ 100

Sample test cases :
Input 1 :
4
6 10 8 5
Output 1 :
10 6 8 5 
8 6 5 
Input 2 :
3
5 7 9
Output 2 :
9 5 7 
No even number found




#include <iostream>
using namespace std;

void heapifyUp(int arr[], int n, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (arr[index] > arr[parent]) {
            swap(arr[index], arr[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void insertIntoMaxHeap(int arr[], int& n, int value) {
    arr[n] = value;
    heapifyUp(arr, n, n);
    n++;
}

void heapifyDown(int arr[], int n, int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        
        if (largest != index) {
            swap(arr[index], arr[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

bool deleteFirstEven(int arr[], int& n) {
    int evenIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenIndex = i;
            break;
        }
    }
    
    if (evenIndex == -1) return false;
    
    arr[evenIndex] = arr[n - 1];
    n--;
    heapifyDown(arr, n, evenIndex);
    return true;
}

void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int n = 0;
    int num_elements;
    cin >> num_elements;
    
    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        insertIntoMaxHeap(arr, n, value);
    }
    
    printMaxHeap(arr, n);
    
    if (!deleteFirstEven(arr, n)) {
        cout << "No even number found";
    } else {
        printMaxHeap(arr, n);
    }
    
    return 0;
}
