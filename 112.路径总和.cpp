// https://leetcode-cn.com/problems/path-sum/
// 递归查找满足条件结果。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = is_exist_path(root, 0, targetSum);
        return flag;
    }
    
    bool is_exist_path(TreeNode *root, int cur_sum, int target) {
        if(root == nullptr) return false;
        TreeNode *p_l = root->left, *p_r = root->right;
        if(root->val + cur_sum == target && p_l == nullptr && p_r == nullptr) {
            return true;
        }
        
        cur_sum += root->val;
        bool flag1 = is_exist_path(p_l, cur_sum, target);
        bool flag2 = is_exist_path(p_r, cur_sum, target);
        return flag1 | flag2;
    }
};

/*
[1,-2,3]
-1
[-2,null,-3]
-5
[8,9,-6,null,null,5,9]
7
true
true
true
*/
