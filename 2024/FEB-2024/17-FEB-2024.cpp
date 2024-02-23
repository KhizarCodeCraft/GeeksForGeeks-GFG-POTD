
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 17-FEB-2024                                                                                                        *
*   Problem       : Does array represent Heap                                                                                          *
*   Problem Link  : https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1                                             *
*   Difficulty    : Easy                                                                                                               *
*   Topics Tags   : Array, Binary Search Tree, Data structure, DSA, Algorithm                                                          *
*   Company Tags  : Cisco                                                                                                              *
****************************************************************************************************************************************

Problem Statemenst 

Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.

Example 1:

Input:
n = 6
arr[] = {90, 15, 10, 7, 12, 2}
Output: 
1
Explanation: 
The given array represents below tree
       90
     /    \
   15      10
  /  \     /
7    12  2
The tree follows max-heap property as every
node is greater than all of its descendants.

Example 2:
Input:  
n = 6
arr[] = {9, 15, 10, 7, 12, 11}
Output:
0
Explanation:
The given array represents below tree
       9
     /    \
   15      10
  /  \     /
7    12  11
The tree doesn't follows max-heap property 9 is
smaller than 15 and 10, and 10 is smaller than 11. 
Your Task:  
You don't need to read input or print anything. Your task is to complete the function isMaxHeap() which takes the array arr[] and its size n as inputs and returns True if the given array could represent a valid level order representation of a Max Heap, or else, it will return False.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 105
1 ≤ arri ≤ 105

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    **Algorithm:**
    1. Start the function `isMaxHeap` with input parameters `arr[]` (the array representing the heap) and `n` (the size of the array).
    2. Iterate through each node (element) in the array.
    3. For each node, check if it has a left child (`i * 2 + 1`) or a right child (`i * 2 + 2`), and if the current node's value is less than either of its children.
    4. If any violation of the max heap property is found, return false.
    5. If no violation is found for any node, return true, indicating that the array represents a max heap.
*/   


//  CPP Code 

class Solution {
public:
    // Function to check if the given array represents a max heap
    bool isMaxHeap(int arr[], int n) {
        // Iterate through each node in the array
        for(int i = 0; i < n; i++) {
            // Check if the current node has a left child or a right child, and if it violates the max heap property
            if ((i * 2 + 1 < n || i * 2 + 2 < n) && (arr[i] < arr[i * 2 + 1] || arr[i] < arr[i * 2 + 2]))
                return false; // If violated, return false
        }
        return true; // If no violation found, return true (the array represents a max heap)
    }
};