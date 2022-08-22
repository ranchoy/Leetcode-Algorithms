// https://leetcode-cn.com/problems/count-complete-tree-nodes/
// 二分查找，利用满二叉树性质，统计节点个数。
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
    int countNodes(TreeNode *root) {
        if(root == nullptr) return 0;
        int l = get_tree_depth(root->left);
        int r = get_tree_depth(root->right);
        if(l == r) {
            return (1<<l) + countNodes(root->right);
        } else {
            return (1<<r) + countNodes(root->left);
        }
    }

    int get_tree_depth(TreeNode *root) {
        if(root == nullptr) return 0;
        int l = get_tree_depth(root->left);
        int r = get_tree_depth(root->right);
        return max(l, r) + 1;
    }
};

/*
[1,2,3,4,5,6]

6
*/
