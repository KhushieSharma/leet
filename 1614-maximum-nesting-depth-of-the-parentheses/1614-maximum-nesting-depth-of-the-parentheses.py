class Solution:
    def maxDepth(self, s: str) -> int:
        d=r=0
        for i in range(0,len(s)):
            if s[i]==')':
                d-=1
                continue
            if s[i]!='(':
                continue
            d+=1
            if(d>r):
                r=d
        return r