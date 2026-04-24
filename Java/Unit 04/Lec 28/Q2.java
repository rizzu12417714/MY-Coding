Single File Programming Question
Problem Statement



Buck is developing a program to validate phone numbers. He wants to ensure that the 
  phone numbers entered by users are in the correct format. Buck's program should handle various cases, including 
  situations where the input contains non-numeric characters or the phone number is not exactly 10 digits.



Check if the input contains only numeric digits.
If the input is non-numeric, throw an InputMismatchException with a descriptive error message "Error: Input mismatch. Please enter a valid 10-digit phone number."
Check if the length of the phone number is exactly 10 digits.
If not, throw an IllegalArgumentException with a message like "Error: Invalid phone number: Must be a 10-digit number."
If the input passes both validations, print "Valid" to indicate that the phone number is valid.
Use the finally block to close the Scanner to prevent resource leaks.
Input format :
The input consists of a string value S, representing the phone number.

Output format :
If the input is a valid 10-digit phone number, the output displays "Valid."

If the input contains non-numeric characters, the output displays "Error: Input mismatch. Please enter a valid 10-digit phone number."

If the input is not exactly 10 digits long, the output displays "Error: Invalid phone number. Must be a 10-digit number."



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ Length of the String ≤ 10

Sample test cases :
Input 1 :
7456984562
Output 1 :
Valid
Input 2 :
1234abcd56
Output 2 :
Error: Input mismatch. Please enter a valid 10-digit phone number.
Input 3 :
98765432
Output 3 :
Error: Invalid phone number: Must be a 10-digit number.
Input 4 :
abcdefghij
Output 4 :
Error: Input mismatch. Please enter a valid 10-digit phone number.



// Header Snippet
import java.util.InputMismatchException;
import java.util.Scanner;

// Body
class PhoneNumberValidator {

    public static void validatePhoneNumber(String phoneNumber) {

        try {
            // Check only digits
            if (!phoneNumber.matches("\\d+")) {
                throw new InputMismatchException();
            }

            // Check length = 10
            if (phoneNumber.length() != 10) {
                throw new IllegalArgumentException();
            }

            // Valid case
            System.out.println("Valid");

        } catch (InputMismatchException e) {
            System.out.println("Error: Input mismatch. Please enter a valid 10-digit phone number.");
        } catch (IllegalArgumentException e) {
            System.out.println("Error: Invalid phone number: Must be a 10-digit number.");
        }
    }
}

// Footer Snippet
public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        PhoneNumberValidator.validatePhoneNumber(scanner.nextLine());

        scanner.close();
    }
}
