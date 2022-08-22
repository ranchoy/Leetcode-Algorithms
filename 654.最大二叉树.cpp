// https://leetcode.cn/problems/maximum-binary-tree/
// 题解：模拟题，注意结束条件以及max_idx非空。
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int> &nums) {
        int len = nums.size();
        TreeNode *root = build_tree(nums, 0, len-1);
        return root;
    }

    TreeNode *build_tree(vector<int> &nums, int left, int right) {
        if(left > right) return nullptr;
        int max_idx = left, max_val = 0; // <max_idx> is not empty.

        for(int i = left; i <= right; i++) {
            if(max_val < nums[i]) {
                max_val = nums[i]; max_idx = i;
            }
        }

        TreeNode *root = new TreeNode(max_val);
        root->left = build_tree(nums, left, max_idx-1);
        root->right = build_tree(nums, max_idx+1, right);
        return root;
    }
};

/*
[3,2,1]
[3,2,1,6,0,5]

[3,null,2,null,1]
[6,3,5,null,2,0,null,null,1]
*/

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
