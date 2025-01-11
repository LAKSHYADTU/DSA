// Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the modified Linked List.

// Example 1 :
// Input: LinkedList: 1->2->3->4->5 , x = 6
// Output: 1->2->3->4->5->6
// Explanation : We can see that 6 is inserted at the end of the linkedlist.

// Example 2 :
// Input: LinkedList: 5->4 , x = 1
// Output: 5->4->1
// Explanation : We can see that 1 is inserted at the end of the linkedlist.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0 <= number of nodes <= 105
// 1 <= node->data , x <= 103

Node *insertAtEnd(Node *head, int x) 
{
    Node*newnode=new Node(x);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}