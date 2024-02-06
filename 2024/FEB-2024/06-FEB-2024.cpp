
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 06-FEB-2024                                                                                                        *
*   Problem       : Count the nodes at distance K from leaf                                                                            *
*   Problem Link  : https://www.geeksforgeeks.org/problems/node-at-distance/1                                                          *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Tree, Data structure, DSA, Algorithm                                                                               *
*   Company Tags  : Flipkart, Microsoft                                                                                                *
****************************************************************************************************************************************

Problem Statemenst 

Given a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes.
A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.

Note: Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to our count.

Example 1:

Input:
Binary tree
        1
      /   \
     2     3
   /  \   /  \
  4   5  6    7
          \ 
          8
k = 2
Output: 
2
Explanation: 
There are only two unique nodes that are at a distance of 2 units from the leaf node. (node 3 for leaf with value 8 and node 1 for leaves with values 4, 5 and 7) Note that node 2 isn't considered for leaf with value 8 because it isn't a direct ancestor of node 8.


Example 2:

Input:
Binary tree
          1
         /
        3
       /
      5
    /  \
   7    8
         \
          9
k = 4
Output: 
1
Explanation: 
Only one node is there which is at a distance of 4 units from the leaf node.(node 1 for leaf with value 9) 


Your Task:
You don't have to read input or print anything. Complete the function printKDistantfromLeaf() that takes root node and k as inputs and returns the number of nodes that are at distance k from a leaf node. 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= n <= 105


*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm for counting nodes at a given distance from leaf nodes

    printKDistantfromLeaf(Node* root, int k)
    Input: Pointer to the root of the binary tree 'root', and an integer 'k' representing the distance.
    Output: The count of nodes at a distance 'k' from the leaf nodes in the binary tree.
    1. Initialize an empty unordered set 's' to store unique ancestor nodes.
    2. Initialize the current level of the tree 'level' to 0.
    3. Initialize an empty vector 'v' to store the path from the root to the current node.
    4. Call the recursive function 'solve(root, k, level, v, s)' to traverse the tree and find nodes at a given distance.
    5. Return the size of the set 's', which represents the count of unique ancestor nodes at a distance 'k' from leaf nodes.
    Note: The recursive function 'solve' traverses the tree in a depth-first manner and updates the set 's' with unique ancestor nodes.
    

*/   

class Solution {
public:
    // Recursive function to traverse the tree and find nodes at a given distance from leaf nodes
    void solve(Node* root, int k, int level, vector<Node*>& v, unordered_set<Node*>& s) {
        // Base case: If the node is NULL, return
        if (root == nullptr) {
            return;
        }
        
        // Add the current node to the path
        v.push_back(root);
        
        // Check if the current node is a leaf node and the distance is valid
        if (root->left == nullptr && root->right == nullptr && (level - k) >= 0) {
            // Get the ancestor node at the required distance
            Node* ele = v[level - k];
            // Insert the ancestor node into the set if not already present
            if (s.count(ele) == 0) {
                s.insert(ele);
            }
        }
        
        // Recur for the left and right subtrees with updated level
        solve(root->left, k, level + 1, v, s);
        solve(root->right, k, level + 1, v, s);
        
        // Backtrack: Remove the current node from the path
        v.pop_back();
    }
    
    // Function to return count of nodes at a given distance from leaf nodes
    int printKDistantfromLeaf(Node* root, int k) {
        // Initialize an unordered set to store unique ancestor nodes
        unordered_set<Node*> s;
        // Initialize the current level of the tree
        int level = 0;
        // Initialize a vector to store the path from root to leaf
        vector<Node*> v;
        // Call the recursive function to traverse the tree and find nodes at a given distance
        solve(root, k, level, v, s);
        // Return the size of the set containing unique ancestor nodes
        return s.size();
    }
};