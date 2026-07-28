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
    int s(TreeNode*root,bool a){
        if(!root)return 0;
        if(root->left==NULL && root->right==NULL)return a?root->val:0;
        return s(root->left,true)+s(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return s(root,false);
    }
};