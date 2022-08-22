// https://leetcode-cn.com/problems/bLyHh0/
// 并查集，适合集合合并操作
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // 并查集，关联节点，最后遍历，统计parent节点个数
        int n = isConnected.size();
        int *parent = new int[210];
        // 并查集初始化
        for(int i=1; i<=n; i++)
            parent[i] = i;

        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                if(isConnected[i-1][j-1] == 1) {
                    union_node(i, j, parent);
                }
            }
        }

        unordered_set<int> st;
        for(int i=1; i<=n; i++) {
            st.insert(find(i, parent)); // 将根节点插入集合
        }
        return st.size();
    }

    int find(int x, int *parent) {
        if(x == parent[x]) {
            return x;
        }
        int temp;
        int root = find(parent[x], parent); // 递归找到根节点
        while(x != parent[x]) { // 减少层数
            temp = parent[x];
            parent[x] = root;
            x = temp;
        }
        return root;
    }

    void union_node(int a, int b, int *parent) {
        int root_a = find(a, parent);
        int root_b = find(b, parent);

        if(root_a != root_b) {
            parent[root_b] = root_a;
        }
    }
};
