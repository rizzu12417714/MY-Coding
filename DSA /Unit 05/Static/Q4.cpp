Single File Programming Question
Problem Statement



Rachel is building a text editor that needs to efficiently sort a list of strings based on their length. 



She needs your help to implement a function that takes an array of strings and sorts them using the heap sort algorithm in ascending order of their lengths. The function should return the sorted list of strings.

Input format :
The first line of input consists of an integer N, representing the number of strings.

The second line consists of N space-separated strings.

Output format :
The output prints the sorted list of strings in ascending order of their lengths.

If two strings have the same length, return them based on their original order in the input array.

Code constraints :
The test cases fall under the following constraints:

1 ≤ N ≤ 10

The maximum length of the string is 100.

Sample test cases :
Input 1 :
4
Eye Ball Z Skincare
Output 1 :
Z Eye Ball Skincare 
Input 2 :
7
Lion Elephant Dolphin Penguin Tiger Koala Giraffe
Output 2 :
Lion Tiger Koala Dolphin Penguin Giraffe Elephant




#include <iostream>
#include <string>
using namespace std;

void heapify(string arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].length() > arr[largest].length())
        largest = l;

    if (r < n && arr[r].length() > arr[largest].length())
        largest = r;

    if (largest != i) {
        string temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(string arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        string temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int N;
    cin >> N;
    string *strings = new string[N];
    for (int i = 0; i < N; i++)
        cin >> strings[i];

    heapSort(strings, N);

    for (int i = 0; i < N; i++)
        cout << strings[i] << " ";

    delete[] strings;
    return 0;
}
