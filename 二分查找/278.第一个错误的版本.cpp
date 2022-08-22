// https://leetcode-cn.com/problems/first-bad-version/
// 二分查找，注意left与right的更新分别是mid+1与mid-1，这样可以避免死循环。
class Solution {
public:
    int firstBadVersion(int n) {
        int mid, left = 1, right = n;

        while(left <= right) {
            mid = left + ((right - left)>>1);
            if(isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

/*
1
1
5
4

1
4
*/
