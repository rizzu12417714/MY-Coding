Single File Programming Question
Problem Statement





Akash has been assigned the task of developing a program to determine whether three given lengths can form a valid triangle. A triangle is considered valid if the sum of any two sides is greater than the third side. To implement this, Akash needs to create a program that takes three integer inputs representing the side lengths and checks whether they satisfy the triangle inequality conditions: a + b > c, a + c > b, and b + c > a. 



The solution should be designed using inheritance, incorporating features such as overriding the toString() and equals() methods, utilizing the instanceof operator, or using super and final keywords.

Input format :
The input consists of three space-separated integers, each representing the length of a side of a triangle.

Output format :
The output displays a single line indicating whether the given side lengths form a triangle or not.

If the side lengths form a triangle, it prints "Triangle".

If the side lengths do not form a triangle, it prints "Not a Triangle".



Refer to the sample output for the formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

1 ≤ side 1, side 2, side 3 ≤ 60

Sample test cases :
Input 1 :
3 4 5
Output 1 :
Triangle
Input 2 :
5 12 30
Output 2 :
Not a Triangle
Input 3 :
35 35 60
Output 3 :
Triangle
Whitelist
Set 1:
toString
equals


import java.util.Scanner;

class Shape {
    int a, b, c;

    Shape(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

class Triangle extends Shape {

    Triangle(int a, int b, int c) {
        super(a, b, c);
    }

    void checkTriangle() {
        if ((a + b > c) && (a + c > b) && (b + c > a)) {
            System.out.println("Triangle");
        } else {
            System.out.println("Not a Triangle");
        }
    }

    public String toString() {
        return a + " " + b + " " + c;
    }

    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Triangle)) return false;

        Triangle t = (Triangle) obj;
        return a == t.a && b == t.b && c == t.c;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int side1 = input.nextInt();
        int side2 = input.nextInt();
        int side3 = input.nextInt();

        Triangle t = new Triangle(side1, side2, side3);
        t.checkTriangle();

        input.close();
    }
}
