class Solution {
public:
    int ans=1;
    int arrangeCoins(int n) {
        if(n==ans)return ans;
        if(n<ans)return ans-1;
        n-=ans;
        ans++;
        return arrangeCoins(n);
    }
};