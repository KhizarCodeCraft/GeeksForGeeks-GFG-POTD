
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 30-JAN-2024                                                                                                        *
*   Problem       : LCS of three strings                                                                                               *
*   Problem Link  : https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1                                                  *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : String,Dynamic Programmin,Data Structures Algorithms,DSA                                                           *
*   Company Tags  : DE Shaw                                                                                                            *
****************************************************************************************************************************************

Problem Statemenst 

Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

Example:
Input:
A = "geeks"
B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: 
"geeks"is the longest common
subsequence with length 5.

Input: 
A = "abcd"
B = "efgh"
C = "ijkl"
Output: 0
Explanation: 
There's no subsequence common
in all the three strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

Constraints:
1 <= n1, n2, n3 <= 20
Elements of the strings consitutes only of the lower case english alphabets.

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

Define a function LCSof3 that takes three strings A, B, and C, along with their lengths n1, n2, and n3 as input.
Initialize a 3D array dp to store lengths of longest common subsequences.
Iterate through all combinations of lengths of substrings of A, B, and C.
At each iteration:
If any of the strings is empty, set LCS length to 0.
If characters at current indices match, increment LCS length by 1.
If characters don't match, LCS length is the maximum of LCS without the current character.
Return length of LCS of entire strings A, B, and C.


*/


class Solution{

     public:

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here

            // Initialize a 3D array to store lengths of longest common subsequences
            int dp[n1+1][n2+1][n3+1];
            
            // Iterate through all combinations of lengths of substrings of A, B, and C
            for (int i = 0; i <= n1; i++) {
                for (int j = 0; j <= n2; j++) {
                    for (int k = 0; k <= n3; k++) {
                        // Base case: If any of the strings is empty, LCS length is 0
                        if (i == 0 || j == 0 || k == 0)
                            dp[i][j][k] = 0;
                        // If characters at current indices match, increment LCS length by 1
                        else if (A[i - 1] == B[j - 1] && A[i - 1] == C[k - 1])
                            dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                        // If characters don't match, LCS length is maximum of LCS without current character
                        else
                            dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                    }
                }
            }
            // Return length of LCS of entire strings A, B, and C
            return dp[n1][n2][n3];

        }
};

