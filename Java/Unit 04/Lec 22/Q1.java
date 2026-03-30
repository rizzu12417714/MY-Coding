Single File Programming Question
Problem Statement



Ravi is designing an educational app where students engage in a math challenge. The app prompts students to input a base and an exponent.



Create a Java program that calculates the value of base^exponent using an iterative approach. You may use a static nested class to organize the power calculation logic.

Input format :
The first line contains an integer b, representing the base.

The second line contains an integer e, representing the exponent.

Output format :
Print a single integer representing the result of base^exponent.

Do not add extra spaces or symbols at the end of the output.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

0 ≤ b ≤ 109

0 ≤ e ≤ 109



Sample test cases :
Input 1 :
2
3
Output 1 :
8
Input 2 :
11
7
Output 2 :
19487171



import java.util.Scanner;

// Main Solution class
class Solution {

    // Static nested class for power calculation
    static class PowerUtils {

        // Method to calculate base^exponent iteratively
        public long calculatePower(long base, long exponent) {
            long result = 1;

            // Loop runs 'exponent' times
            for (long i = 0; i < exponent; i++) {
                result = result * base;
            }

            return result;
        }
    }
}

// Main class (already provided in footer snippet)
class Main {
    public static void main(String[] args) {

        // Scanner for input
        Scanner scanner = new Scanner(System.in);

        // Taking base input
        long base = scanner.nextLong();

        // Taking exponent input
        long exponent = scanner.nextLong();

        // Creating object of nested class
        Solution.PowerUtils calculator = new Solution.PowerUtils();

        // Calculating power
        long result = calculator.calculatePower(base, exponent);

        // Printing result
        System.out.println(result);

        scanner.close();
    }
}
