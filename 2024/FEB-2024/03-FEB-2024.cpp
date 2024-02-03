
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 03-FEB-2024                                                                                                        *
*   Problem       : Decimal Equivalent of Binary Linked List                                                                           *
*   Problem Link  : https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1                                  *
*   Difficulty    : Easy                                                                                                               *
*   Topics Tags   : Linked list, Data structure, DSA, Algorithm                                                                        *
*   Company Tags  : Juniper Networks                                                                                                   *
****************************************************************************************************************************************

Problem Statemenst 

Given a singly linked list of length n. The link list represents a binary number, ie- it contains only 0s and 1s. Find its decimal equivalent.
The significance of the bits decreases with the increasing index in the linked list.
An empty linked list is considered to represent the decimal value 0. 

Since the answer can be very large, answer modulo 109+7 should be printed.

Example:

Example 1:
Input:
n = 3
Linked List = {0, 1, 1}
Output:
3
Explanation:
0*22 + 1*21 + 1*20 =  1 + 2 + 0 = 3


Example 2:
Input:
n = 4
Linked List = {1, 1, 1, 0}
Output:
14
Explanation:
1*23 + 1*22 + 1*21 + 0*20 =  8 + 4 + 2 + 0 = 14


Your Task:
You do not have to take any input or print anything. Complete the function decimalValue() which takes a head node of a linked list as an input parameter and returns decimal representation of it.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= n <= 100
Data of each node is either 0 or 1


*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm for computing the decimal equivalent of a binary linked list modulo 1000000007

    decimalValue(Node *head)
    Input: Pointer to the head of a linked list representing a binary number.
    Output: Decimal equivalent of the binary linked list modulo 1000000007.
    1. If the linked list is empty (head is NULL), return 0.
    2. Initialize a variable 'ans' to 0 to store the decimal equivalent.
    3. Initialize a pointer 'p' to traverse the linked list, starting from the head.
    4. Traverse the linked list:
    a. Update the decimal equivalent 'ans' by left shifting the current value by 1 and adding the new data of the current node.
    b. Perform modulo operation 'ans = ans % 1000000007' to prevent overflow.
    c. Move to the next node.
    5. Return the decimal equivalent 'ans' modulo 1000000007.


*/   



class Solution {
public:
    // Function to compute the decimal equivalent of a binary linked list modulo 1000000007
    unsigned long long int decimalValue(Node* head) {
        // If the linked list is empty, return 0
        if (head == NULL)
            return 0;

        unsigned long long int ans = 0; // Variable to store the decimal equivalent
        Node* p = head; // Pointer to traverse the linked list

        // Traverse the linked list
        while (p) {
            // Update the decimal equivalent by left shifting the current value by 1 and adding the new data
            ans = (ans << 1) | p->data;
            // Modulo operation to prevent overflow
            ans = ans % 1000000007;
            // Move to the next node
            p = p->next;
        }

        // Return the decimal equivalent modulo 1000000007
        return ans;
    }
};
