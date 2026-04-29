bool myCompare(vector<int>a,vector<int>b)
{
    return a[0]-a[1]<b[0]-b[1];
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0;
        sort(costs.begin(), costs.end(),myCompare);
        for(int i=0; i<costs.size()/2; i++)
        {
            sum += costs[i][0]+costs[costs.size()-1-i][1];
        }
        return sum;
    }
};