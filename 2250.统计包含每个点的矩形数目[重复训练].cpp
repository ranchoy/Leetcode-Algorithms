// https://leetcode.cn/problems/count-number-of-rectangles-containing-each-point/
// 题解：排序+二分，题目矩形高度有限，按照高度大至小排序，将矩形高度大于等于节点(x,y)的矩形宽度加入x_arr[]，二分查找刚好比x大的x_arr[]元素个数。
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
        int x, y;
        int n = rectangles.size(), m = points.size();
        vector<int> res(m, 0), idx_arr, x_arr;

        // sort desc by height
        sort(rectangles.begin(), rectangles.end(), [&](auto &a, auto &b) {
            return a[1] > b[1];
        });
        for(int i = 0; i < m; i++) idx_arr.push_back(i);
        sort(idx_arr.begin(), idx_arr.end(), [&](int a, int b) {
            return points[a][1] > points[b][1];
        });

        for(int i = 0, k = 0, flag; i < m; i++) {
            flag = k;
            x = points[idx_arr[i]][0];
            y = points[idx_arr[i]][1];

            while(k < n && rectangles[k][1] >= y){
                x_arr.push_back(rectangles[k++][0]); // insert x-axis value
            }
            if(flag != k) sort(x_arr.begin(), x_arr.end());
            res[idx_arr[i]] = x_arr.end() - lower_bound(x_arr.begin(), x_arr.end(), x); // binary search
        }

        return res;
    }
};

/*
[[1,1],[2,2],[3,3]]
[[1,3],[1,1]]
[[7,1],[2,6],[1,4],[5,2],[10,3],[2,4],[5,9]]
[[10,3],[8,10],[2,3],[5,4],[8,5],[7,10],[6,6],[3,6]]

[1,3]
[1,0,4,1,0,0,0,1]
*/
