
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 18-FEB-2024                                                                                                        *
*   Problem       : Sum of leaf nodes in BST                                                                                           *
*   Problem Link  : https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1                                                  *
*   Difficulty    : Easy                                                                                                               *
*   Topics Tags   : Binary Search Tree, Data structure, DSA, Algorithm                                                                 *
*   Company Tags  :                                                                                                                    *
****************************************************************************************************************************************

Problem Statemenst 

Given a Binary Search Tree with n nodes, find the sum of all leaf nodes. BST has the following property (duplicate nodes are possible):

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than or equal to the node’s key.
Your task is to determine the total sum of the values of the leaf nodes.

Note: Input array arr doesn't represent the actual BST, it represents the order in which the elements will be added into the BST.

Example 1:
Input:
n = 6
arr = {67, 34, 82, 12, 45, 78}
Output:
135
Explanation:
In first test case, the BST for the given input will be-
                67
             /     \
           34       82
          /   \    /
         12   45  78

Hence, the required sum= 12 + 45 + 78 = 135


Example 2:
Input:
n = 1
arr = {45}
Output:
45
Explanation:
As the root node is a leaf node itself, 
the required sum will be 45
Your Task:
You don't have to take any input or print anything. You are required to complete the function sumOfLeafNodes that takes root node of a BST with n nodes as parameter and returns the sum of leaf nodes. 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 104
1 <= Value of each node <= 105

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    **Algorithm:**
    1. Start the function `sumOfLeafNodes` with input parameter `root` (the root of the binary tree).
    2. If the `root` is NULL, return 0 (base case for recursion).
    3. Check if the current node (`root`) is a leaf node (both children are NULL).
    4. If it's a leaf node, return its data.
    5. Otherwise, recursively calculate the sum of leaf nodes in the left and right subtrees by calling the function on the left and right children, and return their sum.
*/   


//  CPP Code 

class Solution {
public:
    /* Function to calculate the sum of leaf nodes in a binary tree */
    int sumOfLeafNodes(Node *root) {
        /* Base case: If the root is NULL, return 0 */
        if (root == NULL)  
            return 0;

        /* If the current node is a leaf node (both children are NULL), return its data */
        if (!root->left && !root->right)  
            return root->data;

        /* Recursively calculate the sum of leaf nodes in the left and right subtrees and return their sum */
        return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
    }
};