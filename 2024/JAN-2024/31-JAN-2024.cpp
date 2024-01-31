
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 31-JAN-2024                                                                                                        *
*   Problem       : Insert and Search in a Trie                                                                                        *
*   Problem Link  : https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1                                                *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Trie,Design Pattern,Data Structures Algorithms,DSA                                                                 *
*   Company Tags  : Accolite,Amazon,Microsoft,D-E-Shaw,FactSet                                                                         *
****************************************************************************************************************************************

Problem Statemenst 

Complete the Insert and Search functions for a Trie Data Structure. 

Insert: Accepts the Trie's root and a string, modifies the root in-place, and returns nothing.
Search: Takes the Trie's root and a string, returns true if the string is in the Trie, otherwise false.
Note: To test the correctness of your code, the code-judge will be inserting a list of N strings called into the Trie, and then will search for the string key in the Trie. The code-judge will generate 1 if the key is present in the Trie, else 0.


Example:

Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = the
Output: 1
Explanation: 
"the" is present in the given set of strings. 


Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = geeks
Output: 0
Explanation: 
"geeks" is not present in the
given set of strings.

Your Task:
You do not have to take any input or print anything. Complete insert and search functions. 

Expected Time Complexity: O(M+|key|)
Expected Auxiliary Space: O(M)
Here M = sum of the length of all strings which are present in the list[] 

Constraints:
1 <= N <= 104
1 <= length of list[i] <= 30
All strings will constitute of lowercase alphabets only.

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm for Trie data structure operations

    insert(struct TrieNode* root, string key)
    Input: A pointer to the root of the Trie data structure and a string key to be inserted.
    Output: None
    1. Iterate through each character 'ch' in the string 'key':
    a. If the character 'ch' doesn't have a child TrieNode in the current TrieNode, create a new TrieNode.
    b. Move to the child TrieNode corresponding to the character 'ch'.
    2. Mark the last TrieNode as the end of the word.

    search(struct TrieNode* root, string key)
    Input: A pointer to the root of the Trie data structure and a string key to be searched.
    Output: True if the key exists in the Trie, false otherwise.
    1. Iterate through each character 'ch' in the string 'key':
    a. If the character 'ch' doesn't have a child TrieNode in the current TrieNode, return false.
    b. Move to the child TrieNode corresponding to the character 'ch'.
    2. Check if the last TrieNode is marked as the end of a word. If yes, return true; otherwise, return false.


*/

// Definition of TrieNode structure
// struct TrieNode {
//     TrieNode* children[26]; // Array to hold children nodes for each character
//     bool isLeaf; // Flag to indicate if the node is the end of a word

//     // Constructor to initialize TrieNode
//     TrieNode() {
//         for (int i = 0; i < 26; i++) {
//             children[i] = nullptr;
//         }
//         isLeaf = false;
//     }
// };

class Solution {
public:
    // Function to check if a character is present as a child of a TrieNode
    bool containsKey(char a, struct TrieNode* root) {
        return root->children[a - 'a'] != NULL;
    }

    // Function to add a new TrieNode as a child of a TrieNode
    void put(char a, struct TrieNode* Node, struct TrieNode* root) {
        root->children[a - 'a'] = Node;
    }

    // Function to get the child TrieNode corresponding to a character
    TrieNode* get(char a, struct TrieNode* Node) {
        return Node->children[a - 'a'];
    }

    // Function to mark a TrieNode as the end of a word
    void setEnd(struct TrieNode* Node) {
        Node->isLeaf = true;
    }

    // Function to insert a word into the Trie data structure
    void insert(struct TrieNode* root, string key) {
        // Iterate through each character of the word
        for (int i = 0; i < key.length(); i++) {
            // If the character is not present as a child, add a new TrieNode
            if (!containsKey(key[i], root)) {
                put(key[i], new TrieNode(), root);
            }
            // Move to the next TrieNode corresponding to the character
            root = get(key[i], root);
        }
        // Mark the last TrieNode as the end of the word
        setEnd(root);
    }

    // Function to search for a word in the Trie data structure
    bool search(struct TrieNode* root, string key) {
        // Iterate through each character of the word
        for (int i = 0; i < key.length(); i++) {
            // If the character is not present as a child, the word doesn't exist
            if (!containsKey(key[i], root))
                return false;
            // Move to the next TrieNode corresponding to the character
            root = get(key[i], root);
        }
        // Check if the last TrieNode is marked as the end of a word
        return root->isLeaf;
    }
};

