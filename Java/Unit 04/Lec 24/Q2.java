Single File Programming Question
Problem Statement



Saran is tasked with designing a program to alphabetize a given string. 



Implement a class, StringSorter, that takes a string as input and sorts its characters alphabetically. The sorting functionality is encapsulated within a non-static nested class, Alphabetizer, which is responsible for sorting the characters and returning the result.



Write a program that takes user input for a string, utilizes the StringSorter class to alphabetize it, and displays the sorted string.

Input format :
The input consists of a string representing the string that needs to be sorted.

Output format :
The output prints a string representing the sorted string.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ length of input string ≤ 10,000

Sample test cases :
Input 1 :
hello
Output 1 :
ehllo
Input 2 :
performance
Output 2 :
aceefmnoprr


import java.util.Arrays;
import java.util.Scanner;

// Your Solution class
class Solution {

    // Outer class
    class StringSorter {
        private String input;

        // Constructor
        public StringSorter(String input) {
            this.input = input;
        }

        // Non-static nested class
        class Alphabetizer {

            // Method to sort string
            public String sort() {
                char[] arr = input.toCharArray();   // Convert to char array
                Arrays.sort(arr);                  // Sort characters
                return new String(arr);            // Convert back to string
            }
        }

        // Method called from main
        public String alphabetize() {
            Alphabetizer a = new Alphabetizer();  // Create inner class object
            return a.sort();                      // Return sorted string
        }
    }
}

// Footer 
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String input = scanner.nextLine();

        Solution solution = new Solution();
        Solution.StringSorter sorter = solution.new StringSorter(input);

        String sortedString = sorter.alphabetize();
        System.out.println(sortedString);

        scanner.close();
    }
}
