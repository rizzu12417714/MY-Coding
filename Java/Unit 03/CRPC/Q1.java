Single File Programming Question
Problem Statement



You are developing a program to help analyze scores in a competition by determining the highest value from a given set of numbers. The program should allow the user to input the total number of elements and then enter the values one by one. To achieve this, you need to implement a class structure using inheritance. 



Create a base class that provides a method to find the maximum value in an array, and extend this class to a subclass that manages the input data. Additionally, override the toString() method to display the array contents in a readable format and the equals() method to compare two sets of data. The program should then compute and print the highest value from the input set.

Input format :
The first line of input consists of an interger 'n' representing the number of elements in the array.

The second line of input consists of n space-separated integers representing the array elements.

Output format :
The output prints an integer representing the maximum element in the given array.



Refer to the sample output for formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

0 ≤ n ≤ 100

1 ≤ array elements ≤ 100

Sample test cases :
Input 1 :
5
1 6 9 8 7
Output 1 :
9
Input 2 :
3
1 6 5
Output 2 :
6
Whitelist
Set 1:
toString
equals

import java.util.*;

// Base class
class MaxFinder {

    // Method to find maximum value in array
    public int findMax(int[] arr) {
        int max = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        return max;
    }
}

// Subclass extending MaxFinder
class ArrayData extends MaxFinder {

    private int[] values;

    // Constructor
    public ArrayData(int[] values) {
        this.values = values;
    }

    // Method to call parent class findMax
    public int findMax() {
        return super.findMax(values);
    }

    // Overriding toString() method
    public String toString() {
        return Arrays.toString(values);
    }

    // Overriding equals() method
    public boolean equals(Object obj) {

        if (this == obj)
            return true;

        if (obj == null || getClass() != obj.getClass())
            return false;

        ArrayData other = (ArrayData) obj;

        return Arrays.equals(this.values, other.values);
    }
}

// Main class
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Read number of elements
        int n = sc.nextInt();

        int[] values = new int[n];

        // Read array elements
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextInt();
        }

        // Create object of subclass
        ArrayData data = new ArrayData(values);

        // Print maximum value
        System.out.println(data.findMax());

        sc.close();
    }
}
