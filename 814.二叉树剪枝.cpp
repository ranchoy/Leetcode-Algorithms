// https://leetcode.cn/problems/binary-tree-pruning/
// 题意：叶子为0节点和仅0子树均剪枝。
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        return root;
    }

    TreeNode* pruneTree2(TreeNode* root) {
        if(root == nullptr) return nullptr;
        if(DFS(root->left) && DFS(root->right)) {
            return (root->val == 1) ? root : nullptr; // important
        }
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode *node = stk.top(); stk.pop();
            if(DFS(node->left) == true) {
                if(node->left) node->left = nullptr;
            } else {
                stk.push(node->left);
            }
            if(DFS(node->right) == true) {
                if(node->right) node->right = nullptr;
            } else {
                stk.push(node->right);
            }
        }

        return root;
    }

    bool DFS(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode *lson = root->left, *rson = root->right;
        if((lson && lson->val == 1) || (rson && rson->val == 1)) {
            return false;
        }
        return DFS(lson) && DFS(rson) && (root->val == 0);
    }
};

/*
[0,null,0]
[1,null,0,0,1]
[1,1,0,1,1,0,1,0]

[]
[1,null,0,null,1]
[1,1,0,1,1,null,1]
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
