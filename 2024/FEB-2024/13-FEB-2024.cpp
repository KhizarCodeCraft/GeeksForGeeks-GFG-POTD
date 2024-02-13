
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 13-FEB-2024                                                                                                        *
*   Problem       : Clone an Undirected Graph                                                                                          *
*   Problem Link  : https://www.geeksforgeeks.org/problems/clone-graph/1                                                               *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Graph, DFs, BFS, Data structure, DSA, Algorithm                                                                    *
*   Company Tags  : Google                                                                                                             *
****************************************************************************************************************************************

Problem Statemenst 

Given a connected undirected graph with n nodes and m edges, with each node having a distinct label from 0 to n-1, create a clone of the graph. Each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

Note: If the user returns a correct copy of the given graph, then the system will print 1; in the case when an incorrect copy is generated or when the user returns the original node, the system will print 0.

For Example :    

class Node {
    val: integer
    neighbors: List[Node]
}

Example 1:

Input:
adjList = 
{
    {1, 3},
    {0, 2},
    {1, 3},
    {0, 2}
}
Output: 1
Explanation:
1 is the output that the driver code will print in case 
you successfully cloned the given graph.

Example 2:

Input:
adjList = 
{
    {1},
    {0}
}
Output: 1
Explanation: 
1 is the output that the driver code will print in case
you successfully cloned the given graph.

Your Task:
You don't need to read input or print anything. Your task is to complete the function cloneGraph( ) which takes a node will always be the first node of the graph as input and returns the copy of the given node as a reference to the cloned graph.

Expected Time Complexity: O(n + m).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n, m <= 104
1 <= Node value <= n

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)


        Below is the algorithm along with the C++ implementation for the provided problem:

        Algorithm:

        Start the function cloneGraph with input parameter node.
        Create a HashMap mp to map original nodes to their corresponding clone nodes.
        Create a clone node for the given node and add it to the HashMap.
        Initialize a queue q and push the original node into it.
        While the queue is not empty, do the following:
        5.1. Pop a node node from the queue.
        5.2. Get the corresponding clone node cloneNode from the HashMap.
        5.3. Iterate through the neighbors of node.
        5.4. For each neighbor n, if n is not in the HashMap:
        5.4.1. Create a clone node for n.
        5.4.2. Add n and its clone to the HashMap.
        5.4.3. Add the clone node to the neighbors of cloneNode.
        5.4.4. Push n into the queue.
        5.5. If n is already in the HashMap, add its clone node to the neighbors of cloneNode.
        Return the clone node of the given node.


*/   


//  CPP Code 

class Solution {
public:
    // HashMap to store mapping between original nodes and their corresponding clone nodes
    unordered_map<Node*, Node*> mp;

    // Function to clone the graph using BFS
    Node* cloneGraph(Node* node) {
        // If input node is null, return null
        if (!node) return nullptr;
        
        // Create a clone node for the given node and add it to the HashMap
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;
        
        // Initialize a queue and push the original node into it
        queue<Node*> q;
        q.push(node);
        
        // BFS to traverse the graph and clone nodes
        while (!q.empty()) {
            // Pop a node from the queue
            Node* currNode = q.front();
            q.pop();
            
            // Get the corresponding clone node from the HashMap
            Node* currCloneNode = mp[currNode];
            
            // Iterate through the neighbors of the current node
            for (Node* neighbor : currNode->neighbors) {
                // If the neighbor is not in the HashMap, create a clone node for it
                if (mp.find(neighbor) == mp.end()) {
                    Node* cloneNeighbor = new Node(neighbor->val);
                    mp[neighbor] = cloneNeighbor;
                    // Add the clone node to the neighbors of the current clone node
                    currCloneNode->neighbors.push_back(cloneNeighbor);
                    // Push the neighbor into the queue for further processing
                    q.push(neighbor);
                } else {
                    // If the neighbor is already in the HashMap, add its clone node to the neighbors of the current clone node
                    currCloneNode->neighbors.push_back(mp[neighbor]);
                }
            }
        }
        
        // Return the clone node of the given node
        return cloneNode;
    }
};

