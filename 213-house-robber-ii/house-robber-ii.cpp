class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        else return max(maxMoney(nums,1,n-1), maxMoney(nums,0,n-2));
    }
    int maxMoney(vector<int>&nums, int left, int right){
        int prey = 0;
        int cur = 0;
        for(int i = left; i<=right; i++){
            int temp = max(cur,nums[i]+prey);
            prey = cur;
            cur = temp;
        }
        return cur;
    }
};