
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 08-FEB-2024                                                                                                        *
*   Problem       : Check if all leaves are at same level                                                                              *
*   Problem Link  : https://www.geeksforgeeks.org/problems/leaf-at-same-level/1                                                        *
*   Difficulty    : Easy                                                                                                               *
*   Topics Tags   : Tree, Data structure, DSA, Algorithm                                                                               *
*   Company Tags  : Amazon                                                                                                             *
****************************************************************************************************************************************

Problem Statemenst 

Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

Example 1:

Input:
Tree:
    1
   / \
  2   3
Output:
true
Explanation:
The binary tree has a height of 2 and the leaves are at the same level.

Example 2:

Input:
Tree:
    10
   /  \
 20   30
 /  \
 10   15
Output:
false
Explanation:
The binary tree has a height of 3 and the leaves are not at the same level.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)

Your Task:
Implement the function check() that checks whether all the leaf nodes in the given binary tree are at the same level or not. The function takes the root node of the tree as an input and should return a boolean value (true/false) based on the condition.

Constraints:
1 ≤ n ≤ 105

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    check(Node* root)
    Input: Pointer to the root of the binary tree 'root'.
    Output: True if all leaf nodes in the binary tree are at the same level, otherwise false.

    1. Calculate the maximum level in the binary tree using the 'lvl' function.
    2. Subtract 1 from the maximum level to get the level of leaf nodes.
    3. Call the 'traverse' function to recursively traverse the binary tree and check if all leaf nodes are at the same level.
    4. Return the result obtained from the 'traverse' function, which indicates whether all leaf nodes are at the same level or not.
    Note: The 'lvl' function calculates the maximum level in the binary tree, and the 'traverse' function recursively checks if all leaf nodes are at the same level.

*/   


//  CPP Code 

class Solution {
public:
    // Function to calculate the maximum level in the binary tree
    int lvl(Node* root, int dis) {
        if (root == NULL) 
            return dis;
        // Recursively calculate the maximum level in the left and right subtrees
        int left = lvl(root->left, dis + 1);
        int right = lvl(root->right, dis + 1);
        // Return the maximum of left and right levels
        return max(left, right);
    }

    // Function to traverse the binary tree and check if all leaf nodes are at the same level
    bool traverse(Node* root, int level, int curr) {
        if (root == NULL) 
            return true;
        // If the current node is a leaf node, check if its level is equal to the maximum level
        if (root->left == NULL && root->right == NULL) 
            return (level == curr) ? true : false;
        // Recursively check if all leaf nodes in the left and right subtrees are at the same level
        return traverse(root->left, level, curr + 1) && traverse(root->right, level, curr + 1);
    }

    // Function to check if all leaf nodes in the binary tree are at the same level
    bool check(Node* root) {
        // Calculate the maximum level in the binary tree
        int level = lvl(root, 0) - 1;
        // Check if all leaf nodes are at the same level
        return traverse(root, level, 0);
    }
};