Single File Programming Question
Problem Statement



Imagine you have a regular shop and a holiday shop. The regular shop offers a 10% discount on all its products, and the holiday shop offers an additional 5% discount during the holiday season. The price of the product will be given by the user and the final prices of regular shop and holiday shop should be displayed. So write a program to calculate the final prices of both the shops. use the function "calculateFinalPrice" to override the classes.

Input format :
The input consists of a double value 'p' representing the price given by the user.

Output format :
The first line of output prints “Regular Shop Final Price: <price>”, where <price> is the discounted price after applying a 10% discount, displayed as a double value (rounded to 2 decimal place).

The second line of output prints “Holiday Shop Final Price: <price>”, where <price> is the discounted price after applying an additional 5% discount, displayed as a double value (rounded to 2 decimal place).



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1.0 ≤ p ≤ 10000.0

Sample test cases :
Input 1 :
100.0
Output 1 :
Regular Shop Final Price: 90.00
Holiday Shop Final Price: 85.50
Input 2 :
50.0
Output 2 :
Regular Shop Final Price: 45.00
Holiday Shop Final Price: 42.75



import java.util.Scanner;

// Base class
class RegularShop {

    double price;

    // Constructor
    RegularShop(double price) {
        this.price = price;
    }

    // Method to calculate final price with 10% discount
    double calculateFinalPrice() {
        return price - (price * 0.10);
    }
}

// Derived class
class HolidayShop extends RegularShop {

    // Constructor
    HolidayShop(double price) {
        super(price);
    }

    // Overriding the method to add extra 5% discount
    @Override
    double calculateFinalPrice() {

        // First apply regular shop discount
        double regularPrice = super.calculateFinalPrice();

        // Apply additional 5% holiday discount
        return regularPrice - (regularPrice * 0.05);
    }
}

// Main class
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Read price from user
        double price = sc.nextDouble();

        // Create objects
        RegularShop regularShop = new RegularShop(price);
        HolidayShop holidayShop = new HolidayShop(price);

        // Print results
        System.out.printf("Regular Shop Final Price: %.2f%n", regularShop.calculateFinalPrice());
        System.out.printf("Holiday Shop Final Price: %.2f%n", holidayShop.calculateFinalPrice());

        sc.close();
    }
}
