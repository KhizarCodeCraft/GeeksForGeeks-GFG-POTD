
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 10-FEB-2024                                                                                                        *
*   Problem       : Number of paths in a matrix with k coins                                                                           *
*   Problem Link  : https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1                              *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Dynamic Programming, Recursion, Matrix, Data structure, DSA, Algorithm                                             *
*   Company Tags  : Amazon                                                                                                             *
****************************************************************************************************************************************

Problem Statemenst 

Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

Example 1:

Input:
k = 12, n = 3
arr[] = [[1, 2, 3], 
       [4, 6, 5], 
       [3, 2, 1]]
Output: 
2
Explanation: 
There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).


Example 2:

Input:
k = 16, n = 3
arr[] = [[1, 2, 3], 
       [4, 6, 5], 
       [9, 8, 7]]
Output: 
0 
Explanation: 
There are no possible paths that lead to sum=16


Your Task:  
You don't need to read input or print anything. Your task is to complete the function numberOfPath() which takes n, k and 2D matrix arr[][] as input parameters and returns the number of possible paths.

Expected Time Complexity: O(n*n*k)
Expected Auxiliary Space: O(n*n*k)

Constraints:

1 <= k < 100
1 <= n < 100
0 <= arrij <= 200



*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm:

    Start the function numberOfPath with input parameters n, k, and 2D vector arr[][].
    Initialize a 3D vector dp of size n x n x k+1 to store the number of ways to collect exactly k coins at each cell.
    Define a recursive function solve to calculate the number of ways to reach the bottom-right cell from the current cell (i, j) with exactly k coins.
    Inside the solve function:
        4.1. If the current cell is out of bounds or the remaining coins (k) are negative, return 0.
        4.2. If the current cell is the bottom-right cell, return 1 if k equals the number of coins in that cell, otherwise return 0.
        4.3. If the result for the current cell and remaining coins is already calculated, return the value stored in dp.
        4.4. Recursively calculate the number of ways to reach the bottom-right cell by moving right or down from the current cell while subtracting the number of coins in the current cell from k.
    Return the result obtained from the top-left cell after calculating the number of ways using the solve function.

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
