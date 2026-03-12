Single File Programming Question
Problem Statement



Janani aims to create a versatile palindrome checker capable of handling both numeric values and words. 



The base class, PalindromeChecker, features a parameterized constructor that takes an integer as input. It includes a method, isPalindrome(), which determines whether the given integer is a palindrome. Include a method displayResult() to print the result of the palindrome check for numbers.



The subclass, WordPalindromeChecker, is derived from the base class. This subclass overrides the isPalindrome() method to accommodate word inputs, treating them case-insensitively. The overridden displayResult() method ensures that the outcome of the word palindrome check is appropriately printed.



Create instances of both classes in the main class and display the results.

Input format :
The first line of input consists of an integer representing the number to check for palindrome.

The second line consists of a string containing both lowercase and uppercase letters, as well as spaces, which is checked for word palindrome(Case-insensitive).

Output format :
If the given integer is a palindrome, the first line of output prints "The number is a palindrome."

Else, print "The number is not a palindrome."

If the given string is a palindrome, the second line of output prints "The word is a palindrome."

Else, print "The word is not a palindrome."



Refer to the sample output for formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

1 ≤ input integer ≤ 109

1 ≤ length of string < 50

The strings are case-insensitive.

Sample test cases :
Input 1 :
121
madam
Output 1 :
The number is a palindrome.
The word is a palindrome.
Input 2 :
15651
raar world
Output 2 :
The number is a palindrome.
The word is not a palindrome.
Input 3 :
1563
Malayalam
Output 3 :
The number is not a palindrome.
The word is a palindrome.
Input 4 :
45789
java
Output 4 :
The number is not a palindrome.
The word is not a palindrome.
Input 5 :
1
race
Output 5 :
The number is a palindrome.
The word is not a palindrome.





import java.util.Scanner;

// Base class for number palindrome checking
class PalindromeChecker {

    int number;

    // Parameterized constructor
    PalindromeChecker(int number) {
        this.number = number;
    }

    // Method to check if number is palindrome
    boolean isPalindrome() {

        int original = number;
        int reverse = 0;

        while (original != 0) {
            int digit = original % 10;
            reverse = reverse * 10 + digit;
            original = original / 10;
        }

        return number == reverse;
    }

    // Method to display result for number
    void displayResult() {
        if (isPalindrome()) {
            System.out.println("The number is a palindrome.");
        } else {
            System.out.println("The number is not a palindrome.");
        }
    }
}

// Derived class for word palindrome checking
class WordPalindromeChecker extends PalindromeChecker {

    String word;

    // Constructor for word
    WordPalindromeChecker(String word) {
        super(0); // calling parent constructor with dummy value
        this.word = word;
    }

    // Override palindrome check for word
    @Override
    boolean isPalindrome() {

        String str = word.toLowerCase(); // case insensitive
        String reversed = "";

        // Reverse the string
        for (int i = str.length() - 1; i >= 0; i--) {
            reversed = reversed + str.charAt(i);
        }

        return str.equals(reversed);
    }

    // Override display method for word result
    @Override
    void displayResult() {
        if (isPalindrome()) {
            System.out.println("The word is a palindrome.");
        } else {
            System.out.println("The word is not a palindrome.");
        }
    }
}

// Main class
public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int number = scanner.nextInt();

        // check number palindrome
        PalindromeChecker numberChecker = new PalindromeChecker(number);
        numberChecker.displayResult();

        scanner.nextLine(); // clear buffer

        String word = scanner.nextLine();

        // check word palindrome
        WordPalindromeChecker wordChecker = new WordPalindromeChecker(word);
        wordChecker.displayResult();

        scanner.close();
    }
}
