// Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list and return the head of the updated list.

// Example 1 : 
// Input: LinkedList: 2<->4<->5, p = 2, x = 6 
// Output: 2<->4<->5<->6
// Explanation: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 2 (0-based indexing).

// Example 2 : 
// Input: LinkedList: 1<->2<->3<->4, p = 0, x = 44
// Output: 1<->44<->2<->3<->4
// Explanation: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 0 (0-based indexing).

// Constraints:
// 0 <= p < size of doubly linked list <= 106
// 1 <= x <= 106

Node *addNode(Node *head, int pos, int data) 
{
    Node*temp = head;
    for(int i=0 ; i<pos ; i++)
        temp = temp->next;
        
    Node*newNode = new Node(data);
    if(temp->next != NULL)
    {
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}