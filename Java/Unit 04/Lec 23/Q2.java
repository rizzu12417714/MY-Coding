Single File Programming Question
Problem Statement



Hank needs to write a program that counts the number of vowels (both uppercase and lowercase) in a given string. 
  The program should handle various scenarios, including invalid input.

Your task is to design and write a program to help Hank with this task. The program should ask Hank to input a string, 
  count the vowels, and display the count. It should also provide error messages for invalid inputs.

Input format :
The first line of input contains a string that may include alphabetic characters (both uppercase and lowercase), numbers, and spaces.

Output format :
The output displays an integer representing the number of vowels in the string.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test case falls under the following constraints:

1 < len(input) < 102

Sample test cases :
Input 1 :
Hello world!
Output 1 :
3
Input 2 :
H3ll0 W0rld
Output 2 :
0



import java.util.Scanner;

// You are using Java
public class Main {

    // Method to count vowels
    public static int countVowels(String inputString) {

        // Handle invalid input (null or empty)
        if (inputString == null || inputString.length() == 0) {
            return 0;
        }

        int count = 0;

        // Convert string to lowercase (to handle both cases)
        inputString = inputString.toLowerCase();

        // Loop through each character
        for (int i = 0; i < inputString.length(); i++) {

            char ch = inputString.charAt(i);

            // Check if vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }

        return count;
    }

    // Main method (Footer)
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // Take full line input (important for spaces)
        String inputString = scanner.nextLine();

        scanner.close();

        // Call function
        int result = countVowels(inputString);

        // Output result
        System.out.println(result);
    }
}
