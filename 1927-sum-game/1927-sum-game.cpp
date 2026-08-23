class Solution {
public:
    bool sumGame(string num) {
        int sum=0,sum2=0,cnt1=0,cnt2=0;
        for(int i=0;i<num.size()/2;i++){
            if(num[i]!='?'){
                sum+=num[i]-'0';
            }
            else cnt1++;
        }
        for(int i=num.size()/2;i<num.size();i++){
            if(num[i]!='?')sum2+=num[i]-'0';
            else cnt2++;
        }
        return (sum-sum2)*2!=(cnt2-cnt1)*9;

    }
};