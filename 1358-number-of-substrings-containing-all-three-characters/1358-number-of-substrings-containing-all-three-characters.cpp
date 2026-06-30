      //int cnt=0; 
        //brute on^2 generate all substrings
        //int n=s.size();
        // for(int i=0;i<n;i++){
        //     int h[3]={0};
        //     for(int j=i;j<n;j++){
        //         h[s[j]-'a']=1;
        //         if(h[0]+h[1]+h[2]==3)cnt+=1;
        //     }
        // }
        // return cnt;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        int l = 0;
        int cnt = 0;
        for(int r = 0; r < n; r++){
            freq[s[r]]++;
            while(freq.size() == 3){
                cnt += (n - r);   // all substrings ending from r to n-1
                freq[s[l]]--;
                if(freq[s[l]] == 0)
                    freq.erase(s[l]);
                l++;
            }
        }
        return cnt;
    }
};