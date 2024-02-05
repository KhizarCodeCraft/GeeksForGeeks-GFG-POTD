
/*
****************************************************************************************************************************************
*   Author        : Khizar Hayat                                                                                                       *
*   Date          : 05-FEB-2024                                                                                                        *
*   Problem       : Sorted insert for circular linked list                                                                             *
*   Problem Link  : https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1                                    *
*   Difficulty    : Easy                                                                                                               *
*   Topics Tags   : Circular Linked List, Linked list, Data structure, DSA, Algorithm                                                  *
*   Company Tags  : Amazon, Zoho, Microsoft                                                                                                             *
****************************************************************************************************************************************

Problem Statemenst 

Given a sorted circular linked list of length n, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

Example:

Input:
n = 3
LinkedList = 1->2->4
(the first and last node is connected, i.e. 4 --> 1)
data = 2
Output: 
1 2 2 4
Explanation:
We can add 2 after the second node.

Input:
n = 4
LinkedList = 1->4->7->9
(the first and last node is connected, i.e. 9 --> 1)
data = 5
Output: 
1 4 5 7 9
Explanation:
We can add 5 after the second node.


Your Task:
The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list and return the head of the linked list.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= n <= 105

*/


/*
Before seeing Code read steps and try to solve problems by reading algorithm of problem(Brief explanation below)

    Algorithm for inserting a node into a sorted circular linked list

    sortedInsert(Node* head, int data)
    Input: Pointer to the head of the sorted circular linked list 'head', and an integer 'data' to be inserted.
    Output: Pointer to the head of the modified sorted circular linked list.

    1. Create a new node 'newNode' with the given data.
    2. Initialize a temporary pointer 'temp' for traversal and set it to 'head'.
    3. Case 1: Empty List
    a. If 'head' is NULL, set 'newNode->next' to 'newNode' and return 'newNode' as the head of the modified list.
    4. Case 2: Inserting at the beginning
    a. If 'data' is less than or equal to 'head->data', insert 'newNode' before 'head':
        i. Set 'newNode->next' to 'head'.
        ii. Traverse to the last node and update its next pointer to 'newNode'.
        iii. Return 'newNode' as the new head of the modified list.
    5. Case 3: Inserting between existing nodes
    a. Traverse the list until finding the correct position to insert 'newNode':
        i. Stop when reaching the end of the list or 'data' is less than or equal to the next node's data.
    b. Insert 'newNode' between 'temp' and 'temp->next':
        i. Set 'newNode->next' to 'temp->next'.
        ii. Update 'temp->next' to 'newNode'.
    6. Return the original 'head' as no modification is made to the head.
    


*/   


class Solution {
public:
    // Function to insert a node into a sorted circular linked list
    Node* sortedInsert(Node* head, int data) {
        // Create a new node with the given data
        Node* newNode = new Node(data);
        Node* temp = head; // Temporary pointer for traversal

        // Case 1: Empty List
        if (!head) {
            newNode->next = newNode; // Set newNode to point to itself
            return newNode; // Return newNode as the head of the modified list
        }

        // Case 2: Inserting at the beginning (newNode becomes the new head)
        else if (data <= head->data) {
            newNode->next = head; // Point newNode to the current head
            // Traverse to the last node to update its next pointer
            while (temp->next != head)
                temp = temp->next;
            // Update the next pointer of the last node to point to newNode
            temp->next = newNode;
            // Return newNode as the new head
            return newNode;
        }

        // Case 3: Inserting between existing nodes
        else {
            // Traverse until finding the correct position to insert newNode
            while (temp->next != head && data > temp->next->data)
                temp = temp->next;
            // Insert newNode between temp and temp->next
            newNode->next = temp->next;
            temp->next = newNode;
            // Return the original head as no modification is made to the head
            return head;
        }
    }
};