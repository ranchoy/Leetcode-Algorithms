// https://leetcode-cn.com/problems/sqrtx/
// 二分查找，注意避免int越界，使用long long int类型。
class Solution {
public:
    int mySqrt(int x) {
        int mid_max = 1<<16;
        long long mid_pow = 0;
        int mid, left = 1, right = x;

        while(left < right) {
            mid = left + ((right - left)>>1);
            if(mid > mid_max) { // 避免越界
                right = mid_max; continue;
            }

            mid_pow = (long long int)mid * mid;
            if(mid_pow == x) {
                return mid;
            } else if (mid_pow > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        mid_pow = (long long int)left * left;
        return (mid_pow > x) ? left-1 : left; // (2.8)^2 < 8 < 3^2
    }
};

/*
4
8

2
2
*/
