Single File Programming Question
Problem Statement



Alice needs a program to calculate the factorial of a non-negative integer using recursion.
  The program should handle invalid input and negative numbers by displaying appropriate error messages.



Task:

Read an integer N from the user.
If N is non-negative, calculate N! using recursion.
If N is negative, display an error.
If the input is not a valid integer, display an error.


Formula:

For a non-negative integer N:

N! = N × (N-1) × ... × 1
0! = 1
Input format :
A single integer N.

Hint: Use Scanner.nextInt() to read input.

Output format :
If input is valid and non-negative, print the factorial value.



If input is negative, print:

Error: Input must be non-negative



If input is not an integer, print:

Error: Input must be a valid integer



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

-10 ≤ N ≤ 20

Sample test cases :
Input 1 :
5
Output 1 :
120
Input 2 :
0
Output 2 :
1
Input 3 :
-3
Output 3 :
Error: Input must be non-negative
Input 4 :
abc
Output 4 :
Error: Input must be a valid integer
Input 5 :
1
Output 5 :
1
Input 6 :
-10
Output 6 :
Error: Input must be non-negative


// Header Snippet
import java.util.Scanner;
import java.util.InputMismatchException;

class FactorialCalculator {

    // Recursive factorial function
    static long factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    // Method to validate and calculate factorial
    static long calculateFactorial(int n) {
        if (n < 0) {
            throw new IllegalArgumentException();
        }
        return factorial(n);
    }

    // Footer Snippet (Main Method)
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {
            int n = sc.nextInt();
            System.out.println(calculateFactorial(n));

        } catch (IllegalArgumentException e) {
            System.out.println("Error: Input must be non-negative");

        } catch (InputMismatchException e) {
            System.out.println("Error: Input must be a valid integer");
        }

        sc.close();
    }
}
