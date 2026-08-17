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
 */class Solution {
public:
    unordered_map<int,int>mp;
    void popl(TreeNode* root){
        if(!root)return;
        mp[root->val]++;
        popl(root->left);
        popl(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        popl(root);
        int maxi=0;
        for(auto [key,val]:mp)maxi=max(maxi,val);
        for(auto [val, freq] : mp) {
            if(freq == maxi) {
                ans.push_back(val);
            }
        }

        return ans;

    }
};