Single File Programming Question
Problem Statement



Akash is designing a program to count the frequency of each character in a given string. He wants your assistance in completing the program.



Create an interface named StringProcessor that includes a default method countCharacterFrequency(). The method takes a string as input and prints the frequency of each character.



Assist Akash in this task.

Input format :
The input consists of a string, It contains lowercase and uppercase letters with spaces.

Output format :
The output prints the frequency of each character in the input string.

Each character and its count is printed on a new line.

The format for each line is: "'<character>': <count>"

Characters are printed in alphabetical order, uppercase letters after spaces, and lowercase letters after uppercase.



Refer to the sample output for formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

1 < length of the string < 50

The characters are case-sensitive.

Sample test cases :
Input 1 :
maximum
Output 1 :
'a': 1
'i': 1
'm': 3
'u': 1
'x': 1
Input 2 :
Onion
Output 2 :
'O': 1
'i': 1
'n': 2
'o': 1
Input 3 :
Java Programming
Output 3 :
' ': 1
'J': 1
'P': 1
'a': 3
'g': 2
'i': 1
'm': 2
'n': 1
'o': 1
'r': 2
'v': 1
Whitelist
Set 1:
interface
default



import java.util.Scanner;
import java.util.Map;
import java.util.TreeMap;

// Interface StringProcessor with a default method
interface StringProcessor {
    // Default method to count character frequency
    default void countCharacterFrequency(String input) {
        // TreeMap ka use characters ko alphabetical order mein sort karne ke liye kiya gaya hai
        // Space, Uppercase, then Lowercase automatic handle ho jayega
        Map<Character, Integer> frequencyMap = new TreeMap<>();

        // String ke har character ko map mein count karna
        for (char ch : input.toCharArray()) {
            frequencyMap.put(ch, frequencyMap.getOrDefault(ch, 0) + 1);
        }

        // Output format: '<char>': <count>
        for (Map.Entry<Character, Integer> entry : frequencyMap.entrySet()) {
            System.out.println("'" + entry.getKey() + "': " + entry.getValue());
        }
    }
}

// Footer snippet ke hisaab se Main class interface ko implement karegi
public class Main implements StringProcessor {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input string read karna
        if (scanner.hasNextLine()) {
            String userInput = scanner.nextLine();
            
            // Interface method ko call karne ke liye Main ka object banaya gaya hai
            new Main().countCharacterFrequency(userInput);
        }
        
        scanner.close();
    }
}
