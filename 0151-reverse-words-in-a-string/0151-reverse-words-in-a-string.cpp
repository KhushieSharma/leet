class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string w,ans;
        while(ss>>w)ans=w+" "+ans;

        return ans.substr(0,ans.size()-1);
    }
};