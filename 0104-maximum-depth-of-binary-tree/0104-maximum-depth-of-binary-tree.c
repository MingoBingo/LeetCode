/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) 
{
    int hLeft, hRight;

    if(root == NULL)
    return 0;

    hLeft = maxDepth(root->left);
    hRight = maxDepth(root->right);

    if(hLeft > hRight)
    return hLeft + 1;

    return hRight + 1;    
}