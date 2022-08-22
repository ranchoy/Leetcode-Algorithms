// https://leetcode-cn.com/problems/valid-perfect-square/submissions/
// 二分查找，注意不要int溢出。
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long mid_pow;
        int mid, mid_mx = 1<<16;
        int left = 1, right = num;

        while(left <= right) {
            mid = left + ((right - left)>>1);
            if(mid > mid_mx) {
                right = mid_mx; continue;
            }
            mid_pow = (long long)mid * mid;
            if(mid_pow == num) {
                return true;
            } else if(mid_pow < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

/*
2000105819
2147395600

false
true
*/
