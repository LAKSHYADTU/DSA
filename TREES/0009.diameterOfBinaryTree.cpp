// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// Example 1:
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

// Example 2:
// Input: root = [1,2]
// Output: 1

// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -100 <= Node.val <= 100

// APP 1 : O(n^2)  ---------------------------------------------
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

void solve(TreeNode*root , int &maxi)
{
    if(root == NULL)
        return ;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    maxi = max(maxi , lh+rh);

    solve(root->left , maxi);
    solve(root->right , maxi);
}

int diameterOfBinaryTree(TreeNode* root) 
{
    int maxi = 0;
    solve(root , maxi);
    return maxi;
}

// APP 2 : O(n)  ---------------------------------------------
int solve(TreeNode*root , int &maxi)
{
    if(root == NULL)
        return 0;

    int lh = solve(root->left , maxi);
    int rh = solve(root->right , maxi);

    maxi = max(maxi , lh+rh);

    return 1 + max(lh , rh);
}

int diameterOfBinaryTree(TreeNode* root) 
{
    int maxi = 0;
    solve(root , maxi);
    return maxi;
}