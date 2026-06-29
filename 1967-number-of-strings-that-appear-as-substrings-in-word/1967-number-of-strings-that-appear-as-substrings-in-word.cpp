class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int a=0;
        for(string s:patterns){
            if(word.find(s)!=string::npos)a++;
        }
        return a;
    }
};