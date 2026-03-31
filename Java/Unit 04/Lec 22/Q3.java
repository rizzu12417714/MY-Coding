Single File Programming Question
Problem Statement



Sharon, a fitness enthusiast, is working on a project to track and display the improvement percentage in weightlifting for gym members. 
  She needs to create a GymMember class with a non-static nested class Progress that calculates the percentage improvement in weightlifting over time. 



The program should take input from gym members, including their names, initial weight, and current weight, and then calculate and display the improvement percentage. 



Formula

Improvement Percentage = (Current Weight − Initial Weight) / Initial Weight * 100

Input format :
The first input line consists of a string, representing the person's name.

The second line consists of two space-separated integers, representing the initial weight and current weight of the person, respectively.

Output format :
The output prints a double value rounded off to one decimal place, representing the improvement percentage.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ weight ≤ 100

Sample test cases :
Input 1 :
John
50 55
Output 1 :
10.0
Input 2 :
Dev
60 68
Output 2 :
13.3
Input 3 :
Ragu
60 98
Output 3 :
63.3



import java.util.Scanner;

// Solution class
class Solution {

    // Outer class
    class GymMember {
        private String name;
        private int initialWeight;
        private int currentWeight;

        // Constructor
        public GymMember(String name, int initialWeight, int currentWeight) {
            this.name = name;
            this.initialWeight = initialWeight;
            this.currentWeight = currentWeight;
        }

        // Non-static nested class
        class Progress {

            // Method to calculate improvement percentage
            public double calculate() {
                return ((currentWeight - initialWeight) * 100.0) / initialWeight;
            }
        }

        // Method called from main
        public double getImprovementPercentage() {
            Progress p = new Progress();   // create inner class object
            return p.calculate();         // return result
        }
    }
}

// Footer (given)
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String name = scanner.nextLine();
        int initialWeight = scanner.nextInt();
        int currentWeight = scanner.nextInt();

        Solution solution = new Solution();
        Solution.GymMember member =
                solution.new GymMember(name, initialWeight, currentWeight);

        System.out.printf("%.1f\n", member.getImprovementPercentage());

        scanner.close();
    }
}
