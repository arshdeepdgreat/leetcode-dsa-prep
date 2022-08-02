class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
       
        vector<vector<long long int>>dp(arr.size(),vector<long long int>(arr[0].size(),-1));
        if(arr[arr.size()-1][arr[0].size()-1])
        {
            return 0;
        }
        int row=0;
        int col=0;
        return fun(arr,row,col,dp);
    }
    int fun(vector<vector<int>>&arr,int row,int col, vector<vector<long long int>>&dp)
    {
        
        if(row<0 or row>=arr.size() or col<0 or col>=arr[0].size())  //out of the board
        {
            return 0;
        }
        if(row==arr.size()-1 and col==arr[0].size()-1)
        {
            return 1;
        }
        if(arr[row][col]==1)   //obstacle
        {
            return 0;
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        long long int total_ways=fun(arr,row,col+1,dp)+0LL+fun(arr,row+1,col,dp)+0LL;
        dp[row][col]=total_ways;
        return dp[row][col];
    }
};