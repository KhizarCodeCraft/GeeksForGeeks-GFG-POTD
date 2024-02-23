
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 16-FEB-2024                                                                                                        *
*   Problem       : Flatten BST to sorted list                                                                                         *
*   Problem Link  : https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1                                        *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Binary Search Tree, Data structure, DSA, Algorithm                                                                 *
*   Company Tags  : Adobe, Amazon                                                                                                      *
****************************************************************************************************************************************

Problem Statemenst 

    Flatten BST to sorted list

    You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

    Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

    Example 1:

    Input:
            5
            /    \
        3      7
        /  \    /   \
        2   4  6     8
    Output: 2 3 4 5 6 7 8
    Explanation: 
    After flattening, the tree looks
    like this
        2
        \
        3
        \
            4
            \
            5
            \
                6
                \
                7
                \
                    8
    Here, left of each node points
    to NULL and right contains the
    next node.

    Example 2:

    Input:
        5
            \
            8
        /   \
        7     9  
    Output: 5 7 8 9
    Explanation:
    After flattening, the tree looks like this:
    5
        \
        7
        \
        8
            \
            9
    Your Task:
    You don't need to read input or print anything. Your task is to complete the function flattenBST() which takes root node of the BST as input parameter and returns the root node after transforming the tree.

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)

    Constraints:
    1 <= Number of nodes <= 103
    1 <= Data of a node <= 105



*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)
 
    **Algorithm:**
    1. Start the function `traversal` with input parameter `root` (the root of the binary tree).
    2. If the current node is NULL, return (base case for recursion).
    3. Get pointers to the left and right children of the current node.
    4. Recursively traverse the left subtree.
    5. If the last visited node is NULL, set the current node as the first node in the final linked list. Update the last visited node and make the left pointer of the first node NULL.
    6. If the last visited node is not NULL, set the right pointer of the last visited node to the current node. Update the last visited node and make the left pointer of the current node NULL.
    7. Recursively traverse the right subtree.

*/   


//  CPP Code 

class Solution {
public:
    Node* last = NULL; // Pointer to keep track of the last node visited
    Node* first = NULL; // Pointer to keep track of the first node in the final linked list

    // Function to perform inorder traversal and convert the binary tree to a linked list
    void traversal(Node* root) {
        if (root == NULL)
            return;

        Node* lefty = root -> left; // Pointer to the left child of the current node
        Node* righty = root -> right; // Pointer to the right child of the current node

        // Recursively traverse the left subtree
        traversal(lefty);

        // If the last node visited is NULL, it means the current node is the first node in the final linked list
        if (last == NULL) {
            first = root; // Set the first node
            root -> left = NULL; // Make the left pointer of the first node NULL
            last = root; // Update the last visited node
        } else {
            last -> right = root; // Set the right pointer of the last visited node to the current node
            last = root; // Update the last visited node
            root -> left = NULL; // Make the left pointer of the current node NULL
        }

        // Recursively traverse the right subtree
        traversal(righty);
    }
};
