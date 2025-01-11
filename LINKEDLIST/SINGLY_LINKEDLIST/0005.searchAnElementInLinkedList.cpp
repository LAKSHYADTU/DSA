// Given a linked list of n nodes and a key, the task is to check if the key is present in the linked list or not.

// Example 1 : 
// Input: n = 4, key = 3
// 1->2->3->4
// Output: true
// Explanation: 3 is present in Linked List, so the function returns true.

// Constraint:
// 1 <= n <= 105
// 1 <= key <= 105

bool searchKey(int n, struct Node* head, int key) 
{
    Node*temp=head;
    while(temp != NULL)
    {
        if(temp->data == key)
            return true;
        temp=temp->next;
    }
    return false;
}