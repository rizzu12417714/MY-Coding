Single File Programming Question
Problem Statement



Alex is a young inventor who dreamed of creating a magical machine. This machine 
  could take a series of numbers, perform a special mathematical trick, and reveal their transformed values.



Write a program that takes an array of integers as input, and calculates the square of each element using a functional interface.

Input format :
The first line of input consists of an integer N, representing the size of the array.

The second line consists of N space-separated integers, representing the element of the array.

Output format :
The output prints the squares of the elements in the input array, separated by space.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 15

1 ≤ array elements ≤ 50

Sample test cases :
Input 1 :
8
1 8 9 6 5 4 7 3
Output 1 :
1 64 81 36 25 16 49 9
Input 2 :
3
12 24 37
Output 2 :
144 576 1369
Whitelist
Set 1:
interface






import java.util.Scanner;

// Functional Interface (only one abstract method)
interface SquareCalculator {
    int square(int x);
}

// Calculator class
class Calculator {

    // Method to calculate squares
    public int[] calculateSquares(int[] numbers) {

        // Lambda expression for squaring
        SquareCalculator sc = (x) -> x * x;

        int[] result = new int[numbers.length];

        // Apply square on each element
        for (int i = 0; i < numbers.length; i++) {
            result[i] = sc.square(numbers[i]);
        }

        return result;
    }
}

// Main class (driver code)
public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // Read size of array
        int count = scanner.nextInt();

        // Read array elements
        int[] numbers = new int[count];
        for (int i = 0; i < count; i++) {
            numbers[i] = scanner.nextInt();
        }

        // Create Calculator object
        Calculator calculator = new Calculator();

        // Get squared numbers
        int[] squaredNumbers = calculator.calculateSquares(numbers);

        // Print result
        StringBuilder result = new StringBuilder();
        for (int num : squaredNumbers) {
            result.append(num).append(" ");
        }

        System.out.println(result.toString().trim());

        scanner.close();
    }
}
