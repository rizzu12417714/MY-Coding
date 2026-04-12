Single File Programming Question
Problem Statement



Vikram is building a date processing tool for a scheduling application. 
  The program takes a date as input and applies special rules based on the year:

If the year is divisible by 2, print the number of days in the input month.
If the year is divisible by 5, print the number of days in the next month.
If the year is not divisible by 2 or 5, print: <Date> is invalid
Here, the term invalid means the year does not satisfy the divisibility rules (not a format error).

The program must also handle leap years when checking February.



Input format :
The input contains a single string representing the date in the format: dd/MM/yyyy



Output format :
If the year is divisible by 2, print:

The month <Month> in the year <Year> has <Days> days



If the year is divisible by 5, print:

The next month <NextMonth> in the year <Year> has <Days> days



If the year is not divisible by 2 or 5, print:

<Date> is invalid



Refer to the sample output for formatting specifications.

Code constraints :
The input year will be between 1900 and 2100

The input date will be provided in the format dd/MM/yyyy

Leap years must be handled correctly for February

If the current month is December, the next month is January of the next year

Sample test cases :
Input 1 :
15/08/2024
Output 1 :
The month AUGUST in the year 2024 has 31 days
Input 2 :
20/12/2025
Output 2 :
The next month JANUARY in the year 2026 has 31 days
Input 3 :
10/02/2023
Output 3 :
10/02/2023 is invalid





import java.time.LocalDate;
import java.time.YearMonth;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.Scanner;

// Utility class to process date
class DateUtil {

    public static String processDate(String dateStr) {
        try {
            // Define input format
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

            // Parse input date
            LocalDate date = LocalDate.parse(dateStr, formatter);

            int year = date.getYear();
            int month = date.getMonthValue();

            // Condition 1: Year divisible by 2
            if (year % 2 == 0) {
                YearMonth ym = YearMonth.of(year, month);
                int days = ym.lengthOfMonth();

                return "The month " + date.getMonth() +
                        " in the year " + year +
                        " has " + days + " days";
            }

            // Condition 2: Year divisible by 5
            else if (year % 5 == 0) {
                LocalDate nextMonthDate = date.plusMonths(1);

                int nextYear = nextMonthDate.getYear();
                int nextMonth = nextMonthDate.getMonthValue();

                YearMonth ym = YearMonth.of(nextYear, nextMonth);
                int days = ym.lengthOfMonth();

                return "The next month " + nextMonthDate.getMonth() +
                        " in the year " + nextYear +
                        " has " + days + " days";
            }

            // Condition 3: Invalid case
            else {
                return dateStr + " is invalid";
            }

        } catch (DateTimeParseException e) {
            // If date format is wrong
            return "Invalid date format";
        }
    }
}

// Main class (Footer)
class DateValidator {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // Read input
        String dateStr = scanner.nextLine();

        // Process date
        String result = DateUtil.processDate(dateStr);

        // Print result
        System.out.println(result);

        scanner.close();
    }
}
