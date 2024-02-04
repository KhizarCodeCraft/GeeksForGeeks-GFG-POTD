
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 04-FEB-2024                                                                                                        *
*   Problem       : Subtraction in Linked List                                                                                         *
*   Problem Link  : https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1                                                *
*   Difficulty    : Hard                                                                                                               *
*   Topics Tags   : Linked list, Data structure, DSA, Algorithm                                                                        *
*   Company Tags  : Amazon                                                                                                             *
****************************************************************************************************************************************

Problem Statemenst 

You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

Example:

Input:
L1 = 1->0->0
L2 = 1->2
Output: 88
Explanation:  
First linked list represents 100 and the
second one represents 12. 12 subtracted from 100
gives us 88 as the result. It is represented
as 8->8 in the linked list.

L1 = 0->0->6->3
L2 = 7->1->0
Output: 647
Explanation: 
First linked list represents 0063 => 63 and 
the second one represents 710. 63 subtracted 
from 710 gives us 647 as the result. It is
represented as 6->4->7 in the linked list.

Your Task:
You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

n and m are the length of the two linked lists respectively.
Expected Time Complexity:  O(n+m)
Expected Auxiliary Space: O(n+m)

Constraints:
1 <= n <= 10000
0 <= values represented by the linked lists < 10n
0 <= values represented by the linked lists < 10m

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm for subtracting two linked lists

    subLinkedList(Node* head1, Node* head2)
    Input: Pointers to the heads of two linked lists 'head1' and 'head2'.
    Output: Pointer to the head of the resulting linked list after subtracting 'head2' from 'head1'.
    1. Remove leading zeros from both linked lists.
    2. Get the lengths of both linked lists 'n1' and 'n2'.
    3. Handle cases when one or both linked lists are empty:
       a. If both are empty, return a new Node containing 0.
       b. If only one is empty, return the other linked list as the result.
    4. Ensure that 'head1' points to the longer linked list.
    5. If both linked lists have equal length, compare their elements:
       a. If all elements are equal, return a new Node containing 0.
       b. If any element of 'head1' is less than the corresponding element of 'head2', swap 'head1' and 'head2'.
    6. Reverse both linked lists for easier subtraction.
    7. Initialize variables 'res' (result) and 't1', 't2' for traversal.
    8. Subtract each element of the lists 'head1' and 'head2':
       a. If 't2' exists, get its data; otherwise, set 'small' to 0.
       b. If 't1's data is smaller than 't2's data, borrow from the next node.
       c. Create a new node with the difference and add it to the result list.
       d. Move to the next nodes in both lists.
    9. Remove leading zeros from the result.
    10. Return the resulting linked list.


*/   


class Solution {

public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to get the length of a linked list
    int getLength(Node* head) {
        int cnt = 0;
        for (Node* curr = head; curr != NULL; curr = curr->next)
            cnt++;
        return cnt;
    }

    // Function to subtract two linked lists
    Node* subLinkedList(Node* head1, Node* head2) {
        // Remove leading zeros from both lists
        while (head1->next != NULL && head1->data == 0)
            head1 = head1->next;
        while (head2->next != NULL && head2->data == 0)
            head2 = head2->next;

        // Get the lengths of both lists
        int n1 = getLength(head1);
        int n2 = getLength(head2);

        // Handle cases when one or both lists are empty
        if (n1 == 0 && n2 == 0)
            return new Node(0);

        // Ensure that head1 points to the longer list
        if (n1 < n2)
            return subLinkedList(head2, head1);

        // If both lists have equal length, compare their elements
        else if (n1 == n2) {
            Node* t1 = head1;
            Node* t2 = head2;
            // Advance pointers until a mismatch is found or the end of a list is reached
            while (t1 && t2 && t1->data == t2->data) {
                t1 = t1->next;
                t2 = t2->next;
            }
            // If t1 reaches the end of the list, return a new Node containing 0
            if (t1 == NULL)
                return new Node(0);
            // If t1's data is less than t2's data, swap head1 and head2
            else if (t1->data < t2->data)
                return subLinkedList(head2, head1);
        }

        // Reverse both lists for easier subtraction
        head1 = reverse(head1);
        head2 = reverse(head2);

        // Initialize variables for result and traversal
        Node* res = NULL;
        Node* t1 = head1;
        Node* t2 = head2;

        // Subtract each element of the lists
        while (t1) {
            int small = 0;
            // Check if t2 exists and get its data, otherwise, small remains 0
            if (t2)
                small = t2->data;
            // If t1's data is smaller than t2's data, borrow from next node
            if (t1->data < small) {
                t1->next->data = t1->next->data - 1;
                t1->data = t1->data + 10;
            }
            // Create a new node with the difference and add it to the result list
            Node* n = new Node(t1->data - small);
            n->next = res;
            res = n;
            // Move to the next nodes in both lists
            t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }

        // Remove leading zeros from the result
        while (res->next && res->data == 0)
            res = res->next;

        // Return the result
        return res;
    }
};