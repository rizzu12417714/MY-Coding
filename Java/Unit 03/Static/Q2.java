Single File Programming Question
Problem Statement



You are given a Java program with two classes, SuperClass and SubClass. The SubClass is a subclass of SuperClass. 



The SuperClass has an integer variable variableA, which is initialized by taking input from the user using a Scanner object. The SubClass has an integer variable variableB, which is calculated as twice the value of variableA from the superclass.



Your task is to complete the program by using the super keyword to access the variableA from the superclass SuperClass within the SubClass. Once you complete the program, it should create a SubClass object, calculate the value of variableB using the super keyword, and then display both variableA from the SuperClass and variableB from the SubClass using the displayVariables() method.

Input format :
The input consists of an integer representing the value of variableA.

Output format :
The first line of output prints "The value of SuperClass: <variableA>" where <variableA> is the integer value entered by the user.

The second line of output prints "The value of SubClass: <variableB>" where <variableB> is twice the value of <variableA>.



Refer to the sample output for formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

0 ≤ variableA ≤ 104

Sample test cases :
Input 1 :
5
Output 1 :
The value of SuperClass: 5
The value of SubClass: 10
Input 2 :
18
Output 2 :
The value of SuperClass: 18
The value of SubClass: 36
Whitelist
Set 1:
super
import java.util.Scanner;

class SuperClass {
    int variableA;

    SuperClass(int value) {
        this.variableA = value;
    }
}

class SubClass extends SuperClass {

    int variableB;

    SubClass(int value) {
        super(value);
        this.variableB = super.variableA * 2;
    }

    void displayVariables() {
        System.out.println("The value of SuperClass: " + variableA);
        System.out.println("The value of SubClass: " + variableB);
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int value = sc.nextInt();
        SubClass obj = new SubClass(value);
        obj.displayVariables();
    }
}
