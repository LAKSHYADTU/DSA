// Given an array of integer arr. Your task is to construct the linked list from arr & return the head of the linked list.

// Example 1 : 
// Input: arr = [1, 2, 3, 4, 5]
// Output: LinkedList: 1->2->3->4->5
// Explanation: Linked list for the given array will be

// Example 2 : 
// Input: arr = [2, 4, 6, 7, 5, 1, 0]
// Output: LinkedList: 2->4->6->7->5->1->0
// Explanation: Linked list for the given array will be

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= arr.size() <= 106
// 1 <= arr[i] <= 106

Node* constructLL(vector<int>& arr) 
{
    Node*head = new Node(arr[0]);
    Node*temp = head;
    for(int i=1 ; i<arr.size() ; i++)
    {
        Node*newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}