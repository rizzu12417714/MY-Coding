Single File Programming Question
Problem Statement



Ram is tasked with creating a basic calculator application that supports three fundamental mathematical operations:
addition, subtraction, and multiplication. The application will consist of a parent class Calculator (addition and subtraction)
  and a child class AdvancedCalculator (multiplication). The program will take user input for the operation choice and two numeric values,
  then calculate and display the result.

Input format :
The first line of input contains an integer representing the choice of operation:

1 for Addition
2 for Subtraction
3 for Multiplication
The second line of input contains an integer num1, which is the first numeric value for the calculation.

The third line of input contains an integer num2, which is the second numeric value for the calculation.

Output format :
If the choice is 1 (Addition): the output prints "Addition: " followed by an integer representing the addition result of num1 and num2.

If the choice is 2 (Subtraction): the output prints "Subtraction: " followed by an integer representing the subtraction result of num1 and num2.

If the choice is 3 (Multiplication): the output prints "Multiplication: " followed by an integer representing the multiplication result of num1 and num2.

If the choice is other: the output prints "Invalid".



Refer to the sample output for format specification

Code constraints :
The given test cases fall under the following constraints:

0 ≤ num1, num2 ≤ 106

Sample test cases :
Input 1 :
1
5
3
Output 1 :
Addition: 8
Input 2 :
2
10
4
Output 2 :
Subtraction: 6
Input 3 :
3
7
9
Output 3 :
Multiplication: 63
Input 4 :
4
3
5
Output 4 :
Invalid



import java.util.Scanner;

// Parent class
class Calculator {

    // Method to perform addition
    int add(int num1, int num2) {
        return num1 + num2;
    }

    // Method to perform subtraction
    int subtract(int num1, int num2) {
        return num1 - num2;
    }
}

// Child class inheriting Calculator
class AdvancedCalculator extends Calculator {

    // Method to perform multiplication
    int multiply(int num1, int num2) {
        return num1 * num2;
    }
}

// Main class
public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // Create object of child class
        AdvancedCalculator calculator = new AdvancedCalculator();

        // Read operation choice
        int choice = scanner.nextInt();

        // If choice is invalid
        if (choice < 1 || choice > 3) {
            System.out.println("Invalid");
            return;
        }

        // Read numbers
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();

        int result;

        // Perform operation based on choice
        if (choice == 1) {
            result = calculator.add(num1, num2);
            System.out.println("Addition: " + result);
        } 
        else if (choice == 2) {
            result = calculator.subtract(num1, num2);
            System.out.println("Subtraction: " + result);
        } 
        else {
            result = calculator.multiply(num1, num2);
            System.out.println("Multiplication: " + result);
        }
    }
}
