// https://leetcode-cn.com/problems/construct-quad-tree/
// DFS深度优先搜索，注意四部分是否全叶子，或者四部分值是否全相等。
class Solution {
public:
    Node* construct(vector<vector<int>> &grid) {
        int n = grid.size();
        Node *res = dfs(grid, 0, n-1, 0, n-1);
        return res;
    }

    Node *dfs(vector<vector<int>> &grid, int i_low, int i_high, int j_low, int j_high) {
        Node *cur_node = new Node();

        if(i_low == i_high && j_low == j_high) {
            cur_node->isLeaf = true;
            cur_node->val = (grid[i_low][j_low] == 1) ? true : false;
            cur_node->topLeft = cur_node->topRight = nullptr;
            cur_node->bottomLeft = cur_node->bottomRight = nullptr;
        } else {
            int i_mid = i_low + (i_high - i_low)/2;
            int j_mid = j_low + (j_high - j_low)/2;
            cur_node->topLeft = dfs(grid, i_low, i_mid, j_low, j_mid); // 上左
            cur_node->topRight = dfs(grid, i_low, i_mid, j_mid+1, j_high); // 上右
            cur_node->bottomLeft = dfs(grid, i_mid+1, i_high, j_low, j_mid); // 下左
            cur_node->bottomRight = dfs(grid, i_mid+1, i_high, j_mid+1, j_high); // 下右
            update_node_elem(cur_node);
        }

        return cur_node;
    }

    bool is_all_leaf(Node *cur_node) {
        bool p1_isleaf, p2_isleaf, p3_isleaf, p4_isleaf;
        p1_isleaf = cur_node->topLeft->isLeaf;
        p2_isleaf = cur_node->topRight->isLeaf;
        p3_isleaf = cur_node->bottomLeft->isLeaf;
        p4_isleaf = cur_node->bottomRight->isLeaf;
        // 重要，判断四部分是否全是叶子节点。
        return p1_isleaf & (p1_isleaf == p2_isleaf) & (p1_isleaf == p3_isleaf) & (p1_isleaf == p4_isleaf);
    }

    bool compare_part_val(Node *cur_node) {
        bool p1_val, p2_val, p3_val, p4_val;
        p1_val = cur_node->topLeft->val;
        p2_val = cur_node->topRight->val;
        p3_val = cur_node->bottomLeft->val;
        p4_val = cur_node->bottomRight->val;
        return (p1_val == p2_val) & (p1_val == p3_val) & (p1_val == p4_val);
    }

    void update_node_elem(Node *cur_node) {
        bool is_leaf = is_all_leaf(cur_node);
        bool is_equal_val = compare_part_val(cur_node);

        if(is_leaf == true && is_equal_val == true) {
            cur_node->isLeaf = true;
            cur_node->val = cur_node->topLeft->val;
            cur_node->topLeft = cur_node->topRight = nullptr;
            cur_node->bottomLeft = cur_node->bottomRight = nullptr;
        } else {
            cur_node->val = true;
            cur_node->isLeaf = false;
        }
    }
};

/*
[[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
[[1,1,0,0],[0,0,1,1],[1,1,0,0],[0,0,1,1]]

[[0,1],[1,1],[1,0],[1,0],[1,1]]
[[0,1],[0,1],[0,1],[0,1],[0,1],[1,1],[1,1],[1,0],[1,0],[1,0],[1,0],[1,1],[1,1],[1,1],[1,1],[1,0],[1,0],[1,0],[1,0],[1,1],[1,1]]
*/
