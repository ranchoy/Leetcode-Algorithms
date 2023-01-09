// https://leetcode.cn/problems/find-if-path-exists-in-graph/
// 题解：并查集 or 深搜DFS or 广搜BFS，注意并查集的路径压缩和集合合并方法，以及DFS的vis标记不需要返回上一层，先找到的就是最短的路径。
class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        vector<int> parent(n, 0);

        for(int i = 0; i < n; i++) parent[i] = i;
        for(auto edge : edges) {
            int i = edge[0], j = edge[1];
            union_node(parent, i, j);
        }

        int a = find(parent, source);
        int b = find(parent, destination);
        return a == b ? true : false;
    }

    int find(vector<int> &parent, int node) {
        if(parent[node] == node) return node; // parent[i]表示节点i的父节点, 默认为i。
        int temp, root = node;

        while(root != parent[root]) {
            root = parent[root]; // find root node.
        }
        while(root != parent[node]) {
            temp = parent[node];
            parent[node] = root; // path compression optimization.
            node = temp;
        }

        return root;
    }

    void union_node(vector<int> &parent, int i, int j) {
        int a = find(parent, i), b = find(parent, j);
        if(a == b) return;
        if(a < b) {
            parent[b] = a; // union set, small value as root node.
        } else {
            parent[a] = b;
        }
    }

    bool validPath2(int n, vector<vector<int>> &edges, int source, int destination) {
        bool flag = false;
        int m = edges.size();
        vector<int> vis(n, 0);
        vector<vector<int>> elist(n);
        for(auto edge : edges) {
            int i = edge[0], j = edge[1];
            elist[i].push_back(j); elist[j].push_back(i);
        }

        DFS(elist, vis, flag, source, destination);
        return flag;
    }

    void DFS(vector<vector<int>> &elist, vector<int> &vis, bool &flag, int source, int destination) {
        if(source == destination) flag = true;
        if(vis[source] == 1 || flag == true) return;
        vector<int> &nums = elist[source];

        vis[source] = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(vis[ nums[i] ] == 1) continue;
            DFS(elist, vis, flag, nums[i], destination);
            // vis[ nums[i] ] = 0; // 必能首先访问到，无需此举！
        }
    }
};

/*
3
[[0,1],[1,2],[2,0]]
0
2
6
[[0,1],[0,2],[3,5],[5,4],[4,3]]
0
5

true
false
*/
