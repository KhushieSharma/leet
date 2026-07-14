class Solution {
public:
    class node{
        public:
        int data,i,j;
        node(int data,int row,int col){
            this->data=data;
            i=row;
            j=col;
        }
    };
    class compare{
        public:
        bool operator()(node*a,node*b){
            return a->data>b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<node*,vector<node*>,compare >pq;
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<k;i++){
            mini=min(mini,nums[i][0]);
            maxi=max(maxi,nums[i][0]);
            node*n=new node(nums[i][0],i,0);
            pq.push(n);
        }
        int st=mini,end=maxi;
        while(!pq.empty()){
            node*p=pq.top();
            pq.pop();
            mini=p->data;
            if(maxi-mini<end-st){
                st=mini;
                end=maxi;
            }
            if(p->j+1<nums[p->i].size()){
                maxi=max(maxi,nums[p->i][p->j+1]);
                pq.push(new node(nums[p->i][p->j+1],p->i,p->j+1));
            }
            else break;
        }
        return {st,end};
    }
};