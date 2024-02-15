
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 15-FEB-2024                                                                                                        *
*   Problem       : Count all Possible Path                                                                                            *
*   Problem Link  : https://www.geeksforgeeks.org/problems/castle-run3644/1                                                            *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Graph, Data structure, DSA, Algorithm                                                                              *
*   Company Tags  :                                                                                                                    *
****************************************************************************************************************************************

Problem Statemenst 

You are presented with an undirected connected graph consisting of n vertices and connections between them represented by an adjacency matrix. Your objective is to determine whether it is possible to start traversing from a node, x, and return to it after traversing all the vertices at least once, using each edge exactly once.

Example 1:

Input: 
paths = 0 1 1 1 1
        1 0 0 1 0
        1 0 0 1 0
        1 1 1 0 1
        1 0 0 1 0
Output: 1
Explanation: 
One can visit the vertices in the following way:
1->3->4->5->1->4->2->1 (assuming 1-based indexing)
Here all the vertices has been visited and all
paths are used exactly once.


Example 2:

Input: 
paths = 0 1 1 0
        1 0 1 1
        1 1 0 0
        0 1 0 0
Output: 0
Explanation: 
There exists no such vertex from which all the 
vertices could be visited and all edges are used 
exactly once.


Your Task:
You don't need to read or print anything. Your task is to complete the function isPossible() which takes adjacency matrix paths as an input parameter and returns 1 if it is possible to start traversing from a node, x, and come back to it after traversing all the vertices at least once, using each edge exactly once.

 Expected Time Complexity: O(n2)
Expected Space Compelxity: O(1)

Constraints:
1 <= n <= 100
0 <= paths[i][j] <= 1
Note: paths[i][j] = 0 where i == j or there exists no edge between i and j. paths[i][j] = 1 means there is a path between i to j.

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

  Method 1 Algorithm

  Algorithm:

    Start the function isPossible with input parameter paths (a 2D vector representing paths).
    Iterate through each row (path) in the 2D vector.
    Calculate the sum of elements in each row using std::accumulate.
    Check if the sum is odd. If it's odd, return false; otherwise, continue.
    If all rows have an even sum, return true.


  Method 2  Algorithm

    Algorithm:
    
    Start the function isPossible with input parameter paths (a 2D vector representing paths).
    Get the number of rows (row) and columns (col) in the 2D vector.
    Initialize a variable count to count the number of 1s in each row.
    Iterate through each row and count the number of 1s.
    If the count of 1s is odd in any row, return 0; otherwise, continue.
    If all rows have an even count of 1s, return 1.


*/   


//  CPP Code  Method 1


#include <vector>
#include <numeric> // For std::accumulate
using namespace std;

class Solution {
public:
    // Function to check if it's possible to construct paths
    int isPossible(vector<vector<int>> paths) {
        // Iterate through each row (path)
        for (auto& row : paths) {
            // Check if the sum of elements in the row is even
            if (accumulate(row.begin(), row.end(), 0) % 2 != 0)
                return false;
        }
        return true;
    }
};

// CPP Code Method 2


#include <vector>
using namespace std;

class Solution {
public:
    // Function to check if it's possible to construct paths
    int isPossible(vector<vector<int>> paths) {
        // Get the number of rows and columns in the 2D vector
        int row = paths.size();
        int col = paths[0].size();
        int count = 0;

        // Iterate through each row
        for (int i = 0; i < row; i++) {
            // Count the number of 1s in the current row
            for (int j = 0; j < col; j++) {
                if (paths[i][j] == 1) {
                    count++;
                }
            }
            // If the count of 1s is odd in any row, return 0
            if (count % 2 != 0) {
                return 0;
            }
        }
        // If all rows have an even count of 1s, return 1
        return 1;
    }
};





