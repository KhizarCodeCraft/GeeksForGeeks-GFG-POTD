
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 24-JAN-2024                                                                                                        *
*   Problem       : Check if a given graph is tree or not                                                                              *
*   Problem Link  : https://www.geeksforgeeks.org/problems/is-it-a-tree/1                                                              *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : DFS,Graph,Tree,Data Structures Algorithms,DSA                                                                      *
*   Company Tags  :                                                                                                                    *
****************************************************************************************************************************************

Problem Statemenst 
You are given an undirected graph of N nodes (numbered from 0 to N-1) and M edges. Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges.

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [1, 3]]
Output: 
1
Explanation: 
Every node is reachable and the graph has no loops, so it is a tree

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [2, 0]]
Output: 
0
Explanation: 
3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.


Your Task:  
You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number nodes in the input graph) and the edges representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 2*105
0 <= M <= 2*105


*/

class Solution{
    public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
         vector<int> ad[n];
        for(auto it:adj){
            int u=it[0];
            int v=it[1];
            ad[u].push_back(v);
            ad[v].push_back(u);
        }
        vector<int>vis(n,0);
        vis[0]=1;
        queue<pair<int,int>> q;
        q.push({0,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:ad[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    return 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return 0;
            }
        }
        return 1;
    }
};