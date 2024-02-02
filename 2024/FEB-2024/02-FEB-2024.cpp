
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 02-FEB-2024                                                                                                        *
*   Problem       : Implement Atoi                                                                                                     *
*   Problem Link  : https://www.geeksforgeeks.org/problems/implement-atoi/1                                                            *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Strings,Data Structures Algorithms,DSA                                                                             *
*   Company Tags  : Morgan Stanley, Amazon, Microsoft, Payu, Adobe, Code Brew                                                          *
****************************************************************************************************************************************

Problem Statemenst 

Given a string, s, the objective is to convert it into integer format without utilizing any built-in functions. If the conversion is not feasible, the function should return -1.

Note: Conversion is feasible only if all characters in the string are numeric or if its first character is '-' and rest are numeric.

Example:

Input:
s = "-123"
Output: 
-123
Explanation:
It is possible to convert -123 into an integer 
and is so returned in the form of an integer

Input:
s = "21a"
Output: 
-1
Explanation: 
The output is -1 as, due to the inclusion of 'a',
the given string cannot be converted to an integer.

Your Task:
You do not have to take any input or print anything. Complete the function atoi() which takes a string s as an input parameter and returns an integer value representing the given string. If the conversion is not feasible, the function should return -1.

|s| = length of string str.
Expected Time Complexity: O( |s| ), 
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |s| ≤ 10

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm for converting a string to an integer (atoi)

    atoi(string s)
    Input: A string 's' representing a number in string format.
    Output: The integer representation of the string.
    1. Initialize a variable 'ans' to 0 to store the final integer value.
    2. Initialize an index 'i' to iterate through the string.
    3. If the first character of the string is '-', set 'i' to 1 to skip the minus sign.
    4. Iterate through each character of the string:
    a. Check if the character is a digit (ASCII values between 48 and 57).
    b. Convert the character to its integer equivalent and update 'ans' by multiplying the current value by 10 and adding the new digit.
    c. If any character is not a digit, return -1 indicating invalid input.
    5. If the first character was '-', make 'ans' negative.
    6. Return the final integer value 'ans'.


*/   

class Solution {
public:
    // Function to convert a string to an integer (atoi)
    int atoi(string s) {
        int ans = 0; // Variable to store the final integer value
        int i = 0; // Index to iterate through the string
        
        // Check if the first character is a minus sign, indicating a negative number
        if (s[0] == '-') {
            i = 1; // Start iterating from the second character
        }
        
        // Iterate through each character of the string
        for (; i < s.length(); i++) {
            // Check if the character is a digit (ASCII values 48 to 57)
            if (s[i] >= 48 && s[i] <= 57) {
                // Convert the character to its integer equivalent
                int m = s[i] - '0';
                // Update the answer by multiplying the current value by 10 and adding the new digit
                ans = ans * 10 + m;
            } else {
                // If any character is not a digit, return -1 indicating invalid input
                return -1;
            }
        }
        
        // If the first character was a minus sign, make the answer negative
        if (s[0] == '-') {
            ans = ans * (-1);
        }
        
        // Return the final integer value
        return ans;
    }
};
