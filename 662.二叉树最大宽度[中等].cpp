// https://leetcode.cn/problems/maximum-width-of-binary-tree/
// 题解：BFS或DFS搜索，记录每层最左非空节点的idx，记录每层最大差值，注意索引可能越界。
// DFS深度优先搜索
using ULL = unsigned long long;
class Solution {
public:
    ULL ans = 0, sub = 0;
    int widthOfBinaryTree(TreeNode *root) {
        vector<ULL> left_nodes;

        dfs(root, left_nodes, 1, 1);
        return ans;
    }

    void dfs(TreeNode *root, vector<ULL> &nums, int level, ULL node_idx) {
        if(root == nullptr) return;
        if(level > nums.size()) nums.push_back(node_idx); // record left nodes index.
        ans = max(ans, node_idx - nums[level-1] + 1);
        
        if(root->left) dfs(root->left, nums, level+1, node_idx*2);
        if(root->right) dfs(root->right, nums, level+1, node_idx*2+1);
    }
};

/*
[2,1,3,null,4]
[1,1,1,1,1,1,1,null,null,null,1,null,null,null,null,2,2,2,2,2,2,2,null,2,null,null,2,null,2]

2
8
*/

// BFS广度优先搜索
using ULL = unsigned long long;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ULL ans = 0, node_idx, level_min_idx;
        int level = 1, cur_cnt = 0, next_cnt = 1;
        TreeNode *node = nullptr;
        queue<pair<TreeNode*, ULL>> que; // Index of nodes.
        que.push(make_pair(root, 1));

        while(!que.empty()) {
            pair<TreeNode*, ULL> tmp = que.front(); que.pop();
            node = tmp.first; node_idx = tmp.second; cur_cnt++;
            if(cur_cnt == 1) level_min_idx = node_idx;
            
            if(node->left) {
                que.push(make_pair(node->left, node_idx*2));
            }
            if(node->right) {
                que.push(make_pair(node->right, node_idx*2+1));
            }

            if(cur_cnt == next_cnt) {
                ans = max(ans, node_idx - level_min_idx + 1);
                cur_cnt = 0; next_cnt = que.size(); level++; // update
            }
        }

        return ans;
    }
};

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
