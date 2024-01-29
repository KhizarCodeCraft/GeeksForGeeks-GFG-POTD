
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 29-JAN-2024                                                                                                        *
*   Problem       : Count digit groupings of a number                                                                                  *
*   Problem Link  : https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1                                     *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Dynamic Programmin,Data Structures Algorithms,DSA                                                                  *
*   Company Tags  :                                                                                                                    *
****************************************************************************************************************************************

Problem Statemenst 

Given a string str consisting of digits, you can divide it into sub-groups by separating the string into substrings. For example, "112" can be divided as {"1", "1", "2"}, {"11", "2"}, {"1", "12"}, and {"112"}.

A valid grouping can be done if you are able to divide sub-groups where the sum of digits in a sub-group is less than or equal to the sum of the digits of the sub-group immediately right to it. Your task is to determine the total number of valid groupings that could be done for a given string.

Example:

Input: 
str = "1119"
Output: 
7
Explanation: 
One valid grouping is {"1", "11", "9"}.
Sum of digits of first sub-group ("1") is 1,
for the second sub-group ("11"), it is 2,
and for the third one ("9"), it is 9.
As the sum of digits of the sub-groups is 
in increasing order, it forms a valid grouping.
Other valid grouping are {"1", "119"}, {"1","1","19"}, 
{"1","1","1","9"}, {"11","19"}, {"111","9"} and {"1119"}
are six other valid groupings.


Input: 
str = "12"
Output: 
2
Explanation: 
{"1","2"} and {"12"} are two valid groupings.

Your Task:
You don't need to read or print anything. Your task is to complete the function TotalCount() which takes the string str as input parameter and returns total possible groupings.

Expected Time Complexity: O(N3) where N is the length of the string.
Expected Space Complexity: O(N2)

Constraints:
1 <= N <= 100
stri ∈ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}



*/


/*
Before seeing Code read steps and try to solve problems(Brief explanation below)

Algorithm: TotalCount(string str)
Input: A string 'str' containing digits

1. Initialize a variable 'needed' to 0.
2. Initialize a variable 'sum' to 0.
3. Iterate through each character in the string 'str':
   a. Add the integer value of the character to 'sum'.
4. Create a 2D vector 'dp' of size str.size() × (sum + 1) and initialize all values to -1.
5. Call the function solve(str, 0, str.size() - 1, needed, dp).

Function solve(string &str, int i, int j, int needed, vector<vector<int>>& dp)
Input:
   - A reference to the input string 'str'.
   - Two integers 'i' and 'j' representing the start and end indices of the current substring.
   - An integer 'needed' representing the required sum of digits.
   - A reference to the dynamic programming table 'dp'.
Output: The count of substrings satisfying the condition.

1. Base Case:
   a. If i > j, return 1. // An empty substring is considered valid.
   b. If i == j, return 1 if the digit at index 'i' is greater than or equal to 'needed', else return 0.

2. If dp[i][needed] is not -1, return dp[i][needed] (memoization).

3. Initialize an empty string 's', a variable 'sum' to 0, and a variable 'ans' to 0.

4. Iterate through each character in the substring from index 'i' to 'j':
   a. Append the character to the string 's'.
   b. Add the integer value of the character to 'sum'.
   c. If 'sum' is greater than or equal to 'needed':
      i. Recursively call solve with parameters (str, k + 1, j, sum, dp) and add the result to 'ans'.

5. Memoize the result by assigning 'ans' to dp[i][needed].

6. Return 'ans'.

Output: Return the result obtained from solve(str, 0, str.size() - 1, needed, dp).




*/


class Solution {
public:
    // Function to recursively solve the problem
    int solve(string &str, int i, int j, int needed, vector<vector<int>>& dp) {
        // Base cases
        if (i > j) {
            return 1; // If substring is empty, return 1
        }
        if (i == j) {
            // If substring has only one digit, return 1 if it's greater than or equal to 'needed', else return 0
            return ((str[i] - '0') >= needed) ? 1 : 0;
        }
        if (dp[i][needed] != -1) {
            return dp[i][needed]; // If result is already computed, return it
        }
        string s = ""; // Temporary string to store substrings
        int sum = 0; // Sum of digits in the substring
        int ans = 0; // Accumulator for the result
        // Iterating through all possible substrings
        for (int k = i; k <= j; k++) {
            s.push_back(str[k]); // Add current digit to the temporary string
            sum += (str[k] - '0'); // Update the sum
            if (sum >= needed) {
                // If sum is greater than or equal to 'needed', recursively solve the substring from k+1 onwards
                ans += solve(str, k + 1, j, sum, dp);
            }
        }
        return dp[i][needed] = ans; // Memoize the result and return
    }
    
    // Function to compute the total count of substrings satisfying the conditions
    int TotalCount(string str) {
        int needed = 0; // Initial value of 'needed'
        int sum = 0; // Initialize sum of digits
        for (int i = 0; i < str.size(); i++) {
            sum += (str[i] - '0'); // Compute the sum of digits in the string
        }
        // Initialize the DP table with -1
        vector<vector<int>> dp(str.size(), vector<int>(sum + 1, -1));
        // Call the recursive function to solve the problem
        return solve(str, 0, str.size() - 1, needed, dp);
    }
};