Single File Programming Question
Problem Statement



Raj is designing a productivity tool for employees to help them calculate the number of working days
between two given dates. This is particularly useful for scheduling projects, planning leave, or tracking productivity.

The program should:

Accept two dates as input in the format "dd/MM/yyyy": the start date and the end date.
Calculate the total number of weekdays (Monday through Friday) between the two dates, inclusive.
Exclude weekends (Saturday and Sunday) from the calculation.
Implement the logic for calculating working days in a utility class, and the main class should only handle input and output.
Input format :
The first line of input contains a string representing the start date in the format "dd/MM/yyyy".

The second line of input contains a string representing the end date in the format "dd/MM/yyyy".

Output format :
The output displays an integer representing the total number of weekdays between the two dates.



Refer to the sample output for formatting specifications.

Code constraints :
The input dates will always be in the valid "dd/MM/yyyy" format.

The end date will always be greater than or equal to the start date.

The range of dates will be within the years 1900 to 2100.

Sample test cases :
Input 1 :
01/01/2023
07/01/2023
Output 1 :
5
Input 2 :
15/08/2023
15/08/2023
Output 2 :
1


import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.DayOfWeek;
import java.util.Scanner;

// Utility Class
class DateUtil {

    public static int calculateWorkingDays(LocalDate startDate, LocalDate endDate) {

        int count = 0;

        // Loop through dates (inclusive)
        while (!startDate.isAfter(endDate)) {

            DayOfWeek day = startDate.getDayOfWeek();

            // Count only weekdays (Mon–Fri)
            if (day != DayOfWeek.SATURDAY && day != DayOfWeek.SUNDAY) {
                count++;
            }

            // Move to next day
            startDate = startDate.plusDays(1);
        }

        return count;
    }
}

// Footer Snippet (Main Class)
class WorkingDaysCalculator {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        // Read input
        String startDateStr = scanner.nextLine().trim();
        LocalDate startDate = LocalDate.parse(startDateStr, formatter);

        String endDateStr = scanner.nextLine().trim();
        LocalDate endDate = LocalDate.parse(endDateStr, formatter);

        // Calculate working days
        int workingDays = DateUtil.calculateWorkingDays(startDate, endDate);

        // Output result
        System.out.println(workingDays);

        scanner.close();
    }
}
