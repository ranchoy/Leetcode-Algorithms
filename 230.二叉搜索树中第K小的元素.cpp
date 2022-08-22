// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
// 二叉搜索树第k大元素，利用二叉树中序遍历实现。
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
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()) {
            while(root != nullptr) { // 左半区
                stk.push(root);
                root = root->left;
            }

            if(!stk.empty()) {
                TreeNode *node = stk.top(); stk.pop(); // 节点
                if((--k) == 0) return node->val;
                root = node->right; // 右半区
            }
        }
        return -1;
    }
};

/*
[1] 1
[1,null,2] 2
[5,3,6,2,4,null,null,1] 3

1
2
3
*/
