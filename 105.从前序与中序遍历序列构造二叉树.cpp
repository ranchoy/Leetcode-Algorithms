// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 恢复二叉树（无重复元素）的可能组合：先序+中序，后序+中序，不能缺少中序数组；
// 利用先/后序确定当前区间的根节点，再划分左右半区，递归构造左右子树。
class Solution {
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        TreeNode *root = build(preorder, inorder, 0, n-1, 0, n-1);
        return root;
    }

    TreeNode *build(vector<int> &pre_arr, vector<int> &in_arr, int l1, int r1, int l2, int r2) {
        if(l1 == r1) return new TreeNode(pre_arr[l1]);
        if(l1 > r1) return nullptr;
        int k = -1, len = 0;
        TreeNode *root = new TreeNode(pre_arr[l1]);
        for(int i = r2; i >= l2; i--) {
            if(in_arr[i] == pre_arr[l1]) {
                k = i; break; // 根断点
            }
        }
        if(k == -1) return nullptr; // 非法情况
        len = k - l2; // 左半区长度
        root->left = build(pre_arr, in_arr, l1+1, l1+len, l2, k-1);
        root->right = build(pre_arr, in_arr, l1+len+1, r1, k+1, r2);
        return root;
    }
};

/*
[3,9,20,15,7]
[9,3,15,20,7]

[3,9,20,null,null,15,7]
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
