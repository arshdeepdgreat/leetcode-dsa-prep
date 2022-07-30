class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(),1);
        
        
        for(int i=1;i<n;i++){
            int max_len = 1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    max_len = max(dp[j]+1,max_len);
            }
            dp[i]=max_len;
        }
        
        int ans = 1;
        for(auto i:dp)ans=max(ans,i);
        return ans;
    }
};