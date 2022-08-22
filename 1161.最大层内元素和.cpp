// https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/
// 题解：二叉树层次遍历，利用队列实现，计算每层节点的和值，返回和值最大层的序号。
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;

        int level = 1, cur_sum = 0;
        int cur_cnt = 1, next_cnt = 0;
        int max_val = INT_MIN, max_level = 0;
        TreeNode *node = nullptr;
        queue<TreeNode*> que; que.push(root);

        while(!que.empty() || cur_sum != 0) { // important
            if(cur_cnt > 0) {
                node = que.front(); que.pop();
                cur_sum += node->val; cur_cnt--;

                if(node->left) {
                    que.push(node->left); next_cnt++;
                }
                if(node->right) {
                    que.push(node->right); next_cnt++;
                }
            } else {
                if(max_val < cur_sum) {
                    max_val = cur_sum; max_level = level; // update
                }
                cur_sum = 0; cur_cnt = next_cnt; next_cnt = 0; // reset
                level++;
            }
        }

        return max_level;
    }
};

/*
[-100,-200,-300,-20,-5,-10,null]

3
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
