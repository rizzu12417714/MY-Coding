Single File Programming Question
Problem Statement



Dhivya  is working on a problem to check if a number is a "happy number." A happy number is defined as follows:



Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle that does not include 1.
If the number equals 1, it's a happy number. Otherwise, it's not. 


Help Dhivya implement this task.

Input format :
The first line of input consists of a positive integer n.

Output format :
The Output print True if the number is a happy number.

Print False otherwise.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

n is a positive integer.
The number n should be a valid positive integer within typical integer limits.
Sample test cases :
Input 1 :
19
Output 1 :
True
Input 2 :
2
Output 2 :
False



#include <bits/stdc++.h>
using namespace std;

int nextNum(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    unordered_set<int> seen;

    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = nextNum(n);
    }

    if (n == 1)
        cout << "True";
    else
        cout << "False";

    return 0;
}
