// https://leetcode.cn/problems/binary-tree-inorder-traversal/
// 题解：中序遍历，左根右，先遍历完左节点，再上溯当前根节点，后遍历右节点。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> nums;
        stack<TreeNode *> stk;

        while(root || !stk.empty()) {
            while(root) {
                stk.push(root);
                root = root->left;
            }

            TreeNode *node = stk.top(); stk.pop();
            nums.push_back(node->val);

            if(node->right) root = node->right;
        }

        return nums;
    }
};

/*
[1,null,2,3]

[1,3,2]
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
