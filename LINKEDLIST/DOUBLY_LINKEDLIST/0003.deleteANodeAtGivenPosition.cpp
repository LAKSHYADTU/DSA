// Given a Doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

// Example 1 : 
// Input: LinkedList = 1 <--> 3 <--> 4, x = 3
// Output: 1 <--> 3
// Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.

// Example 2 : 
// Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
// Output: 5 <--> 2 <--> 9
// Explanation:

// Constraints:
// 2 <= size of the linked list <= 106
// 1 <= x <= size of the linked list 
// 1 <= node->data <= 104

Node* deleteNode(Node* head, int x) 
{
    if(head==NULL || head->next==NULL)
        return NULL;
        
    Node*temp = head;
    for(int i=1 ; i<x ; i++)
    {
        temp = temp->next;
    }
    
    if(temp->prev == NULL)  // first element
    {
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }
    else if(temp->next == NULL)  // last element
    {
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp;
        return head;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}