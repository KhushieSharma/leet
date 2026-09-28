class Solution {
public:
    int maxDepth(string s) {
        int d=0,r=0;
        for(char ch:s){
            if(ch==')'){
                d--;
                continue;
            }
            if(ch!='(')continue;
            d++;
            if(d>r)r=d;
        }
        return r;
    }
};