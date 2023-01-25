// https://leetcode.cn/problems/count-number-of-rectangles-containing-each-point/
// 题解：排序+二分，数据中矩形高度有限，按照高度分类矩形和从小到大排序成x_arr[]。然后，从点i的高度points[i][1]开始遍历找到能包含的矩形并累加。
class Solution {
    public int[] countRectangles(int[][] rectangles, int[][] points) {
        List<Integer>[] x_arr = new List[101];
        Arrays.setAll(x_arr, e -> new ArrayList<>());
        int n = rectangles.length, m = points.length;
        int[] ans = new int[m];

        for(int[] r : rectangles) x_arr[r[1]].add(r[0]); // 按照坐标y存储坐标x
        for(var x : x_arr) Collections.sort(x); // 坐标x由小到大排序

        for(int i = 0; i < m; i++) {
            for(int j = points[i][1]; j <= 100; j++) {
                ans[i] += x_arr[j].size() - lower_bound(x_arr[j], points[i][0]);
            }
        }

        return ans;
    }

    int lower_bound(List<Integer> nums, int k) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums.get(mid) >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
}

/*
[[1,2],[2,3],[2,5]]
[[2,1],[1,4]]
[[1,1],[2,2],[3,3]]
[[1,3],[1,1]]

[2,1]
[1,3]
*/