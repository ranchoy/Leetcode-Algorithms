// https://leetcode.cn/problems/queries-on-number-of-points-inside-a-circle/
// 题解：排序+二分，针对每个圆圈寻找其上界和下界，在上下界中找到在圆圈内的点。注意二分的边界，上界函数upper_bound()返回left，下界函数lower_bound()返回right。
class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int n = points.length, m = queries.length;
        int[] ans = new int[m];

        Arrays.sort(points, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[0] == b[0]) return a[1] - b[1]; // x相同，y升序
                return a[0] - b[0]; // x升序
            }
        });

        for(int i = 0; i < m; i++) {
            int a = queries[i][0], b = queries[i][1], c = queries[i][2];
            int left = Math.max(upper_bound(points, a - c), 0); // 圆的左边界节点下标
            int right = Math.min(lower_bound(points, a + c), n - 1); // 圆的右边界节点下标

            for(int j = left; j <= right; j++) {
                int x = points[j][0], y = points[j][1];
                if((x - a) * (x - a) + (y - b) * (y - b) <= c * c) {
                    ans[i]++;
                }
            }
        }

        return ans;
    }

    int upper_bound(int[][] points, int x) {
        /* 寻找圆的左边界节点下标 */
        int left = 0, right = points.length;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(points[mid][0] < x) left = mid + 1; // important!
            else right = mid;
        }
        return left;
    }

    int lower_bound(int[][] points, int x) {
        /* 寻找圆的右边界节点下标 */
        int left = 0, right = points.length;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(points[mid][0] > x) right = mid; // important!
            else left = mid + 1;
        }
        return right;
    }
}

/*
[[1,3],[3,3],[5,3],[2,2]]
[[2,3,1],[4,3,1],[1,1,2]]
[[1,1],[2,2],[3,3],[4,4],[5,5]]
[[1,2,2],[2,2,2],[4,3,2],[4,3,3]]

[3,2,2]
[2,3,2,4]
*/