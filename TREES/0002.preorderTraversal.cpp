// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,2,3]
// Explanation:

// Example 2:
// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
// Output: [1,2,4,5,6,7,3,8,9]
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
void solve(TreeNode* root , vector<int>&v)
{
    if(root == NULL)
        return ;
    v.push_back(root->val);
    solve(root->left , v);
    solve(root->right , v);
}
vector<int> preorderTraversal(TreeNode* root) 
{
    vector<int>v;
    solve(root , v);
    return v;
}

// APP 2 (ITERATIVE) : ----------------------------------------------
vector<int> preorderTraversal(TreeNode* root) 
{
    vector<int>v;
    if(root == NULL)
        return v;

    stack<TreeNode*>st;
    st.push(root);

    while(!st.empty())
    {
        root = st.top();
        st.pop();
        v.push_back(root->val);
        if(root->right != NULL)
            st.push(root->right);
        if(root->left != NULL)
            st.push(root->left);
    }
    return v;
}