/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) 
{
    if(root == NULL)
    return 0;

    return countNodes(root->right) + countNodes(root->left) + 1;    
}