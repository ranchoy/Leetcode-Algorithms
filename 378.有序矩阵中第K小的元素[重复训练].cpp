// https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/
// 二分查找，从左下角开始查找，不断更新mid值判断第k小元素在[left,mid]区间还是[mid+1,right]区间
// 注意mid=left+(right-left)/2;
class Solution {
public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int left = mat[0][0];
        int right = mat[n-1][n-1];

        while(left < right) {
            int mid = left + (right - left)/2; // 注意mid>=left，如果别不这么算(-5+-4)/2=-4>-5
            if(is_elem_contant(mat, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool is_elem_contant(vector<vector<int>> &mat, int k, int mid) {
        int n = mat.size();
        int i = n-1, j = 0, elem_num = 0;
        while(i >= 0 && j <= n-1) {
            if(mat[i][j] <= mid) { // 重要
                elem_num += i + 1; // 该列不大于mid元素个数
                j++;
            } else {
                i--;
            }
        }
        return elem_num >= k; // 重要，符号是大于等于，表示目标值在左半区[left,mid]
    }
};

/*
[[-5,-4],[-5,-4]]
3
[[1,5,9],[10,11,13],[12,13,15]]
8

-4
13
*/
