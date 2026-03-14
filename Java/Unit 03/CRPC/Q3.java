Single File Programming Question
Problem Statement



Rufus is tasked with developing a Carbon Footprint Calculator to estimate the environmental impact of electricity usage and transportation emissions.



Your task is to guide Rufus to complete the program by following the instructions below.



EnvironmentalMetrics Class

Contains two protected fields:

electricityUsage: Electricity usage in kilowatt-hours (kWh)
transportationEmissions: Transportation activity value in kilograms (kg)


CarbonFootprintCalculator Class



A final class that extends the EnvironmentalMetrics class.

Contains two final fields:

          electricityEmissionFactor = 0.4 (kgCO2 per kWh)

          transportationEmissionFactor = 2.5 (kgCO2 per kg)

Constructor:

Accepts electricity usage and transportation emissions and initializes the inherited fields.

Method:

estimateCarbonEmissions() calculates and displays:

        Carbon emissions from electricity

        Carbon emissions from transportation

        Total carbon footprint



Formulas

Electricity Carbon = electricityUsage × electricityEmissionFactor
Transportation Carbon = transportationEmissions × transportationEmissionFactor
Total Carbon Footprint = Electricity Carbon + Transportation Carbon
Input format :
The first line of input contains a double value representing the electricity usage in kilowatt-hours.

The second line of input contains a double value representing the transportation emissions.

Output format :
The first line of output prints the carbon emissions from electricity usage, rounded off to two decimal places, in the format:

"Electricity: <value> kgCO2"

The second line of output prints the carbon emissions from transportation, rounded off to two decimal places, in the format:

"Transportation: <value> kgCO2"

The third line of output prints the total carbon footprint (sum of electricity and transportation emissions), rounded off to two decimal places, in the format: "Total: <value> kgCO2"



Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1.0 ≤ electricity ≤ 250.0

1.0 ≤ transportation emissions ≤ 250.0

Sample test cases :
Input 1 :
6.2
3.4
Output 1 :
Electricity: 2.48 kgCO2
Transportation: 8.50 kgCO2
Total: 10.98 kgCO2
Input 2 :
35.7
25.4
Output 2 :
Electricity: 14.28 kgCO2
Transportation: 63.50 kgCO2
Total: 77.78 kgCO2
Input 3 :
145.3
126.9
Output 3 :
Electricity: 58.12 kgCO2
Transportation: 317.25 kgCO2
Total: 375.37 kgCO2

Whitelist
Set 1:
final

import java.util.Scanner;

// Base class
class EnvironmentalMetrics {

    protected double electricityUsage;
    protected double transportationEmissions;

    // Constructor
    EnvironmentalMetrics(double electricityUsage, double transportationEmissions) {
        this.electricityUsage = electricityUsage;
        this.transportationEmissions = transportationEmissions;
    }
}

// Final derived class
final class CarbonFootprintCalculator extends EnvironmentalMetrics {

    // Final emission factors
    final double electricityEmissionFactor = 0.4;
    final double transportationEmissionFactor = 2.5;

    // Constructor
    CarbonFootprintCalculator(double electricityUsage, double transportationEmissions) {
        super(electricityUsage, transportationEmissions);
    }

    // Method to calculate and print emissions
    void estimateCarbonEmissions() {

        double electricityCarbon = electricityUsage * electricityEmissionFactor;
        double transportationCarbon = transportationEmissions * transportationEmissionFactor;
        double total = electricityCarbon + transportationCarbon;

        System.out.printf("Electricity: %.2f kgCO2\n", electricityCarbon);
        System.out.printf("Transportation: %.2f kgCO2\n", transportationCarbon);
        System.out.printf("Total: %.2f kgCO2", total);
    }
}

// Main class
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double electricity = sc.nextDouble();
        double transportation = sc.nextDouble();

        CarbonFootprintCalculator calculator =
                new CarbonFootprintCalculator(electricity, transportation);

        calculator.estimateCarbonEmissions();
    }
}
