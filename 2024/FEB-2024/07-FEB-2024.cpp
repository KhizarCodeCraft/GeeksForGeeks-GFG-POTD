
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 07-FEB-2024                                                                                                        *
*   Problem       : Min distance between two given nodes of a Binary Tree                                                              *
*   Problem Link  : https://www.geeksforgeeks.org/problems/node-at-distance/1                                                          *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Tree, Data structure, DSA, Algorithm                                                                               *
*   Company Tags  : Amazon, Samsung, MakeMy Trip, Ola Cabs, Linkedin, Qualcomm                                                         *
****************************************************************************************************************************************

Problem Statemenst 

Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum distance between them. The given two nodes are guaranteed to be in the binary tree and all node values are unique.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 
2
Explanation: 
We need the distance between 2 and 3. Being at node 2, we need to take two steps ahead in order to reach node 3. The path followed will be: 2 -> 1 -> 3. Hence, the result is 2. 

Example 2:

Input:
        11
      /   \
     22  33
    /  \  /  \
  44 55 66 77
a = 77, b = 22
Output: 
3
Explanation: 
We need the distance between 77 and 22. Being at node 77, we need to take three steps ahead in order to reach node 22. The path followed will be: 77 -> 33 -> 11 -> 22. Hence, the result is 3.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
2 <= n <= 105
1 <= Data of a node <= 109


*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm for finding the minimum distance between two nodes in a binary tree

    findDist(Node* root, int a, int b)
    Input: Pointer to the root of the binary tree 'root', and integers 'a' and 'b' representing the nodes whose distance needs to be found.
    Output: The minimum distance between nodes 'a' and 'b' in the binary tree.

    1. Initialize variables 'startNode' and 'endNode' to store 'a' and 'b' respectively.
    2. Initialize an empty unordered map 'parentMap' to store parent nodes.
    3. Initialize a pointer 'startNodeAdd' to store the address of the start node.
    4. Call the function 'nodeToParentLink(root)' to establish parent-child links in the tree.
    5. Call the function 'dfs(startNodeAdd)' to perform a depth-first search (DFS) starting from the start node address.
    6. Return the result obtained from the DFS function, which represents the minimum distance between nodes 'a' and 'b'.
    Note: The function 'dfs' recursively explores the tree while keeping track of visited nodes and their distances from the start node.


*/   


class Solution {
public:
    // Variables to store the start and end nodes
    int startNode, endNode;
    // Map to store parent nodes
    unordered_map<int, Node*> parentMap;
    // Pointer to the start node
    Node* startNodeAdd;

    // Function to establish parent-child links in the tree
    void nodeToParentLink(Node* root) {
        if (root == NULL) {
            return;
        }

        // Check if the current node is the start node
        if (root->data == startNode) {
            startNodeAdd = root; // Store the address of the start node
        }

        // Recursively establish links for left subtree
        if (root->left != NULL) {
            parentMap[root->left->data] = root; // Store the parent node
            nodeToParentLink(root->left);
        }

        // Recursively establish links for right subtree
        if (root->right != NULL) {
            parentMap[root->right->data] = root; // Store the parent node
            nodeToParentLink(root->right);
        }
    }

    // Map to track visited nodes during DFS
    unordered_map<int, bool> visited;

    // Depth-first search (DFS) function to find the minimum distance
    int dfs(Node* root) {
        // Base case: If the node is NULL or already visited, return a large value
        if (root == NULL || visited[root->data] == true) {
            return 1e7; // Infinity
        }

        // Base case: If the current node is the end node, return 0
        if (root->data == endNode) {
            return 0;
        }

        visited[root->data] = true; // Mark the current node as visited

        // Recursively explore the left subtree
        int left = dfs(root->left);
        // Recursively explore the right subtree
        int right = dfs(root->right);
        // Recursively explore the ancestor nodes
        int up = dfs(parentMap[root->data]);

        visited[root->data] = false; // Unmark the current node after backtracking

        // Return the minimum distance among left, right, and up paths, incremented by 1
        return min(left, min(right, up)) + 1;
    }

public:
    // Function to find the minimum distance between two nodes in a binary tree
    int findDist(Node* root, int a, int b) {
        // Initialize start and end node values
        startNode = a;
        endNode = b;
        // Clear the parent map and visited map
        parentMap.clear();
        visited.clear();
        // Establish parent-child links in the tree
        nodeToParentLink(root);
        // Find the minimum distance using DFS from the start node address
        return dfs(startNodeAdd);
    }
};