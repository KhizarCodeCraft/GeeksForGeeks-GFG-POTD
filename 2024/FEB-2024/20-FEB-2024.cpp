
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 20-FEB-2024                                                                                                        *
*   Problem       : Word Break                                                                                                         *
*   Problem Link  : https://www.geeksforgeeks.org/problems/word-break1352/1                                                            *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Dynamic Programming, Data structure, DSA, Algorithm                                                                *
*   Company Tags  : Zoho, Flipkart, Amazon, Microsoft, Hike, Walmart, MAQ Software, Google, IBM                                        *
****************************************************************************************************************************************

Problem Statemenst 

Given a string s and a dictionary of n words dictionary, find out if "s" can be segmented into a space-separated sequence of dictionary words.
Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

Note: From the dictionary dictionary each word can be taken any number of times and in any order.

Example 1:

Input:
n = 6
s = "ilike"
dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
Output:
1
Explanation:
The string can be segmented as "i like".

Example 2:

Input:
n = 6
s = "ilikesamsung"
dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
Output:
1
Explanation:
The string can be segmented as 
"i like samsung" or "i like sam sung".
Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else returns 0. You don't need to read any input or print any output, it is done by driver code.

Expected Time Complexity: O(len(s)2)
Expected Space Complexity: O(len(s))

Constraints:
1 ≤ n ≤ 12
1 ≤ len(s) ≤ 1100


*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    **Algorithm:**
    1. Start the function `wordBreak` with input parameters `n` (length of the input string), `s` (the input string), and `dictionary` (vector of strings representing the dictionary).
    2. Base case: If the string is empty (`s == ""`), return 1, indicating that it can be broken into words.
    3. Iterate through the dictionary to find matching prefixes for the string.
    4. For each word in the dictionary, check if it matches the prefix of the string (`s.substr(0, it.size())`).
    5. If a match is found, recursively call the `wordBreak` function with the remaining substring after removing the matched prefix.
    6. If the recursive call returns 1 (indicating that the remaining substring can be broken into words), return 1.
    7. If no match is found in the dictionary, return 0, indicating that the string cannot be broken into words.
*/   


//  CPP Code 

class Solution {
public:
    /* Function to check if a string can be broken into words from the given dictionary */
    int wordBreak(int n, string s, vector<string> &dictionary) {
        // Base case: If the string is empty, it can be broken into words
        if(s == "") 
            return 1;
        
        // Iterate through the dictionary to find matching prefixes
        for(auto it : dictionary) {
            // Check if the current word in the dictionary matches the prefix of the string
            if(it == s.substr(0, it.size())) {
                // Recursively check if the remaining substring can be broken into words
                if(wordBreak(n, s.substr(it.size()), dictionary)) 
                    return 1; // If yes, return 1
            }
        }
        
        // If no match is found in the dictionary, return 0
        return 0;
    }
};