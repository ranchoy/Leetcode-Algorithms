// https://leetcode-cn.com/problems/guess-number-higher-or-lower/
// 二分查找
class Solution {
public:
    int guessNumber(int n) {
        return get_val(1, n);
    }

    int get_val(int left, int right) {
        if(left > right) return -1;
        int mid = left + ((right - left) >> 1);
        int flag = guess(mid);
        if(flag == 0) {
            return mid;
        } else if(flag == -1) {
            return get_val(left, mid-1);
        }
        return get_val(mid+1, right);
    }
};

/*
10
6

6
*/
