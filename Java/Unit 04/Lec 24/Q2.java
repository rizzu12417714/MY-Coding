Single File Programming Question
Problem Statement



Elara wants to reverse a given string using Java lambda expressions.



Write a program that takes a string as input and prints the reversed version
    of the string using a functional interface and a lambda expression.



Note: You may use the predefined method StringBuilder.reverse() for reversing the string.

Input format :
The input consists of a single line containing a string.

Output format :
Print the reversed version of the input string.

Refer to the sample output for formatting specifications.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ length of the string ≤ 25

The string may contain lowercase, uppercase, and special characters.

Sample test cases :
Input 1 :
Wizard!!
Output 1 :
!!draziW
Input 2 :
Enchanted
Output 2 :
detnahcnE



import java.util.Scanner;

// Functional Interface
interface ReverseStringFunction {
    String reverse(String input);
}

// Class to perform reverse using lambda
class StringReverser {

    // Static method (called from main)
    public static String reverseUsingLambda(String input) {

        // Lambda expression implementation
        ReverseStringFunction obj = (str) -> 
                new StringBuilder(str).reverse().toString();

        // Return reversed string
        return obj.reverse(input);
    }
}

// Main class
public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // Read input string
        String input = scanner.nextLine();

        // Call method
        String reversed = StringReverser.reverseUsingLambda(input);

        // Print output
        System.out.println(reversed);

        scanner.close();
    }
}
