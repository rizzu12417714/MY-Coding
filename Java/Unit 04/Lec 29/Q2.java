Single File Programming Question
Problem Statement



In a file management system, users must provide a valid file name when creating new files.

To maintain consistency, the system enforces specific rules for file names.



Write a Java program that reads a file name and validates it using a custom exception.



Rules

A file name is considered valid if:

It contains only alphanumeric characters (letters A–Z, a–z, and digits 0–9).
Its length is at least 3 characters.
If the file name violates any rule, throw a custom exception named

InvalidFileNameException.



Note



You may use predefined Java functions such as:

String.matches() to check whether the file name is alphanumeric.
Input should be read using Scanner.nextLine().

Input format :
The input consists of a single string S, representing the file name.

Output format :
The output is displayed in the following format:

If the file name is valid, print:

Valid file name



If the file name is invalid, print:

Error: Invalid file name. It must be alphanumeric and have a minimum length of 3 characters.





Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ length of S ≤ 20

S may contain letters, digits, spaces, or special characters.



Sample test cases :
Input 1 :
myfile123
Output 1 :
Valid file name
Input 2 :
ab
Output 2 :
Error: Invalid file name. It must be alphanumeric and have a minimum length of 3 characters.
Input 3 :
file@name
Output 3 :
Error: Invalid file name. It must be alphanumeric and have a minimum length of 3 characters.
Input 4 :
file name
Output 4 :
Error: Invalid file name. It must be alphanumeric and have a minimum length of 3 characters.
Input 5 :
1234
Output 5 :
Valid file name


// Header Snippet
import java.util.Scanner;

// Custom Exception
class InvalidFileNameException extends Exception {
    public InvalidFileNameException(String message) {
        super(message);
    }
}

// Validator Class
class FileNameValidator {

    // Method to validate file name
    public static void validateFileName(String fileName) throws InvalidFileNameException {

        // Check length and alphanumeric condition
        if (fileName.length() < 3 || !fileName.matches("[a-zA-Z0-9]+")) {
            throw new InvalidFileNameException(
                "Error: Invalid file name. It must be alphanumeric and have a minimum length of 3 characters."
            );
        }
    }

    // Method to process input
    public static void processInput() {

        Scanner scanner = new Scanner(System.in);
        String fileName = scanner.nextLine();

        try {
            validateFileName(fileName);
            System.out.println("Valid file name");
        } catch (InvalidFileNameException e) {
            System.out.println(e.getMessage());
        }

        scanner.close();
    }
}

// Footer Snippet
public class Main {
    public static void main(String[] args) {
        FileNameValidator.processInput();
    }
}
