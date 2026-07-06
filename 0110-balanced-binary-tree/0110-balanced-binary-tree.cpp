/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int hei(TreeNode*root){
        if(root==NULL)return 0;
        return 1+max(hei(root->left),hei(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        int l=hei(root->left);
        int r=hei(root->right);
        if(abs(l-r)>1)return false;
        return isBalanced(root->left) && isBalanced(root->right);

    }
};