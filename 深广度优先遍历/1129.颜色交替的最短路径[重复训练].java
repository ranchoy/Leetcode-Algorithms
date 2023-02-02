// https://leetcode.cn/problems/shortest-path-with-alternating-colors/
// 题解：广度优先遍历BFS，next[color=0|1][i]=ArrayList<>()记录各红蓝边，dist[2][n]记录节点0到各点的最短距离，注意路径必须是红蓝色边交替构成。
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        int[] ans = new int[n];
        int[][] dist = new int[2][n]; // dist[0][i]表示红色边结束的(0-->i)的最短距离。
        List<Integer>[][] next = new List[2][n]; // next[0][i]={j,k,l}表示红色边(i->j)、(i->k)和(i->l)存在。
        Queue<int[]> que = new ArrayDeque<>();

        dist[0][0] = dist[1][0] = 0; // important!
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) next[i][j] = new ArrayList<Integer>(); // init
            for(int j = 1; j < n; j++) dist[i][j] = Integer.MAX_VALUE;
        }
        for(int[] edge : redEdges) next[0][edge[0]].add(edge[1]);
        for(int[] edge : blueEdges) next[1][edge[0]].add(edge[1]);
        que.add(new int[]{0,0}); que.add(new int[]{0,1}); // [i,0|1]，连节点0的颜色为红0或蓝1。

        while(!que.isEmpty()) {
            int[] temp = que.poll();
            int x = temp[0], color = temp[1];

            for(int y : next[1 - color][x]) { // x->y
                if(dist[1 - color][y] != Integer.MAX_VALUE) {
                    continue; // 已经存在更短的距离(x->y)，跳过。
                }

                dist[1 - color][y] = dist[color][x] + 1; // 距离累加dist(0-->x)+1。
                que.offer(new int[]{y, 1 - color}); // 插入新节点y，边(x->y)颜色为(1-color)。
            }
        }

        for(int i = 0; i < n; i++) {
            ans[i] = Math.min(dist[0][i], dist[1][i]); // 取最后为红或蓝色边dist最小的结果。
            if(ans[i] == Integer.MAX_VALUE) ans[i] = -1;
        }

        return ans;
    }
}

/*
3
[[0,1],[1,2]]
[]
3
[[0,1]]
[[1,2]]

[0,1,-1]
[0,1,2]
*/