class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int score = nums.back() - nums.front(), upper, lower;
        for(int i=0; i!=nums.size()-1;++i){
            upper = max(nums.back()-k,nums[i]+k);
            lower = min(nums.front()+k,nums[i+1]-k);
            score = min(score,upper-lower);
        }
        return score;
    }
};