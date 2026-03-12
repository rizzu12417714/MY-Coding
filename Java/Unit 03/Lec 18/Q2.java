Single File Programming Question
Problem Statement



Alice is developing an interactive square calculator program to engage his students. He wants the program to take the user's name and an integer as input, calculate the square of the integer, and display a personalized message using the class CustomClass.



Alice is interested in ensuring that the program uses the instanceof operator to check the presence of specific instances. 



Note

name is an instance of String class.

customObj is an instanceof CustomClass.

Any other instance name other than the above-mentioned will create an error.

Input format :
The first line of input consists of a string, which represents the name.

The second line consists of an integer.

Output format :
The first line of output prints “Name is an instance of String: <true/false>”, indicating whether the entered name is an instance of the String class.

The second line prints “Square of the entered number: <square>”, where <square> is the square of the entered integer.

The third line prints “Hey, [name]! How are you?”, where [name] is the string entered by the user.

The fourth line prints “customObj is an instance of CustomClass: <true/false>”, indicating whether the created object customObj is an instance of the CustomClass.



Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

The string name input should be 100 characters.

1 ≤ input integer ≤ 15

Sample test cases :
Input 1 :
Arun
3
Output 1 :
Name is an instance of String: true
Square of the entered number: 9
Hey, Arun! How are you?
customObj is an instance of CustomClass: true
Input 2 :
Sharon
12
Output 2 :
Name is an instance of String: true
Square of the entered number: 144
Hey, Sharon! How are you?
customObj is an instance of CustomClass: true


Whitelist
Set 1:
instanceof




import java.util.Scanner;

// Custom class
class CustomClass {

    // Method to display a message
    void displayMessage(String message) {
        System.out.println(message);
    }

    // Method to check if object is instance of CustomClass
    boolean isInstanceOfCustomClass(Object obj) {
        return obj instanceof CustomClass;
    }
}

// Utility class
class Utility {

    // Method to check if the given object is instance of String
    boolean isStringInstance(Object obj) {
        return obj instanceof String;
    }

    // Method to calculate square of a number
    int squareNumber(int num) {
        return num * num;
    }
}

// Main class
public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        String name = scanner.nextLine();

        Utility utility = new Utility();

        boolean result1 = utility.isStringInstance(name);
        System.out.println("Name is an instance of String: " + result1);

        int userNumber = scanner.nextInt();

        int squaredNumber = utility.squareNumber(userNumber);
        System.out.println("Square of the entered number: " + squaredNumber);

        CustomClass customObj = new CustomClass();

        customObj.displayMessage("Hey, " + name + "! How are you?");

        boolean result3 = customObj.isInstanceOfCustomClass(customObj);
        System.out.println("customObj is an instance of CustomClass: " + result3);

        scanner.close();
    }
}
