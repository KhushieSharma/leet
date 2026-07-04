struct node{
    int key,val,cnt;
    node*next;
    node*prev;
    node(int k,int v){
        key=k;
        val=v;
        cnt=1;
        next=prev=nullptr;
    }
};
struct List{
    int size;
    node*head;
    node*tail;
    List(){
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addf(node*n){
        node*temp=head->next;
        n->next=temp;
        n->prev=head;
        head->next=n;
        temp->prev=n;
        size++;
    }
    void del(node*n){
        node*p=n->prev;
        node*nx=n->next;
        p->next=nx;
        nx->prev=p;
        size--;
    }

};
class LFUCache {
public:
    unordered_map<int,node*>mp;
    unordered_map<int,List*>mp1;
    int max,minf,curs;
    LFUCache(int capacity) {
        max=capacity;
        minf=0;
        curs=0;
    }
    void updatefre(node*n1){
        mp.erase(n1->key);
        mp1[n1->cnt]->del(n1);
        if(n1->cnt==minf && mp1[minf]->size==0)minf++;
        List*high=new List();
        if(mp1.find(n1->cnt+1)!=mp1.end())high=mp1[n1->cnt+1];
        n1->cnt+=1;
        high->addf(n1);
        mp1[n1->cnt]=high;
        mp[n1->key]=n1;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node*n1=mp[key];
            int ans=n1->val;
            updatefre(n1);
            return ans;
        }
        return -1;
    }
    void put(int key, int value) {
        if(max==0)return;
        if(mp.find(key)!=mp.end()){
            node*n1=mp[key];
            n1->val=value;
            updatefre(n1);
            return;
        }
        else if(curs==max){
            List*l=mp1[minf];
            node*deln=l->tail->prev;
            mp.erase(deln->key);
            l->del(deln);
            curs--;
        }
        curs++;
        minf=1;
        List*l1=new List();
        if(mp1.find(minf)!=mp1.end()){
            l1=mp1[minf];
        }
        node*n1=new node(key,value);
        l1->addf(n1);
        mp[key]=n1;
        mp1[minf]=l1;
    
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */