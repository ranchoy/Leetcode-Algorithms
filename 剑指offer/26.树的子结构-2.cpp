// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
// 先序遍历+二叉树深度，二叉树深度过滤不合理样例，再先序遍历逐个找根节点入口。
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        int a = tree_depth(A), b = tree_depth(B);
        if(a < b) return false;
        if(A == nullptr || B == nullptr) return false; //过滤空树

        stack<TreeNode*> stk; stk.push(A);
        while(!stk.empty()) {
            TreeNode *node = stk.top(); stk.pop();

            if(node->val == B->val) {
                bool flag = tree_comp(node, B);
                if(flag == true) return true; // 发现则结束
            }
            if(node->right != nullptr) stk.push(node->right);
            if(node->left != nullptr) stk.push(node->left);
        }
        return false;
    }

    int tree_depth(TreeNode *root) {
        if(root == nullptr) return 0;
        int left = tree_depth(root->left);
        int right = tree_depth(root->right);
        return max(left,right)+1;
    }

    bool tree_comp(TreeNode *r1, TreeNode *r2) {
        if(r1 == nullptr && r2 == nullptr) return true;
        if(r1 != nullptr && r2 == nullptr) return true;
        if(r1 == nullptr && r2 != nullptr) return false;
        if(r1->val != r2->val) return false;

        bool flag_left = tree_comp(r1->left, r2->left);
        bool flag_right = tree_comp(r1->right, r2->right);
        return (flag_left & flag_right);
    }
};

/*
[2,2]
[3,2,1,2]
[-1,3,2,0]
[]
[1,0,1,-4,-3]
[1,-4]
[10,12,6,8,3,11]
[10,12,6,8]

false
false
false
true
*/
