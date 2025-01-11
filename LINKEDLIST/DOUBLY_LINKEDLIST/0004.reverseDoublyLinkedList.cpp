// Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.

// Example 1 : 
// Input: LinkedList: 3 <-> 4 <-> 5
// Output: 5 <-> 4 <-> 3

// Example 2 : 
// Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
// Output: 196 <-> 59 <-> 122 <-> 75

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= number of nodes <= 106
// 0 <= node->data <= 104

DLLNode* reverseDLL(DLLNode* head) 
{
    if(head==NULL || head->next==NULL)
        return head;

    DLLNode* previous = NULL;
    DLLNode*temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        head->next = previous;
        head->prev = temp;
        previous = head;
        head = temp;
    }
    return previous;
}