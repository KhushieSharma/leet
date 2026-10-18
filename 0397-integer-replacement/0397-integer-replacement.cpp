class Solution {
public:
    int sol(long long n){
        if(n==1)return 0;
        if(n%2==0)return 1+sol(n/2);
        return 1+min(sol(n+1),sol(n-1));
    }
    int integerReplacement(int n) {
        return sol((long long)n);
    }
};