// https://leetcode-cn.com/problems/bLyHh0/
// https://leetcode-cn.com/problems/number-of-provinces/
// 并查集，如果当前节点x等于parent[x]，则它为父节点，最后统计父节点个数。
// 并查集注意要进行路径压缩，使得父子节点的路径长度降低。
class Solution {
public:
    int findCircleNum(vector<vector<int>> &map) {
        int res = 0;
        int n = map.size();
        vector<int> parent(n,0);
        for(int i = 0; i < n; i++) {
            parent[i] = i; // 父亲节点是当前节点
        }

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(map[i][j] == 1) {
                    union_set(parent, i, j);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(parent[i] == i) res++;
        }
        return res;
    }

    int find(vector<int> &parent, int x) {
        int root = x, temp;
        // 查找root节点
        while(parent[root] != root) {
            root = parent[root];
        }
        // 路径压缩
        while(parent[x] != root) {
            temp = parent[x];
            parent[x] = root;
            x = temp;
        }
        return root;
    }

    void union_set(vector<int> &parent, int a, int b) {
        int x = find(parent, a);
        int y = find(parent, b);
        // 合并
        if(x != y) {
            parent[y] = x;
        }
    }
};

/*
[[1,1,0],[1,1,0],[0,0,1]]
[[1,0,0],[0,1,0],[0,0,1]]

2
3
*/
