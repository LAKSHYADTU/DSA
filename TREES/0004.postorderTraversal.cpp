// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [3,2,1]
// Explanation:

// Example 2:
// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
// Output: [4,6,7,5,2,9,8,3,1]
// Explanation:

// Example 3:
// Input: root = []
// Output: []
// Example 4:
// Input: root = [1]
// Output: [1]

// Constraints:
// The number of the nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// APP 1 (RECURSIVE) : ----------------------------------------------
void solve(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    solve(root->left, v);
    solve(root->right, v);
    v.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> v;
    solve(root, v);
    return v;   
}

// APP 2 (ITERATIVE USING 2 STACK) : --------------------------------------
vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> v;
    if(root == NULL)
        return v;

    stack<TreeNode*>st1 , st2;
    st1.push(root);
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL)
            st1.push(root->left);
        if(root->right != NULL)
            st1.push(root->right);
    }

    while(!st2.empty())
    {
        v.push_back(st2.top()->val);
        st2.pop();
    }
    return v;
}

// APP 3 (ITERATIVE USING 1 STACK) : --------------------------------------
vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> v;
    if(root == NULL)
        return v;

    stack<TreeNode*>st;
    while(root!=NULL || !st.empty())
    {
        if(root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            TreeNode*temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                v.push_back(temp->val);
                while(!st.empty() && temp==st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    v.push_back(temp->val);
                }
            }
            else
                root=temp;
        }
    }
    return v;
}
