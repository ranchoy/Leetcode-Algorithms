// https://leetcode.cn/problems/longest-univalue-path/
// 题解：DFS搜索，当前root节点的值为(left+right)，若等于Pre_val则返回max(left,right)+1。
class Solution {
public:
    int max_val = 0;
    int longestUnivaluePath(TreeNode *root) {
        if(root == nullptr) return 0;
        dfs(root, root->val);
        return max_val;
    }

    int dfs(TreeNode *root, int pre_val) {
        if(root == nullptr) return 0;
        int left = dfs(root->left, root->val);
        int right = dfs(root->right, root->val);
        max_val = max(max_val, left + right);
        if(root->val == pre_val) return max(left, right) + 1;
        return 0;
    }
};

/*
[1,4,5,4,4,5]
[5,4,5,1,1,5]

2
2
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
