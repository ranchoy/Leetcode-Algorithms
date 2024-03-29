import java.util.*;
// https://leetcode.cn/problems/maximum-average-pass-ratio/
// 题解：优先队列，班级i比班级j更优先的条件是(a0+1)/(a1+1) - a0/a1 > (b0+1)/(b1+1) - b0/b1，注意结果要避免精度丢失。
class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        double ans = 0;
        int n = classes.length;
        PriorityQueue<int[]> pri_que = new PriorityQueue<>((a, b) -> {
            // long x = (long) b[1] * (b[1] + 1) * (a[1] - a[0]); // (long) important!!!
            // long y = (long) a[1] * (a[1] + 1) * (b[1] - b[0]);
            double x = 1.0 * (a[0] + 1) / (a[1] + 1) - 1.0 * a[0] / a[1];
            double y = 1.0 * (b[0] + 1) / (b[1] + 1) - 1.0 * b[0] / b[1];
            if(x == y) return 0;
            return (x < y) ? 1 : -1;
        });

        for(var item : classes) pri_que.offer(item); // insert
        for(int i = 0; i < extraStudents; i++) {
            int[] t = pri_que.poll();
            pri_que.offer(new int[]{t[0] + 1, t[1] + 1});
        }

        while(!pri_que.isEmpty()) {
            int[] t = pri_que.poll();
            ans += 1.0 * t[0] / t[1];
        }

        return ans / n;
    }
}

/*
[[1,2],[3,5],[2,2]]
2
[[2,4],[3,9],[4,5],[2,10]]
4
[[511,910],[289,691],[4,279],[87,843],[415,788]]
61437

0.78333
0.53485
0.96707
*/