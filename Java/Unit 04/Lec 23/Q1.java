Single File Programming Question
Problem Statement



Kehlani is a diligent homemaker with a knack for organization and management. 
  She’s planning a system to monitor the expiry dates of groceries to ensure her household always uses fresh items and reduces waste.



She designed a method monitorExpiryDates that collects the names of groceries and their respective days until expiration. 
  The class ExpiryChecker under the method monitorExpiryDates tracks the items nearing their expiry dates and
  displays warning messages when they are close to expiration (less than or equal to 7 days).



Now, help Kehlani by writing a program using the concept of local classes.

Input format :
The first line of input is a positive integer n which represents the number of grocery items to be monitored.

The next n lines of input contain the name of the grocery item and the number of days remaining for the item to expire separated by space.

Output format :
The output displays "[item] is nearing its expiry date. Only [d] days left" for each product that is about to expire.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ Length of the String(Item Name) ≤ 100

0 ≤ daysRemaining ≤ 100

Sample test cases :
Input 1 :
3
Milk 4
Bread 8
Eggs 2
Output 1 :
Milk is nearing its expiry date. Only 4 days left
Eggs is nearing its expiry date. Only 2 days left
Input 2 :
4
Yogurt 1
Chicken 6
Lettuce 9
Tomatoes 3
Output 2 :
Yogurt is nearing its expiry date. Only 1 days left
Chicken is nearing its expiry date. Only 6 days left
Tomatoes is nearing its expiry date. Only 3 days left



import java.util.Scanner;

// Main class
class GroceryMonitor {

    // Method where we use LOCAL CLASS
    public void monitorExpiryDates(String[] items, int[] daysRemaining) {

        // ✅ Local Class inside method
        class ExpiryChecker {

            // Method to check and print expiry items
            void checkExpiry(String item, int days) {
                if (days <= 7) {
                    System.out.println(item + " is nearing its expiry date. Only " + days + " days left");
                }
            }
        }

        // Create object of local class
        ExpiryChecker checker = new ExpiryChecker();

        // Loop through items
        for (int i = 0; i < items.length; i++) {
            checker.checkExpiry(items[i], daysRemaining[i]);
        }
    }

    // Main method (Footer part)
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int numItems = scanner.nextInt();

        String[] groceryItems = new String[numItems];
        int[] daysRemaining = new int[numItems];

        // Input loop
        for (int i = 0; i < numItems; i++) {
            groceryItems[i] = scanner.next();
            daysRemaining[i] = scanner.nextInt();
        }

        // Create object and call method
        GroceryMonitor monitor = new GroceryMonitor();
        monitor.monitorExpiryDates(groceryItems, daysRemaining);

        scanner.close();
    }
}
