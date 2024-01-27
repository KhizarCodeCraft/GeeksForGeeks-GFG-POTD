
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 27-JAN-2024                                                                                                        *
*   Problem       : Brackets in Matrix Chain Multiplication                                                                            *
*   Problem Link  : https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1                               *
*   Difficulty    : Hard                                                                                                               *
*   Topics Tags   : Dynamic Programming,Matrix,Algorithm,Data Structures Algorithms,DSA                                                                    *
*   Company Tags  : Microsoft                                                                                                          *
****************************************************************************************************************************************

Problem Statemenst 

Given an array p[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

NOTE:

Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also Please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
As there can be multiple possible answers, the console would print "True" for the correct string and "False" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.

Example:

Input: 
n = 5
p[] = {40, 20, 30, 10, 30}
Output: 
True
Explaination: 
Let's divide this into matrix(only 4 are possible) 
[ [40, 20] -> A
, [20, 30] -> B
, [30, 10] ->C
, [10, 30] -> D ]
First we perform multiplication of B & C -> (BC)
then we multiply A to (BC) -> (A(BC))
then we multiply D to (A(BC)) -> ((A(BC))D)
so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.


Input: 
n = 3
p = {3, 3, 3}
Output: 
True
Explaination: 
The solution returned the string (AB), which performs minimum multiplications. The total number of multiplications are (3*3*3) = 27.


Your Task:
You do not need to read input or print anything. Your task is to complete the function matrixChainOrder() which takes n and p[] as input parameters and returns the string of parenthesis for n-1 matrices. Use uppercase alphabets to denote each matrix.

Expected Time Complexity: O(n3)
Expected Auxiliary Space: O(n2)

Constraints:
2 ≤ n ≤ 26 
1 ≤ p[i] ≤ 500 
*/

class Solution
{
        
private:
    string printParenthesis(int i, int j, vector<vector<int>>& bracket) {
        if (i == j)
            return string(1, 'A' + i - 1);

        return "(" + printParenthesis(i, bracket[i][j], bracket) 
        + printParenthesis(bracket[i][j] + 1, j, bracket) + ")";
    }
    
    
public:
    string matrixChainOrder(int arr[], int N){
        // code here
        
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j)
                    dp[i][j] = 0;
            }
        }

        vector<vector<int>> bracket(N, vector<int>(N, 0));

        for (int l = 2; l < N; l++) {
            for (int i = 1; i < N - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        return printParenthesis(1, N - 1, bracket);
    }
        
};