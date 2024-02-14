
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 14-FEB-2024                                                                                                        *
*   Problem       : Find all Critical Connections in the Graph                                                                         *
*   Problem Link  : https://www.geeksforgeeks.org/problems/critical-connections/1                                                      *
*   Difficulty    : Hard                                                                                                               *
*   Topics Tags   : Graph, Data structure, DSA, Algorithm                                                                              *
*   Company Tags  : Amazon                                                                                                             *
****************************************************************************************************************************************

Problem Statemenst 

A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges and each vertex distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than (2,1). Additionally, it is expected that you store the edges in sorted order.

Example 1:

Input:

Output:
0 1
0 2
Explanation: 
On removing edge (0, 1), you will not be able to
reach node 0 and 2 from node 1. Also, on removing
edge (0, 2), you will not be able to reach node 0
and 1 from node 2.


Example 2:

Input:

Output:
2 3
Explanation:
The edge between nodes 2 and 3 is the only
Critical connection in the given graph.


Your task:
You dont need to read input or print anything. Your task is to complete the function criticalConnections() which takes the integer v denoting the number of vertices and an adjacency list adj as input parameters and returns  a list of lists containing the Critical connections in the sorted order.

Expected Time Complexity: O(v + e)
Expected Auxiliary Space: O(v)

Constraints:
1 ≤ v, e ≤ 104

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm:
    1. Start the function `criticalConnections` with input parameters `v` (number of vertices) and `adj` (adjacency list).
    2. Initialize a set `st` to store unique critical connections.
    3. Define a DFS function to traverse the graph and find critical connections:
    - Mark the current node as visited and initialize lowTime and TOI values.
    - Traverse through adjacent nodes:
        - If the adjacent node is not visited, recursively call DFS for it.
        - Update lowTime of the current node.
        - If the TOI of the current node is less than the lowTime of the adjacent node, it's a critical connection. Insert it into the set after sorting.
    4. Initialize vectors to track visited nodes, lowTime, and TOI.
    5. Perform DFS starting from index 0.
    6. Convert the set to a vector.
    7. Return the vector containing critical connections.

*/   


//  CPP Code 

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
    // Set to store unique critical connections
    set<vector<int>> st;

    // Depth-first search (DFS) function to find critical connections
    void DFS(int ind, int parent, int &currTime, vector<int> &vis, vector<int> &lowTime, vector<int> &TOI, vector<int> adj[]) {
        // Mark the current node as visited
        vis[ind] = 1;
        // Initialize lowTime and TOI values for the current node
        lowTime[ind] = TOI[ind] = currTime++;

        // Traverse through adjacent nodes
        for (auto adjNode : adj[ind]) {
            // Skip if the adjacent node is the parent node
            if (adjNode == parent) continue;
            // If the adjacent node is not visited
            if (vis[adjNode] == 0) {
                // Recursively call DFS for the adjacent node
                DFS(adjNode, ind, currTime, vis, lowTime, TOI, adj);

                // Update lowTime of the current node
                lowTime[ind] = min(lowTime[ind], lowTime[adjNode]);

                // If the TOI of the current node is less than the lowTime of the adjacent node, it's a critical connection
                if (TOI[ind] < lowTime[adjNode]) {
                    // Create an edge vector and sort it
                    vector<int> edge = {ind, adjNode};
                    sort(edge.begin(), edge.end());
                    // Insert the sorted edge into the set
                    st.insert(edge);
                }
            } else {
                // Update lowTime of the current node
                lowTime[ind] = min(lowTime[ind], lowTime[adjNode]);
            }
        }
    }

public:
    // Function to find critical connections in the graph
    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        // Initialize vectors to track visited nodes, lowTime, and TOI (Time of Insertion)
        vector<int> vis(v, 0), lowTime(v), TOI(v);
        // Initialize current time
        int currTime = 0;
        // Perform DFS starting from index 0
        DFS(0, -1, currTime, vis, lowTime, TOI, adj);

        // Convert set to vector
        vector<vector<int>> res(st.begin(), st.end());

        // Return the vector containing critical connections
        return res;
    }
};
