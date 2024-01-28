
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 28-JAN-2024                                                                                                        *
*   Problem       : Geekina Hate 1s                                                                                                    *
*   Problem Link  : https://www.geeksforgeeks.org/problems/geekina-hate-1s/1                                                           *
*   Difficulty    : Hard                                                                                                               *
*   Topics Tags   : Binary Search,Bit Manipulation Logic,Data Structures Algorithms,DSA                                                *
*   Company Tags  : Microsoft                                                                                                          *
****************************************************************************************************************************************

Problem Statemenst 


It is a universal fact that Geekina hates 1s however it is also known that Geekina loves the integers having atmost k 1s (set-bits) in their binary representation. 

Geekina demanded nth such non-negative number from Geek, and being a good friend of Geek, now it's your responsibility to tell him that number.

Note: The test cases are generated such that the answer always exists and will fit in the 64-bit data type.

Example:

Input:
n = 5
k = 1
Output:
8
Explanation:
Following numbers are loved by Geekina -
0 = (0)2
1 = (1)2
2 = (10)2
4 = (100)2
8 = (1000)2

Input:
n = 6
k = 2
Output:
5
Explanation:
Following numbers are loved by Geekina -
0 = (0)2
1 = (1)2
2 = (10)2
3 = (11)2
4 = (100)2
5 = (101)2

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function findNthNumer() that takes n and k as input parameters. Return the nth number having at most k set-bits.

Expected Time Complexity: O(k*log(n) + constant)
Expected Auxiliary Space: O(k*log(n) + constant)

Constraints:
1 <= n <= 109
1 <= k <= 63



*/


/*
Before seeing Code read steps and try to solve problems(Brief explanation below)

Problem Statement: Given a value of n and k, the task is to find the nth number having exactly k set bits in its binary representation.

Approach Overview:

We can utilize dynamic programming to efficiently count the numbers with k set bits.
Binary search can be applied to find the nth number efficiently.
Implementation Details:

The find function calculates the count of numbers less than or equal to n with exactly k set bits.
The dpf function recursively computes the count, considering the current digit and maintaining tightness.
Memoization is used to avoid redundant calculations.
The findNthNumber function performs binary search to find the nth number.
Key Steps:

Convert n to a binary string to facilitate digit-wise processing.
Use binary search to find the nth number efficiently.
Compute the count of numbers less than or equal to mid with exactly k set bits using dynamic programming.
Output: The program outputs the nth number with k set bits.

*/


class Solution {
public:
    vector<vector<vector<long long>>> dp; // Dynamic programming table
    
private:
    // Helper function to find the count of numbers less than or equal to n
    long long find(long long n, int k){
        string s = bitset<64>(n).to_string(); // Convert n to binary string
        reset(); // Reset dynamic programming table
        return dpf(s, s.length(), 1, k); // Call recursive function to compute count
    }
    
    // Recursive function to compute count of valid numbers
    long long dpf(string s, int n, int tight, int k){
        if(k < 0) // Base case: If k is negative, return 0
            return 0;
        if(n == 0){ // Base case: If string length becomes 0, return 1
            return 1;
        }
        if(dp[tight][k][n] != -1) // If value is already computed, return it
            return dp[tight][k][n];
        int ub = (tight == 1 ? (int)(s[s.length() - n] - '0') : 1); // Set upper bound based on tightness
        long long res = 0;
        for(int dig = 0; dig <= ub; dig++){ // Iterate over possible digits
            if(dig == ub) // If digit is equal to upper bound, continue with tightness
                res += dpf(s, n - 1, tight, k - dig);
            else // Otherwise, set tightness to 0
                res += dpf(s, n - 1, 0, k - dig);
        }
        return dp[tight][k][n] = res; // Memoize and return result
    }
    
    // Helper function to reset the dynamic programming table
    void reset(){
        for(int i = 0; i < 65; i++){
            for(int j = 0; j < 65; j++){
                dp[0][i][j] = dp[1][i][j] = -1;
            }
        }
    }
    
public:
    // Main function to find the nth number with k set bits
    long long findNthNumber(int n, int k) {
        long long low = 0, high = 1e18; // Set initial search range
        dp = vector<vector<vector<long long>>>(2, vector<vector<long long>>(65, vector<long long>(65, -1))); // Initialize dynamic programming table
        while(low <= high){ // Binary search loop
            long long mid = low + (high - low) / 2; // Compute mid value
            long long count = find(mid, k); // Get count of valid numbers less than or equal to mid
            if(count >= n) // If count is greater than or equal to n, adjust search range
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low; // Return the final result
    }
};










