class Solution {
public:
    string addStrings(string n, string m) {
        int i=n.size()-1;
        int j=m.size()-1;
        int c=0;
        string ans="";
        while(i>=0 || j>=0||c!=0){
            int d1=(i>=0)?n[i]-'0':0;
            int d2=(j>=0)?m[j]-'0':0;
            int sum=d1+d2+c;
            c=sum/10;
            ans+=to_string(sum%10);
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};