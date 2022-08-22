// https://leetcode-cn.com/problems/binary-gap/
// 模拟题，记录相邻bit=1位置即可，注意初始位置left的取值。
class Solution {
public:
    int binaryGap(int n) {
        int k = 0, mx_len = 0;
        int left = (n&1) ? 0 : -1;

        while(n > 0) {
            k++;
            n = n >> 1;
            
            if(n & 1 == 1) {
                if(left == -1) {
                    left = k; continue;
                }
                mx_len = max(mx_len, k - left);
                left = k;
            }
        }

        return mx_len;
    }
};

/*
1
5
8
22

0
2
0
22
*/
