Single File Programming Question
Problem Statement



Ashok is writing a program that focuses on calculating and displaying the calories burned during a workout for a fitness enthusiast. He has certain specifications as follows.



Implement a class structure with a base class Person and a derived class FitnessEnthusiast that inherits from Person. The program should take user input for the fitness enthusiast's name, workout duration (in minutes), and calorie burn rate (calories burned per minute).



Create a constructor for the FitnessEnthusiast class to initialize the name, workout duration, and calorie burn rate. Utilize the super keyword to invoke the constructor of the superclass. 



Implement a method that calculates the calories burned during the workout using the formula (workout duration * calories burn rate). Display the calculated calories burned.



Help Ashok to complete the program. 

Input format :
The first line of input consists of a string, representing the name.

The second line consists of an integer, representing the workout duration in minutes.

The third line consists of a double value, representing the calorie burn rate.

Output format :
The output prints "Calories Burned: X calories", where X is a double value, representing the calories burned, rounded off to one decimal place.



Refer to the sample output for formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

1 ≤ workout duration ≤ 1200

1.0 ≤ calorie burn rate ≤ 50.0

Sample test cases :
Input 1 :
Dinesh
30
9.70
Output 1 :
Calories Burned: 291.0 calories
Input 2 :
Sharon
120
28.14
Output 2 :
Calories Burned: 3376.8 calories
Whitelist
Set 1:
super



Import java.util.Scanner
// Base class
class Person {

    String name;

    // Constructor of Person
    Person(String name) {
        this.name = name;
    }
}

// Derived class
class FitnessEnthusiast extends Person {

    int duration;
    double burnRate;

    // Constructor using super keyword
    FitnessEnthusiast(String name, int duration, double burnRate) {
        super(name); // calling parent constructor
        this.duration = duration;
        this.burnRate = burnRate;
    }

    // Method to calculate calories
    double calculateCalories() {
        return duration * burnRate;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String name = sc.nextLine();
        int duration = sc.nextInt();
        double burnRate = sc.nextDouble();

        FitnessEnthusiast f = new FitnessEnthusiast(name, duration, burnRate);
        System.out.printf("Calories Burned: %.1f calories", f.calculateCalories());
    }
}
