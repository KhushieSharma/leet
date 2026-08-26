class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
    int l=0,o=0;
    int r=0;
    int n=s.size();
    int mini=INT_MAX;
    string ans="";
    while(r<n){
        if(s[r]=='1')o++;
        while(o==k){
            if(r-l+1<=mini){
                if(r-l+1==mini){
                    if(ans>s.substr(l,r-l+1))ans=s.substr(l,r-l+1);
                }
                else ans=s.substr(l,r-l+1);
                mini=r-l+1;
            }
            if(s[l]=='1')o--;
            l++;
        }
        r++;
    }
    return ans;
    }
};