class Solution {
public:
    struct Node {
        int x, y;
        Node(int a, int b): x(a), y(b) {}
    };
    
    int dir[2][2] = {{0,1}, {1,0}}; // ֻ�����»�������

    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        if(grid.size()==1 && grid[0].size()==1) return grid[0][0];

        return SPFA(grid);
    }

    int SPFA(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int dis[n][m];
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x7f, sizeof(dis));

        Node *s = new Node(0, 0); // ��Դ��s�������
        queue<Node*> qlist;
        qlist.push(s);
        vis[0][0] = 1;
        dis[0][0] = grid[0][0];

        while(!qlist.empty()) {
            Node *temp = qlist.front();
            qlist.pop();
            int x = temp->x;
            int y = temp->y;
            vis[x][y] = 0; // ������

            for(int i=0; i<2; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                Node *next_node = new Node(nx, ny);

                if(!is_ok(next_node, n, m)) // Խ�磬����
                    continue;

                if(dis[nx][ny] > dis[x][y] + grid[nx][ny]) {
                    dis[nx][ny] = dis[x][y] + grid[nx][ny];

                    if(vis[nx][ny] == 0) {
                        vis[nx][ny] = 1;
                        qlist.push(next_node); // �����
                    }
                    // SPFA������������ͳ�ƽڵ�next_node����д������������n����ڸ������˳�
                }
            }
        }
        return dis[n-1][m-1];
    }

    bool is_ok(Node *p, int n, int m) {
        if(p->x < 0 || p->y < 0 || p->x > n-1 || p->y > m-1) {
            return false;
        }
        return true;
    }
};
