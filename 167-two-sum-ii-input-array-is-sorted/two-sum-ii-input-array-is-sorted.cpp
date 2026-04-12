class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p = 0;
        int r=numbers.size()-1;

        while(p<r){
            if(numbers[p]+numbers[r]==target)break;
            else if(numbers[p]+numbers[r]>target) --r;
            else ++p;
        }
        return {p+1, r+1};
    }
};