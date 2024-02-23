
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 19-FEB-2024                                                                                                        *
*   Problem       : Game with String                                                                                                   *
*   Problem Link  : https://www.geeksforgeeks.org/problems/game-with-string4100/1                                                      *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : String, Heap, Data structure, DSA, Algorithm                                                                       *
*   Company Tags  : Amazon                                                                                                             *
****************************************************************************************************************************************

Problem Statemenst 

Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string. 

Example 1:

Input: 
s = abccc, k = 1
Output: 
6
Explaination:
We remove c to get the value as 12 + 12 + 22

Example 2:

Input: 
s = aabcbcbcabcc, k = 3
Output: 
27
Explaination: 
We remove two 'c' and one 'b'. Now we get the value as 32 + 32 + 32.
Your Task:
You do not need to read input or print anything. Your task is to complete the function minValue() which takes s and k as input parameters and returns the minimum possible required value.

Expected Time Complexity: O(n+klog(p))  where n is the length of string and p is number of distinct alphabets and k number of alphabets to be removed. 
Expected Auxiliary Space: O(n)

Constraints:
0 ≤ k ≤ |string length| ≤ 105



*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

**Algorithm:**
1. Start the function `minValue` with input parameters `s` (the input string) and `k` (the number of characters to remove).
2. Create a map (`mp`) to store the frequency of each character in the string.
3. Count the frequency of each character in the string.
4. Store the frequencies in a vector (`v`).
5. Sort the frequencies in ascending order.
6. Remove `k` characters with the highest frequencies by decrementing their frequencies and re-sorting the vector.
7. Calculate the sum of squares of remaining frequencies.
8. Return the sum, which represents the minimum value of the string after removing `k` characters.
*/   


//  CPP Code 


class Solution {
public:
    /* Function to calculate the minimum value of string s after removing k characters */
    int minValue(string s, int k) {
        // Create a map to store the frequency of characters in the string
        unordered_map<char, int> mp;
        
        // Count the frequency of each character in the string
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        // Store the frequencies in a vector
        vector<int> v;
        for(auto it : mp) {
            v.push_back(it.second);
        }
        
        // Sort the frequencies in ascending order
        sort(v.begin(), v.end());
        
        // Remove k characters with the highest frequencies
        for(int i = 0; i < k; i++) {
            int size = v.size();
            v[size - 1] = v[size - 1] - 1; // Decrease the frequency of the character
            sort(v.begin(), v.end()); // Re-sort the frequencies
        }
        
        // Calculate the sum of squares of remaining frequencies
        int sum = 0;
        for(int i = 0; i < v.size(); i++) {
            sum += v[i] * v[i];
        }
        
        return sum; // Return the minimum value
    }
};