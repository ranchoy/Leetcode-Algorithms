// https://leetcode.cn/problems/maximum-swap/
// 题解：贪心，记录num中最大元素下标，再与高位小的元素互换，注意总交换一次。
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int len = s.size();
        int max_idx = len - 1, idx1 = -1, idx2 = -1; 

        for(int i = len-1; i >= 0; i--) {
            if(s[i] > s[max_idx]) {
                max_idx = i;
            } else if(s[i] < s[max_idx]) {
                idx1 = i; idx2 = max_idx;
            }
        }

        if(idx1 >= 0) {
            swap(s[idx1], s[idx2]);
            return stoi(s);
        }

        return num;
    }
};

/*
2736
9973

7236
9973
*/
