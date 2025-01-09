// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Explanation:

// Example 2:
// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
// Output: [4,2,6,5,7,1,3,9,8]
// Explanation:

// Example 3:
// Input: root = []
// Output: []

// Example 4:
// Input: root = [1]
// Output: [1]

// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// APP 1 (RECURSIVE) : ----------------------------------------------
void solve(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    solve(root->left, v);
    v.push_back(root->val);
    solve(root->right, v);
}
vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> v;
    solve(root, v);
    return v;
}

// APP 2 (ITERATIVE) : ----------------------------------------------
vector<int> inorderTraversal(TreeNode* root) 
{
    stack<TreeNode*>st;
    TreeNode*temp = root;
    vector<int>v;
    while(true)
    {
        if(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if(st.empty())
                break;
            temp = st.top();
            st.pop();
            v.push_back(temp->val);
            temp = temp->right;
        }
    }
    return v;
}