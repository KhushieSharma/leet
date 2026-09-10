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
    pair<int,int>sol(TreeNode* root,int &cnt){
        if(root==NULL)return {0,0};
        auto [ls,lc]=sol(root->left,cnt);
        auto [rs,rc]=sol(root->right,cnt);
        int subs=ls+rs+root->val;
        int subc=lc+rc+1;
        if(subs/subc==root->val)cnt++;
        return {subs,subc};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        sol(root,cnt);
        return cnt;
    }
};