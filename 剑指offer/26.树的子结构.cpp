// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/
// 题解：层次遍历，按照A树节点遍历，找到即停止。
class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if(A == nullptr || B == nullptr) return false;
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool dfs(TreeNode *A, TreeNode *B) {
        if(B == nullptr) return true;
        if(A == nullptr || A->val != B->val) return false;
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};

/*
[4,2,3,4,5,6,7,8,9]
[4,8,9]

true
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x): val(x), left(NULL), right(NULL) {}
 * };
 */
