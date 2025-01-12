// Given a binary tree, determine if it is height-balanced

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true

// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

// APP 1 : TC = O(N^2)
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root)
{
    if(root == NULL)
        return true;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    if(abs(lh-rh) > 1)
        return false;
    
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    if(!left || !right)
        return false;
    return true;
}

// APP 2 : TC = O(N)
int solve(TreeNode*root)  
{
    if(root == NULL)
        return 0;
    
    int lh = solve(root->left);
    int rh = solve(root->right);

    if(lh==-1 || rh==-1)
        return -1;

    if(abs(lh-rh) > 1)
        return -1;
    
    return 1 + max(lh , rh);
}

bool isBalanced(TreeNode* root)  // TC = O(n)
{
    // If Tree is balanced BT, then i will return height
    // else i will return false
    return solve(root) != -1;
}