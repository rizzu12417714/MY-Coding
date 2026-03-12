Single File Programming Question
Problem Statement



Arshath is learning programming and wants to practice problems to test his understanding. His professor gave him a program to implement using the super keyword.



Create a Vehicle class with a default maximum speed of 120. Develop a Car class that extends Vehicle, allowing users to specify a custom maximum speed during car setup. Use the super keyword to set the default maximum speed in the Vehicle class. Display both the default and user-defined maximum speeds for the vehicle.



Assist Arshath in implementing the program.

Input format :
The input consists of an integer, representing the custom maximum speed of the car.

Output format :
The first line of the output prints "Maximum Speed from Base class (Vehicle): " followed by an integer representing the maximum default speed from the base class (Vehicle).

The second line of output prints "Maximum Speed from Subclass (Car): " followed by an integer representing the user-defined speed from the subclass (Car).



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ speed ≤ 300

Sample test cases :
Input 1 :
150
Output 1 :
Maximum Speed from Base class (Vehicle): 120
Maximum Speed from Subclass (Car): 150
Input 2 :
156
Output 2 :
Maximum Speed from Base class (Vehicle): 120
Maximum Speed from Subclass (Car): 156
Input 3 :
300
Output 3 :
Maximum Speed from Base class (Vehicle): 120
Maximum Speed from Subclass (Car): 300

Whitelist
Set 1:
super




import java.util.Scanner;

// Base class
class Vehicle {

    int maxSpeed;

    // Constructor to set default speed
    Vehicle() {
        maxSpeed = 120;
    }
}

// Subclass
class Car extends Vehicle {

    int carSpeed;

    // Constructor to receive user-defined speed
    Car(int speed) {
        super(); // call Vehicle constructor
        this.carSpeed = speed;
    }

    // Method to display speeds
    void display() {
        System.out.println("Maximum Speed from Base class (Vehicle): " + super.maxSpeed);
        System.out.println("Maximum Speed from Subclass (Car): " + carSpeed);
    }
}

// Main class
class CarRentalSystem {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int carSpeed = scanner.nextInt();

        Car rentalCar = new Car(carSpeed);

        rentalCar.display();

        scanner.close();
    }
}
