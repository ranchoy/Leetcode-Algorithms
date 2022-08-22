// https://leetcode-cn.com/problems/bLyHh0/
// ���鼯���ʺϼ��Ϻϲ�����
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // ���鼯�������ڵ㣬��������ͳ��parent�ڵ����
        int n = isConnected.size();
        int *parent = new int[210];
        // ���鼯��ʼ��
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
            st.insert(find(i, parent)); // �����ڵ���뼯��
        }
        return st.size();
    }

    int find(int x, int *parent) {
        if(x == parent[x]) {
            return x;
        }
        int temp;
        int root = find(parent[x], parent); // �ݹ��ҵ����ڵ�
        while(x != parent[x]) { // ���ٲ���
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
