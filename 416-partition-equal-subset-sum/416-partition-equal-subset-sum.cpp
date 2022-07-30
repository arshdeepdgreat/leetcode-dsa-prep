class Solution {
public:
    bool cs(vector<int>&arr,int n,int sum){
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=sum;i++){
            dp[0][i]=false;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j<arr[i-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else if(j>=arr[i-1])
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(auto i:nums)
            sum+=i;
        if(sum%2==0){
            return cs(nums,nums.size(),sum/2);
        }
        return false;
    }
};