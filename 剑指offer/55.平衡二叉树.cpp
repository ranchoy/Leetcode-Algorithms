// https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
// 递归，依次向左右部进行遍历。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int left = tree_depth(root->left);
        int right = tree_depth(root->right);
        if(abs(left - right) > 1) return false;
        return isBalanced(root->left) & isBalanced(root->right);
    }

    int tree_depth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = tree_depth(root->left);
        int right = tree_depth(root->right);
        return max(left, right) + 1;
    }
};

/*
[3,9,20,null,null,15,7]
true
*/
