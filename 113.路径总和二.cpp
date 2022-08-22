// https://leetcode-cn.com/problems/path-sum-ii/submissions/
// DFS������ȱ�����ע��DFS�Ļ��ݣ���������޽�ʱ���ݣ�������ִ���Ұ�����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return res; // ��Ҫ
        vector<int> temp;
        temp.push_back(root->val);
        dfs_path_search(root, temp, root->val, targetSum);
        return res;
    }

    void dfs_path_search(TreeNode *root, vector<int> &temp, int cur_sum, int target) {
        if(root == nullptr) return;
        TreeNode *p_l = root->left, *p_r = root->right;
        if(cur_sum == target && p_l == nullptr && p_r == nullptr) {
            res.push_back(temp); return;
        }

        if(p_l) {
            cur_sum += p_l->val; // ��Ҫ
            temp.push_back(p_l->val);
            dfs_path_search(p_l, temp, cur_sum, target);
            cur_sum -= p_l->val;
            temp.pop_back();
        }

        if(p_r) {
            cur_sum += p_r->val; // ��Ҫ
            temp.push_back(p_r->val);
            dfs_path_search(p_r, temp, cur_sum, target);
            cur_sum -= p_r->val;
            temp.pop_back();
        }
    }
};

/*
[],1
[]
[5,4,8,11,null,13,4,7,2,null,null,5,1],22
[[5,4,11,2],[5,8,4,5]]
*/
