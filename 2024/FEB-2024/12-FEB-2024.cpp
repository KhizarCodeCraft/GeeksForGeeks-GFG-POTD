
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 12-FEB-2024                                                                                                        *
*   Problem       : Recursive sequence                                                                                                 *
*   Problem Link  : https://www.geeksforgeeks.org/problems/recursive-sequence1611/1                                                    *
*   Difficulty    : Easy                                                                                                               *
*   Topics Tags   : Maths, Recursion, Data structure, DSA,                                                                             *
*   Company Tags  : MAQ Software                                                                                                       *
****************************************************************************************************************************************

Problem Statemenst 

A function F is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... upto n terms (look at the examples for better clarity). Given an integer n, determine the F(n).

Note: As the answer can be very large, return the answer modulo 109+7.

Example 1:

Input: n = 5
Output: 365527
Explanation: 
F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 = 365527.

Example 2:

Input: n = 7
Output: 6006997207
Explanation: 
F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 + 11*12*13*14*15 + 
16*17*18*19*20*21 + 22*23*24*25*26*27*28 = 6006997207.
6006997207 % 109+7 = 6997165


Your Task:
You do not need to read input or print anything. Your task is to complete the function sequence() which takes an integer n as an input parameter and returns the value of F(n).

Expected Time Complexity: O(n2)
Expected Space Complexity: O(1)

Constraints:
1 ≤ n ≤ 103

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm:

    Start the function sequence with input parameter n.
    Initialize variables mod, cnt, and ans to store the modulo value, count, and answer respectively.
    Iterate from 1 to n:
    3.1. Initialize temp as 1.
    3.2. Iterate from 1 to i:
    3.2.1. Increment cnt to keep track of the total count.
    3.2.2. Update temp by multiplying it with cnt and taking the modulo with mod.
    3.3. Update ans by adding temp and taking the modulo with mod.
    Return ans.

*/   


//  CPP Code 

class Solution {
public:
    // Function to generate the sequence for a given value of n
    long long sequence(int n) {
        // Define the modulo value
        int mod = 1e9 + 7;
        // Initialize count and answer variables
        int cnt = 0;
        long long ans = 0;

        // Iterate from 1 to n
        for (int i = 1; i <= n; i++) {
            // Initialize temporary variable to store the product
            long long temp = 1;

            // Iterate from 1 to i
            for (int j = 1; j <= i; j++) {
                // Increment count to keep track of the total count
                cnt++;
                // Update temp by multiplying it with cnt and taking modulo with mod
                temp = (temp * cnt) % mod;
            }

            // Update ans by adding temp and taking modulo with mod
            ans = (ans + temp) % mod;
        }

        // Return the generated sequence
        return ans;
    }
};
