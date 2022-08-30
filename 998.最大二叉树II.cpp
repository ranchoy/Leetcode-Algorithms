// https://leetcode.cn/problems/maximum-binary-tree-ii/
// 题解：递归，注意root已经是最大树，可以利用左右子树递归。
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode *root, int val) {
        TreeNode *new_node = new TreeNode(val);
        if(root == nullptr) return new_node;
        if(root->val < val) {
            new_node->left = root; return new_node;
        } else {
            root->right = insertIntoMaxTree(root->right, val); return root;
        }

        return nullptr;
    }
};

/*
[5,2,3,null,1]
5
[4,1,3,null,null,2]
5

[5,2,4,null,1,3]
[5,4,null,1,3,null,null,2]
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
