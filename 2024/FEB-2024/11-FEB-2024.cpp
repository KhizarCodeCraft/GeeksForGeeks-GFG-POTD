
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 11-FEB-2024                                                                                                        *
*   Problem       : Recamans sequence                                                                                                  *
*   Problem Link  : https://www.geeksforgeeks.org/problems/recamans-sequence4856/1                                                     *
*   Difficulty    : Easy                                                                                                               *
*   Topics Tags   : Hash, Maths, Recursion, Data structure, DSA, Algorithm                                                             *
*   Company Tags  :                                                         *
****************************************************************************************************************************************

Problem Statemenst 

Given an integer n, return the first n elements of Recaman’s sequence.
It is a function with domain and co-domain as whole numbers. It is recursively defined as below:
Specifically, let a(n) denote the (n+1)th term. (0 being the 1st term).
The rule says:
a(0) = 0
a(n) = a(n-1) - n, if a(n-1) - n > 0 and is not included in the sequence previously
       =  a(n-1) + n otherwise.

Example 1:

Input: 
n = 5
Output: 
0 1 3 6 2
Explaination: 
a(0) = 0,
a(1) = a(0)-1 = 0-1 = -1 and -1<0, therefore a(1) = a(0)+1 = 1,
a(2) = a(1)-2 = 1-2 = -1 and -1<0, therefore a(2) = a(1)+2 = 3,
a(3) = a(2)-3 = 3-3 = 0 but since 0 is already present in the sequence, a(3) = a(2)+3 = 3+3 = 6,
a(4) = a(3)-4 = 6-4 = 2.
Therefore the first 5 elements of Recaman's sequence will be 0 1 3 6 2.


Example 2:

Input: 
n = 3
Output: 
0 1 3
Explaination: 
As seen in example 1, the first three elements will be 0 1 3.


Your Task:
You do not need to read input or print anything. Your task is to complete the function recamanSequence() which takes n as the input parameter and returns the sequence.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 105
*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

*/   


//  CPP Code 

#include <vector>
using namespace std;

class Solution {
public:
    // Recursive function to calculate the number of ways to reach the bottom-right cell with exactly k coins
    long long solve(int i, int j, int n, int k, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp) {
        // If current cell is out of bounds or remaining coins are negative, return 0
        if (i >= n || j >= n || k < 0) return 0;
        // If current cell is bottom-right cell, return 1 if k equals the number of coins in that cell, otherwise return 0
        if (i == n - 1 && j == n - 1) return k == arr[i][j];
        // If result for current cell and remaining coins is already calculated, return the value stored in dp
        if (dp[i][j][k] != -1) return dp[i][j][k];

        // Recursively calculate the number of ways to reach the bottom-right cell
        long long left = solve(i, j + 1, n, k - arr[i][j], arr, dp);
        long long down = solve(i + 1, j, n, k - arr[i][j], arr, dp);
        
        // Store the result in dp and return
        return dp[i][j][k] = left + down;
    }
    
    // Function to calculate the number of ways to collect exactly k coins while moving from top-left to bottom-right corner
    long long numberOfPath(int n, int k, vector<vector<int>>& arr) {
        // Initialize 3D vector dp to store the number of ways to collect exactly k coins at each cell
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // Calculate the number of ways using the recursive function solve
        long long ans = solve(0, 0, n, k, arr, dp);
        
        // Return the result obtained from the top-left cell
        return ans;
    }
};
