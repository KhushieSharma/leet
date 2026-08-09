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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)return head;
        ListNode*dum=new ListNode(0);
        dum->next=head;
        int cnt=0;
        ListNode*cur=dum,*nex=dum,*pre=dum;
        while(cur->next!=NULL){
            cnt++;
            cur=cur->next;
        }
        while(cnt>=k){
            cur=pre->next;
            nex=cur->next;
            for(int i=1;i<k;i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre=cur;
            cnt-=k;
        }
        return dum->next;
    }
};