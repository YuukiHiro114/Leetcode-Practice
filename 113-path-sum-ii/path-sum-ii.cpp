/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>pathSum(TreeNode*root, int targetSum){
            res.clear();
            path.clear();
            target = targetSum;
            dfs(root);
            return res;
    }
private:
vector<vector<int>> res;
vector<int>path;
int sum = 0;
int target = 0;

    void dfs(TreeNode*root){
        if(root == nullptr)return;
        sum += root->val;
        path.push_back(root->val);
        if(root -> left == nullptr && root -> right == nullptr && sum == target){
            res.push_back(path);
        }
        dfs(root -> left);
        dfs(root -> right);
        sum -= root -> val;
        path.pop_back();
    }
};
