// https://leetcode.cn/problems/deepest-leaves-sum/
// 题解：层次遍历，一旦层次加深ans重新置零。
class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        if(root == nullptr) return 0;
        int ans = 0, cnt = 1, next_cnt = 0;
        int cur_depth = 1, tot_depth = get_tree_depth(root);
        queue<TreeNode*> que; que.push(root);

        while(!que.empty()) {
            TreeNode *node = que.front();
            que.pop(); cnt--;

            if(node->left) {
                que.push(node->left); next_cnt++;
            }
            if(node->right) {
                que.push(node->right); next_cnt++;
            }

            if(cur_depth == tot_depth) ans += node->val;
            
            if(cnt == 0) {
                cnt = next_cnt; next_cnt = 0; cur_depth++; // update
            }
        }

        return ans;
    }

    int get_tree_depth(TreeNode *root) {
        if(root == nullptr) return 0;
        int left_depth = get_tree_depth(root->left);
        int right_depth = get_tree_depth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};
/*
[1,2,3,4,5,null,6,7,null,null,null,null,8]
[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]

15
19
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
