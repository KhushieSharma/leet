/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if(head==NULL)return NULL;
        // unordered_map<Node*,Node*>mp;
        // Node*temp=head;
        // while(temp!=NULL){
        //     mp[temp]=new Node(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=NULL){
        //     mp[temp]->next=mp[temp->next];
        //     mp[temp]->random=mp[temp->random];
        //     temp=temp->next;
        // }
        // return mp[head];
        Node*iter=head;
        Node*front=NULL;
        while(iter!=NULL){
            front=iter->next;
            Node*copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        iter=head;
        while(iter!=NULL){
            if(iter->random!=NULL){
                iter->next->random=iter->random->next; //deep copy
            }
            iter=iter->next->next;
        }
        iter=head;
        front=head;
        Node*dum=new Node(0);
        Node*copy=dum;
        while(iter!=NULL){
            front=iter->next->next;
            copy->next=iter->next;
            iter->next=front;
            copy=copy->next;
            iter=iter->next;
        }
        return dum->next;

    }
};