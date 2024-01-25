
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 22-JAN-2024                                                                                                        *
*   Problem       : Paths from root with a specified sum                                                                               *
*   Problem Link  : https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1                                      *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : DSA,Graph                                                                                                          *
*   Company Tags  : Microsoft                                                                                                          *
****************************************************************************************************************************************

Problem Statemenst 
Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum.
Path not necessarily end on a leaf node.

Example

Input :                                        
sum = 8
Input tree
         1
       /   \
     20      3
           /    \
         4       15   
        /  \     /  \
       6    7   8    9      

Output :
1 3 4
Explanation : 
Sum of path 1, 3, 4 = 8.

Input : 
sum = 38
Input tree
          10
       /     \
     28       13
           /     \
         14       15
        /   \     /  \
       21   22   23   24
Output :
10 28
10 13 15  
Explanation :
Sum of path 10, 28 = 38 and
Sum of path 10, 13, 15 = 38.

Your task :
You don't have to read input or print anything. 
Your task is to complete the function printPaths() that takes the root of the tree and sum as input
 and returns a vector of vectors containing the paths that lead to the sum.
 
Expected Time Complexity: O(N)
Expected Space Complexity: O(N2)

*/

class Solution
{   public:
    void FindingNodes(Node* root, int sum, vector<vector<int>> &sol, vector<int> &nodes, int &sum1) {
    // Base case: If the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Include the current node in the path
    nodes.push_back(root->key);
    sum1 += root->key;

    // Check if the current path sums up to the target sum
    if (sum1 == sum) {
        // If yes, add the current path to the solution matrix
        sol.push_back(nodes);
    }

    // Recur for the left subtree
    if (root->left != NULL) {
        FindingNodes(root->left, sum, sol, nodes, sum1);
    }

    // Recur for the right subtree
    if (root->right != NULL) {
        FindingNodes(root->right, sum, sol, nodes, sum1);
    }

    // Backtrack: Exclude the current node from the path
    sum1 -= root->key;
    nodes.pop_back();
    }
    
    
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
         // Initialize the solution matrix and auxiliary vector for storing current path
        vector<vector<int>> matrix;
        vector<int> nodes;
        int sum1 = 0; // Variable to track the current sum in the path
    
        // Call the recursive function to find paths
        FindingNodes(root, sum, matrix, nodes, sum1);
    
        // Return the solution matrix containing all paths
        return matrix;
    }
};