class Solution {
public:
    /*
    1987 
    
    
    123
    132
    213
    231
    312
    321
    */
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return;
        int p=n-1;
        while(p!=1 and nums[p]<=nums[p-1]){
            p--;
        }
        if(nums[0]>=nums[1] and p==1){
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            p--;
            for(int i=n-1;i>p;i--){
                if(nums[i]>nums[p]){
                    int temp=nums[i];
                    nums[i]=nums[p];
                    nums[p]=temp;
                    break;
                }
            }
            reverse(nums.begin()+p+1,nums.end());
            return;
        }
    }
};