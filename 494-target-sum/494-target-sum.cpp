class Solution {
    
public:
    int subset(int n,vector<int>nums,int sum)  {
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<sum+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i][j]+dp[i-1][j-nums[i-1]];

            }
        }
        return dp[n][sum];        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(auto i:nums)s+=i;
        
        if (s<target)return 0;
        
        int p=(target+s)/2;
        if((s + target) % 2 != 0)
            return 0;
        int n=nums.size();
        return subset(n,nums,abs(p));   
    }
};