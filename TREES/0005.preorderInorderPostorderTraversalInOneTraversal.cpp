// You have been given a Binary Tree of 'N'
// nodes, where the nodes have integer values.
// Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.

// EXAMPLE 1 : 
// Sample Input 1 :
// 1 2 3 -1 -1 -1  6 -1 -1
// Sample Output 1 :
// 2 1 3 6 
// 1 2 3 6 
// 2 6 3 1
// Explanation of Sample Output 1 :
// Inorder traversal of given tree = [2, 1, 3, 6]
// Preorder traversal of given tree = [1, 2, 3, 6]
// Postorder traversal of given tree = [2, 6, 3, 1]

// EXAMPLE 2 : 
// Sample Input 2 :
// 1 2 4 5 3 -1 -1 -1 -1 -1 -1
// Sample Output 2 :
// 5 2 3 1 4 
// 1 2 5 3 4 
// 5 3 2 4 1
// Explanation of Sample Output 2 :
// Inorder traversal of given tree = [5, 2, 3, 1, 4]
// Preorder traversal of given tree = [1, 2, 5, 3, 4]
// Postorder traversal of given tree = [5, 3, 2, 4, 1]

// Constraints :
// 1 <= 'N' <= 10^5
// 0 <= 'data' <= 10^5     
// where 'N' is the number of nodes and 'data' denotes the node value of the binary tree nodes.

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    stack<pair<TreeNode* , int>>st;
    st.push({root , 1});
    vector<int>pre , in , post;
    vector<vector<int>>ans(3);
    if(root==NULL) 
        return ans;
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();
        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
                st.push({it.first->left , 1});
        }
        else if(it.second==2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
                st.push({it.first->right , 1});
        }
        else
            post.push_back(it.first->data);
    }
    ans[0]=in;
    ans[1]=pre;
    ans[2]=post;
    return ans;
}

// TRICK : Always remember when new value is push it's 2nd term is 1
// if(num ==1)
//     prepush
//     top.second++;
//     left
// else if (num==2)
//     inpush
//     top.second++;
//     right
// else   
//     postpush