class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[l]=nums[i];
                l+=1;
            }
        }
        return l;
    }
};