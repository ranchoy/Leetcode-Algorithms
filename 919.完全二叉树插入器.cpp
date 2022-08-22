// https://leetcode.cn/problems/complete-binary-tree-inserter/
// 题解：保存可行的节点，优先选择左子树，再选择右子树。
class CBTInserter {
private:
    TreeNode *root;
    queue<TreeNode*> f_que; // incomplete node
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> t_que;
        
        t_que.push(root);
        while(!t_que.empty()) {
            TreeNode *node = t_que.front();
            t_que.pop();
            if(node->left) t_que.push(node->left);
            if(node->right) t_que.push(node->right);
            if(!(node->left && node->right)) f_que.push(node);
        }
    }
    
    int insert(int val) {
        TreeNode *node = new TreeNode(val);
        TreeNode *temp = f_que.front();

        if(temp->left == nullptr) {
            temp->left = node;
        } else {
            temp->right = node;
            f_que.pop();
        }
        f_que.push(node);
        return temp->val;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/*
["CBTInserter","insert","get_root"]
[[[1]],[2],[]]
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]

[null,1,[1,2]]
[null, 1, 2, [1, 2, 3, 4]]
*/

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
