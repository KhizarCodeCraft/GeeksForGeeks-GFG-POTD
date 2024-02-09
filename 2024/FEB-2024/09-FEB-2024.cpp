
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 09-FEB-2024                                                                                                        *
*   Problem       : Check for Children Sum Property in a Binary Tree                                                                   *
*   Problem Link  : https://www.geeksforgeeks.org/problems/children-sum-parent/1                                                       *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Tree, Data structure, DSA, Algorithm                                                                               *
*   Company Tags  : Intuit                                                                                                             *
****************************************************************************************************************************************

Problem Statemenst 

Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

Example 1:

Input:
Binary tree
       35
      /   \
     20  15
    /  \  /  \
   15 5 10 5
Output: 
1
Explanation: 
Here, every node is sum of its left and right child.

Example 2:

Input:
Binary tree
       1
     /   \
    4    3
   /  
  5    
Output: 
0
Explanation: 
Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isSumProperty() that takes the root Node of the binary tree as input and returns 1 if all the nodes in the tree satisfy the following properties, else it returns 0.

Expected Time Complexiy: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= n <= 105
1 <= Data on nodes <= 105

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm for checking whether all nodes of a tree have the value equal to the sum of their child nodes

    isSumProperty(Node root)
    Input: Root of the tree 'root'.
    Output: 1 if all nodes in the tree have the value equal to the sum of their child nodes, otherwise 0.

    1. Define a recursive function 'check' to validate the sum property for each node in the tree.
    2. In the 'check' function:
    a. Base case: If the node is a leaf node, return true.
    b. Check if either left or right child is null, and if so, recursively check the non-null child.
    c. If both children are present, check if the sum of their data is equal to the current node's data.
    d. Recursively check the left and right subtrees, and return true only if both satisfy the sum property.
    3. Call the 'check' function to validate the sum property for the entire tree.
    4. If all nodes satisfy the sum property, return 1; otherwise, return 0.


    isSumProperty(Node* root)
    Input: Pointer to the root of a binary tree 'root'.
    Output: 1 if all nodes in the tree have the value equal to the sum of their child nodes, otherwise 0.

    1. Define a class Solution with a function check to recursively check if all nodes satisfy the sum property.
        1.1. If the node is a leaf node (i.e., both left and right children are null), return true.
        1.2. If the left child is null, recursively check the sum property of the right child:
            1.2.1. If the data of the right child matches the current node's data, recursively check the right subtree.
            1.2.2. If not, return false.
        1.3. If the right child is null, recursively check the sum property of the left child:
            1.3.1. If the data of the left child matches the current node's data, recursively check the left subtree.
            1.3.2. If not, return false.
        1.4. If both children are present, check if the sum of their data is equal to the current node's data:
            1.4.1. Recursively check both left and right subtrees.
            1.4.2. Return true only if both subtrees satisfy the sum property.
    2. Define a function isSumProperty which takes the root of the binary tree as input:
        2.1. Call the check function to validate the sum property for the entire tree.
        2.2. If all nodes satisfy the sum property, return 1; otherwise, return 0.

*/   


//  CPP Code 


class Solution {
public:
    // Function to recursively check if all nodes satisfy the sum property
    bool check(Node *node) {
        // Base case: If the node is a leaf node, return true
        if (node->left == nullptr && node->right == nullptr) {
            return true;
        }

        // If the left child is null, check the sum property of the right child
        if (node->left == nullptr) {
            // If the data of the right child matches the current node's data, recursively check the right subtree
            if (node->data == node->right->data) {
                return check(node->right);
            } else {
                return false;
            }
        }

        // If the right child is null, check the sum property of the left child
        if (node->right == nullptr) {
            // If the data of the left child matches the current node's data, recursively check the left subtree
            if (node->data == node->left->data) {
                return check(node->left);
            } else {
                return false;
            }
        }

        // If both children are present, check the sum property
        if ((node->left->data + node->right->data) == node->data) {
            // Recursively check both left and right subtrees
            bool left = check(node->left);
            bool right = check(node->right);
            // Return true only if both subtrees satisfy the sum property
            return left && right;
        }
        // If the sum property is not satisfied, return false
        return false;
    }

    // Function to check whether all nodes of a tree have the value 
    // equal to the sum of their child nodes
    int isSumProperty(Node *root) {
        // Call the check function to validate the sum property for the entire tree
        if (check(root)) {
            return 1; // If all nodes satisfy the sum property, return 1
        }
        return 0; // Otherwise, return 0
    }
};
