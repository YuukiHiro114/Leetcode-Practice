class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k<=nums.size()/2){
            priority_queue<int, vector<int>, greater<int>>pql;
            for(int i =0; i<nums.size(); ++i){
                if(pql.size()<k){
                    pql.push(nums[i]);
                }else{
                    if(pql.top()<nums[i]){
                        pql.pop();
                        pql.push(nums[i]);
                    }
                }
            }
            return pql.top();
        }
        else{
            priority_queue<int>pq2;
            for(int i =0; i<nums.size();++i){
                if(pq2.size()<nums.size()-k+1){
                    pq2.push(nums[i]);
                }else{
                    if(pq2.top()>nums[i]){
                        pq2.pop();
                        pq2.push(nums[i]);
                    }
                }
            }
            return pq2.top();
        }
    }
};