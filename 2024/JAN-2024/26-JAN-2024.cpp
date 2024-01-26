
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 26-JAN-2024                                                                                                        *
*   Problem       : Fractional Knapsack                                                                                                *
*   Problem Link  : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1                                            *
*   Difficulty    : Medium                                                                                                             *
*   Topics Tags   : Greedy Algorithm,Data Structures Algorithms,DSA                                                                    *
*   Company Tags  : Microsoft                                                                                                          *
****************************************************************************************************************************************

Problem Statemenst 
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. 

Example

Input:
N = 3, W = 50
value[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.000000
Explanation:
Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total weight becomes 60+100+80.0=240.0
Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 

Input:
N = 2, W = 50
value[] = {60,100}
weight[] = {10,20}
Output:
160.000000
Explanation:
Take both the items completely, without breaking.
Total maximum value of item we can have is 160.00 from the given capacity of sack.

Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size N and returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= W <= 109
1 <= valuei, weighti <= 104



*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        double ans =0;
        vector<pair<double,double>>v;
        for(int i =0;i<n;i++){
            v.push_back({double(arr[i].value)/arr[i].weight,arr[i].weight});
        }
        sort(v.rbegin(),v.rend());
        for(int i = 0;i<n;i++){
            if(v[i].second<=w){
                ans+=(v[i].first)*v[i].second;
                w -= v[i].second;
            }
            else{
                ans+=((v[i].first))*w;
                w=0;
            }
        }
        return ans;
    }
        
};