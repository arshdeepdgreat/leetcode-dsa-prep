class Solution {
public:
    pair<int,int> func(string s,int p1,int p2){
        int n=s.size();
            while(p1>=0 and p2<n and s[p1]==s[p2])
            {
                p1--;
                p2++;
            }
        return {p1,p2};
    }
    string longestPalindrome(string s) {
        pair<int,int>ans={-1,0};
        int n=s.size();
        for(int i=0;i<n;i++){
            int p1=i-1;
            int p2=i+1;
            pair<int,int> k=func(s,p1,p2);
            if(k.second - k.first - 1 > ans.second - ans.first -1){
                ans=k;
            }
            p1=i;
            p2=i+1;
            k=func(s,p1,p2);
            if(k.second - k.first - 1 > ans.second - ans.first -1){
                ans=k;
            }
        }
        return s.substr(ans.first+1,ans.second-ans.first-1);
    }
};