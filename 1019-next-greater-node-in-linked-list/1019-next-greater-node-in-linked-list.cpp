/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ng;
        ListNode*cur=head;
        while(cur){
            ListNode*p=cur->next;
            int ans=0;
            while(p){
              if(p->val>cur->val){
                ans=p->val;
                break;
              }
              p=p->next;
            }
            ng.push_back(ans);
            cur=cur->next;
        }
        return ng;
    }
};