
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 01-FEB-2024                                                                                                        *
*   Problem       : Panagram Checking                                                                                                  *
*   Problem Link  : https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1                                               *
*   Difficulty    : Easy                                                                                                               *
*   Topics Tags   : Strings,Data Structures Algorithms,DSA                                                                             *
*   Company Tags  :                                                                                                                    *
****************************************************************************************************************************************

Problem Statemenst 

Given a string s check if it is "Panagram" or not.

A "Panagram" is a sentence containing every letter in the English Alphabet.

Example:

Input:
s = "Bawds jog, flick quartz, vex nymph"
Output: 
1
Explanation: 
In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.

Input:
s = "sdfs"
Output: 
0
Explanation: 
In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.

Your Task:
You do not have to take any input or print anything. You need to complete the function checkPangram() that takes a string as a parameter and returns true if the string is a Panagram, or else it returns false.

Expected Time Complexity: O( |s| )
Expected Auxiliary Space: O(1)
|s| denotes the length of the input string.

Constraints:
1 ≤ |s| ≤ 104
Both Uppercase & Lowercase are considerable

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

// Algorithm for checking Pangram

// checkPangram(string s)
// Input: A string 's'.
// Output: True if the string is a Pangram, false otherwise.
// 1. Initialize an array 'check' of size 26, to keep track of occurrences of each letter, and set all values to zero.
// 2. Iterate through each character 'ch' in the string 's':
//    a. Ignore spaces.
//    b. Increment the count of the corresponding letter (ignoring case) in the 'check' array.
// 3. Iterate through each element in the 'check' array:
//    a. If any element is zero, return false.
// 4. If all elements are non-zero, return true.

*/   

class Solution {
public:
    // Function to check if a string is a Pangram or not
    bool checkPangram(string s) {
        // Array to keep track of occurrences of each letter (initialized with zeros)
        int check[26] = {0};
        
        // Iterate through each character of the string
        for (int i = 0; i < s.length(); i++) {
            // Ignore spaces
            if (s[i] != 32)
                // Increment the count of the corresponding letter (ignore case)
                check[tolower(s[i]) - 'a']++;
        }
        
        // Check if all letters of the alphabet are present at least once
        for (int i = 0; i < 26; i++) {
            if (check[i] == 0)
                return false; // If any letter is missing, return false
        }
        return true; // If all letters are present, return true
    }
};